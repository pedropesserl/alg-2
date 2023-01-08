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
	int tam; //indice_pivo;
	printf("tamanho do vetor: ");
	scanf("%d", &tam);
	if ( !(vetor = malloc(tam * sizeof(int))) ) return 1;
	vetor = le_vetor(tam);

	// TESTE: QUICKSORT
	int numComparacoes = quickSort(vetor, tam);

	// TESTE: PARTICIONA
	/* indice_pivo = -1; */
	/* int numComparacoes = particiona(vetor, 0, tam-1, &indice_pivo, 0); */
	/* int numComparacoes = particiona_iterativo(vetor, 0, tam-1, &indice_pivo); */
	/* printf("indice: %d\n", indice_pivo); */

	imprime_vetor(vetor, tam);
	printf("numero de comparacoes: %d\n", numComparacoes);

	return 0;
}
