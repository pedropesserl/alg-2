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
	// TESTE: INTERCALA RECURSIVO
	/* int *vetor, *novo; */
	/* int tam = 10; */

	/* if ( !(novo = malloc(100 * sizeof(int))) ) return 1; */

	/* vetor = le_vetor(tam); */	

	/* int meio = (tam - 1 + 0) / 2; */

	/* int numComparacoes = intercala(vetor, meio + 1, vetor + meio + 1, tam - 1 - meio, novo); */
	/* imprime_vetor(vetor, tam); */
	/* printf("numero de comparacoes: %d\n", numComparacoes); */
	
	/* free(vetor); free(novo); */
	/* return 0; */

	// TESTE: INTERCALA WRAPPER
	/* int *vetor, *novo; */
	/* int tam = 20; */
	/* vetor = le_vetor(tam); */

	/* if ( !(novo = malloc(100 * sizeof(int))) ) return 1; */

	/* int numComparacoes = intercalaWrapper(vetor, 0, 14, 19, novo); */
	/* imprime_vetor(vetor, tam); */
	/* printf("numero de comparacoes: %d\n", numComparacoes); */
	
	/* free(vetor); */
	/* return 0; */

	// TESTE: MERGESORT
	int *vetor;
	int tam;
	scanf("%d", &tam);

	vetor = le_vetor(tam);

	int numComparacoes = mergeSort(vetor, tam);
	imprime_vetor(vetor, tam);
	printf("numero de comparacoes: %d\n", numComparacoes);
	
	free(vetor);
	return 0;
}
