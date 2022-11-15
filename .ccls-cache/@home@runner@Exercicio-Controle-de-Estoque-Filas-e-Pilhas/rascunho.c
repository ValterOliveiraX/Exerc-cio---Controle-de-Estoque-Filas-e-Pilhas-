#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 4

/* Estrutura para os pacotes enviados */
typedef struct {
	        char nome[10];
	        int numero_pacote;
	 } elemento;

int cont=0;

/* DECLARACOES GLOBAIS DE CONSTANTES */
const elemento VL_NULO = {0, 0};

/* Arquivo que contem as rotinas de implementação da fila */
#include "tad_fila1b.h"

/* protótipos */
void limpar_tela();
void delay(long n);
void montar_tela();
int sorteia();
elemento criaPacote();
int colocaNovoNaFila(tipo_fila *fila);
int enviaParaProcessador(tipo_fila *fila, tipo_fila *fila_processador);
int retiraDoProcessador(tipo_fila *fila_processador);
void efetua_processamento(tipo_fila fila[MAX]);

void limpar_tela() {
   system("clear");
   printf("SIMULACAO DO ENVIO DE PACOTES EM UMA REDE DO TIPO\n");
   printf("CLIENTE/SERVIDOR UTILIZANDO A ESTRUTURA DE DADOS FILA\n\n\n");
}

void delay(long n) {
	int i, j;
	for (i=0;i<n;i++)
           for (j=0;j<n;j++);
}
	
/* Atualiza a tela com os valores dos processos */
void montar_tela(tipo_fila fila[MAX]) {
   int i,j,t; 
   elemento ele;
   limpar_tela();
   for (j=0; j<=3; j++) {
      if (j<=2)
          printf("\n\nCLIENTE %d:\n\n  ", j+1);
      else
          printf("\n\n\nSERVIDOR (processando)... :\n\n  ");

      if ((t=tamanho(fila[j])) > 0) {
         for (i=1; i<=t; i++) {
            primeiroFila(fila[j], &ele);
            printf("|%s - %d|  ", ele.nome, ele.numero_pacote);
            sairElemento(&fila[j], &ele);
            entrarElemento(&fila[j], ele);
         }
      }
      else
         printf("|  vazia  |");
   }
   printf("\n\n...............................................");
   delay(10000);
  getchar();
}

/* Retorna um cliente randomico para envio de pacotes */
int sorteia(){
        srand(time(NULL));
	return (random()%10);
}

elemento criaPacote() {
   elemento e;
   strcpy(e.nome, "pkt");
   e.numero_pacote = ++cont;
   return e;
}

int colocaNovoNaFila(tipo_fila *fila) {
   elemento e;
   if (!filaCheia(*fila)) {
       entrarElemento(fila, e=criaPacote());
   }
}

int enviaParaProcessador(tipo_fila *fila, tipo_fila *fila_processador) {
   elemento e;
   if (!filaVazia(*fila)) {
      sairElemento(fila,&e);
      if (!filaCheia(*fila_processador))
         entrarElemento(fila_processador, e);
    }
}

int retiraDoProcessador(tipo_fila *fila_processador) {
   elemento e;
   if (!filaVazia(*fila_processador))
      sairElemento(fila_processador, &e);
}

/* Efetua o envio de pacotes ao servidor */
void efetua_processamento(tipo_fila fila[MAX]){
   int s;
   elemento e;
   while(1) {
       limpar_tela();
       s = sorteia();
       if (s >=0 && s <=2) 
          colocaNovoNaFila(&fila[s]);
       else 
          if (s >=3 && s <=5) 
             enviaParaProcessador(&fila[s-3], &fila[MAX-1]);
          else 
             if (s >=6 && s <=10)       
                retiraDoProcessador(&fila[MAX-1]);
       montar_tela(fila);
   }
}

/* Funcao principal do programa */
int main() {
   int i;
   tipo_fila fila[MAX];
   for (i=0; i<=MAX-1; i++)
      criarFila(&fila[i]);
   efetua_processamento(fila);
}