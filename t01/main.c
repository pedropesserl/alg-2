#include <stdio.h>
#include <stdlib.h>
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
	if ( !(vetor = malloc(65010 * sizeof(int))) ) return 1;
	int tam = 65000;
	for (int i = 0; i < tam; i++) {
		vetor[i] = 65000 - i;
	}

	int numComparacoes = insertionSort(vetor, tam);

	/* printf("vetor ordenado: \n"); */
	/* imprime_vetor(vetor, tam); */
	printf("numero de comparacoes: %d\n", numComparacoes);
	
	free(vetor);
	return 0;
}
