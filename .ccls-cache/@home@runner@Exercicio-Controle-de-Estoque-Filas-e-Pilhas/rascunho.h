#include <stdio.h>
#include <stdlib.h>
typedef struct {
long int codigo;
char nome[40];
} cliente;
typedef cliente elemento;
const elemento VL_NULO = {0, ""};
#include "tad_fila1.c"
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
1) Utilização

© Prof. Gentil Cutrim Serra Júnior

20
2)