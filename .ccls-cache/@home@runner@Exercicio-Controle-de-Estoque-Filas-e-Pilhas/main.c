/***********
+-------------------------------------+
| INSTITUTO FEDERAL DO MARANHÃO       |
| SISTEMAS DE INFORMAÇÃO              |
|ALGORITMOS E ESTRUTUTURAS DE DADOS I |
| Professor Gentil Cutrim             |
| Acadêmico: Valter Oliveira          |
+------------- -----------------------+
O objetivo deste codigo e fazer uma analise
sobre o comportamento de codigos com filas e pilhas

*/
#include "template.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
  int CodigoProduto;
  char Descricao[20];
  int Quantidade;
  char TipoEmbalagem[20];
} produto;
typedef produto elemento;

/* DECLARACOES GLOBAIS DE CONSTANTES */
const elemento VL_NULO = {0, "", 0, ""};
#include "tad_fila.h"
#include "tad_pilha.h"

tipo_lista lista;
pilha p;
/*PROTÓTIPOS DA FUNÇÕES */
void incluir();
void excluir();
void fila();
void pilhaa();
void monta_tela();
int entra_codigo(int *codigo);
int entra_descricao(char *descricao);
int entra_quantidade(int *quantidade);
int entra_tipo_embalagem(int *tipo);
void listar();
/*++++++ MAIN +++++++*/
int main(void) {
  char opcao;
  do {
    limpatela();
    monta_tela();
    opcao = escolhe_opcao();
    switch (opcao) {
    case '0':
      listar();
      pausa();
      pausa();
      break;
    case '1':
      incluir();
      pausa();
      break;
    case '2':
      // alterar();
      break;
    case '3':
      excluir();
      pausa();
      break;
    case '4':
      // gravar();
      break;
    case '5':
      // carregar();
      break;
    case '9':
      exit(1);
      break;
    }
  } while (1);
}

void monta_tela() {
  printf("\n+- SISTEMA GRAVACAO PILHA E FILA -+");
  printf("\n0 - listar");
  printf("\n1 - incluir");
  printf("\n2 - alterar");
  printf("\n3 - excluir");
  printf("\n4 - gravar dados");
  printf("\n5 - carregar dados");
  printf("\n9 - sair\n");
}

/*EXCLUSAO -------------------*/
void excluir() {
  int pos, busc, codigo, i, tam;
  char descricao[20];
  tam = tamanho(lista);
  elemento elem = VL_NULO;
  limpatela();
  /*fila   ---- */
  if (!filaVazia(lista)) {
    listar();
    printf("\nescreva o codigo do produto para a EXCLUSÃO: ->");
    scanf("%d", &codigo);
    for (i = 0; i < tam; i++) {
      // exibindo produtos para exclusao
      primeiroFila(lista, &elem);
      if (sairElemento(&lista, &elem)) {
        if (codigo == elem.CodigoProduto) {
          elem = VL_NULO;//opcional
          break;
        }
        printf("\n-- ÊXITO --\n");
        entrarElemento(&lista, elem);
      } else
        printf("falha ao acessar a fila!!!!!");
    }
  } else
    printf("fila vazia!!!! ");
  /*pilha -------*/
  tipo_pilha aux;
  criarPilha(&aux);
  //colocando de volta na pilha
  while (!pilhaVazia(aux)) {
    desempilharElemento(&p, &elem);
    //busca de elemento para exclusao
    if (codigo == elem.CodigoProduto){
     
    }else
    //reentrada na pilha
    empilharElemento(&aux, elem);
    /*
    desempilhar ate determinado
    empilahr de volta
*/
  }




  
  pausa();
}




        // INCLUIR 
void incluir() {
  int pos;
  elemento elem = VL_NULO;
  limpatela();
  entra_descricao(&elem.Descricao);
  entra_codigo(&elem.CodigoProduto);
  entra_quantidade(&elem.Quantidade);
  entra_tipo_embalagem(&elem.TipoEmbalagem);
  // pos = posicao_para_incluir(tamanho(lista));
  printf("\n");

  if (entrarElemento(&lista, elem)) {
    printf("\nElemento incluído na fila com sucesso!");
    // pausa();
  } else
    printf("falha ao salvar na fila");

  if (empilharElemento(&p, elem)) {
    printf("\nElemento incluído na pilha com sucesso!");
    pausa();
  } else
    printf("falha ao salvar na pilha");
  pausa();
}

void listar() {
  int i, tam;
  elemento elem;
  limpatela();
  printf("FILA:\nCOD.\tDESC.\tQUANT.\tTIPO.\t\n");
  tam = tamanho(lista);
  if (tam > 0) {
    for (i = 1; i <= tam; i++) {
      if (sairElemento(&lista, &elem)) {
        printf("%d\t%s\t%d\t\t%s\n", elem.CodigoProduto, elem.Descricao,
               elem.Quantidade, elem.TipoEmbalagem);
        entrarElemento(&lista, elem);
      }
    }
    fflush(stdin);
    getchar();
    getchar();
  } else {

    printf("FILA VAZIA!!!!! \n");
  }
  // IMPRIMINDO PILHA
  tipo_pilha aux;
  criarPilha(&aux);

  printf("PILHA:\nCOD.\tDESC.\tQUANT.\tTIPO.\t\n");
  if (!pilhaVazia(p)) {
    while (!pilhaVazia(p)) {
      desempilharElemento(&p, &elem);
      empilharElemento(&aux, elem);
    }
    // primeiroFila(lista, &elem);
    while (!pilhaVazia(aux)) {
      desempilharElemento(&aux, &elem);
      printf("%d\t%s\t%d\t\t%s\n", elem.CodigoProduto, elem.Descricao,
             elem.Quantidade, elem.TipoEmbalagem);
      empilharElemento(&p, elem);
    }
  } else {
    printf("PILHA VAZIA!!!!! \n");
  }
}

// entrada de dados
int entra_codigo(int *codigo) {
  printf("\nInsira o codigo do produto: ->");
  fflush(stdin);
  scanf("%d", codigo);
}
int entra_descricao(char *descricao) {
  printf("\nInsira a descrição ->");
  fflush(stdin);
  scanf("%s", descricao);
}
int entra_quantidade(int *quantidade) {
  printf("\nescreva a quantidade de itens");
  fflush(stdin);
  scanf("%d", quantidade);
}
int entra_tipo_embalagem(int *tipo) {
  printf("\nTipo de embalagem ->");
  fflush(stdin);
  scanf("%s", tipo);
}

// esquema de filas e pilhas
/*
FILAS:
LOOP
  SAIR ELEMENTO
    OPERAÇÃO ()
  ENTRAR ELEMENTO
PILHAS:
DESEMPILHAR
EMPILHAR(AUX);

*/
