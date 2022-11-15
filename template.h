#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// facilitadores de função
//return 0 = retorna falso ou erro
//return 1 = retorna verdadeiro ou sucesso.
void limpatela() { system("cls || clear"); }
void pausa() {
  printf("\nAperte para continuar.... \n");
  getchar();
}
int sorteio(int i) { return rand() % i; }
char escolhe_opcao() { return getchar(); }
void limpar() { fflush(stdin); }


/*
Elementos só podem ser inseridos no fim da fila.
 Elementos só podem ser retirados no início da
fila.

Primeiro a Entrar, Primeiro a Sair  FIFO: first in,
first out
//-------------------------------------

 entrarElemento(&f,e)
 primeiroFila(f,&e)
 sairElemento(&f,&e)


#include <stdio.h>
#include <stdlib.h>
typedef struct {
long int codigo;
char nome[40];
} cliente;
typedef cliente elemento;
const elemento VL_NULO = {0, ""};
#include "tad_fila2.c"
tipo_fila f;
elemento elem;
int i;
char op;
limpa_tela() {
system("clear");
}

void listar() {
int i, tam;
elemento elem;
limpa_tela();
tam = tamanho(f);
if (tam > 0) {
for (i=1; i<=tam; i++) {
if (sairElemento(&f,&elem)) {
printf("%d - %d - %s\n", i , elem.codigo, elem.nome);
entrarElemento(&f,elem);
}
}
fflush(stdin);
getchar();getchar();
}
else {
printf("Fila vazia\n");
printf("<tecle ENTER para continuar>");
fflush(stdin);
getchar();getchar();
}
}
void incluir() {
int posicao;
elemento elem;
limpa_tela();
printf("Codigo: ");
scanf("%d", &elem.codigo);
printf("Nome do Cliente: ");
fflush(stdin);
scanf("%s", &elem.nome);
printf("------------------------------------------------\n");
fflush(stdin);
if (entrarElemento(&f,elem))
printf("Elemento incluído com sucesso!");
else
printf("Lista Cheia");
fflush(stdin);
getchar();getchar();
}
void monta_tela() {
printf("\n0 - listar");
printf("\n1 - incluir");
printf("\n2 - excluir");
printf("\n9 - sair\n");
}
char escolhe_opcao() {
return getchar();
}
void main() {
char opcao;
criarFila(&f);
do {
limpa_tela();
monta_tela();
opcao = escolhe_opcao();
switch (opcao) {
case '0':
listar();
break;
case '1':
incluir();
break;
case '2':
//excluir();
break;
case '9':
exit(1);
break;
}
} while (1);
}






#include <stdio>
#include <conio>
typedef int elemento;
#include "tad_pilha2.c"
void binario() {
tipo_pilha p;
int x,n,d;
clrscr();
printf("Digite um inteiro decimal positivo: ");
scanf("%d", &n);
criarPilha(&p);
do {
x = n % 2;
empilharElemento(&p,x);
n = n / 2;
} while (n!=0);
printf("\nO correspondente binario é: ");
while (!pilhaVazia(p)) {
desempilharElemento(&p,&d);
printf("%d",d);

}
fflush(stdin);
getchar();
}
void main() {
char op;
do {
binario();
clrscr();
printf("Deseja mais um numero(s/n)? ");
op = getchar();
} while ((op == 'S') || (op=='s'));
}

void entregar_carro_proprietario(fila *f, int codigo_veiculo) {
elemento e;
int tam = tamanho(*f);
for (int i=0; i<tam; i++) {
printf(“retirar carro da fila”);
sairElemento(&f, &e);
if (e.codigo == codigo_veiculo)
printf(“entregar carro para o proprietário”);
else {
printf(“devolver carro para a fila”);
entrarElemento(&f, e);
}
}
}






3)
*/