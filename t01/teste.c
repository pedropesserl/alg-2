#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordenacao.h"

int *le_vetor(int tam) {
	int *v;
	if ( !(v = malloc(50010 * sizeof(int))) ) return NULL;
	int n;
	for (int i = 0; i < tam; i++) {
 		scanf("%d", &n);
		v[i] = n;
	}
	return v;
}

void imprime_vetor(int *v, int tam) {
	for (int i = 0; i < tam; i++)
		printf("%d ", v[i]);
	printf("\n");
}

int main() {
	int *vetor;
	int tam;
	printf("tamanho do vetor: ");
	scanf("%d", &tam);
	if ( !(vetor = malloc(tam * sizeof(int))) ) return 1;
	vetor = le_vetor(tam);

	int numComparacoes = heapSort(vetor, tam);

	imprime_vetor(vetor, tam);
	printf("numero de comparacoes: %d\n", numComparacoes);

	return 0;
}
