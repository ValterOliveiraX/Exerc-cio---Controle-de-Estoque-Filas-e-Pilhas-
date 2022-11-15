#include "tad_lst1.h"

typedef tipo_lista tipo_fila;

int entrarElemento(tipo_lista *f, elemento e) {
	return incluir_elemento(f, tamanho(*f)+1, e);
}

int sairElemento(tipo_lista *f, elemento *e) {
	obter_elemento(*f, 1, e);
	return excluir_elemento(f, 1);
}

int criarFila(tipo_lista *f) {
	inicializa_lista(f);
}

int primeiroFila(tipo_lista f, elemento *e)
{
	obter_elemento(f, 1, e);
}

int filaVazia(tipo_lista f) {
	return (tamanho(f) == 0);
}

int filaCheia(tipo_lista f) {
	return (tamanho(f) == MAX);
}