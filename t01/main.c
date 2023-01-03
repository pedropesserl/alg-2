#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"

int *le_vetor(int tam) {
	int *v;
	if ( !(v = malloc(100 * sizeof(int))) ) return NULL;
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
	int tam = 10;
	vetor = le_vetor(tam);

	int numComparacoes = insertionSort(vetor, tam);

	printf("vetor ordenado: \n");
	imprime_vetor(vetor, tam);
	printf("numero de comparacoes: %d\n", numComparacoes);
	free(vetor);
	return 0;
}
