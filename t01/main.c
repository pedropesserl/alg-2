#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"

/* void trocar(int *a, int *b) { */
/* 	int temp = *a; */
/* 	*a = *b; */
/* 	*b = temp; */
/* } */

/* int menor(int vetor[], int tam, int *numComparacoes) { */
/* 	if (tam == 1) */
/* 		return 0; */

/* 	int m = menor(vetor, tam-1, numComparacoes); */
	
/* 	(*numComparacoes)++; */
/* 	return vetor[tam-1] < vetor[m] ? tam-1 : m; */
/* } */

/* void temp_selectionSort(int vetor[], int inicio, int fim, int *numComparacoes) { */
/* 	if (fim - inicio <= 0) */
/* 		return; */

/* 	int m = menor(vetor, fim - inicio + 1, numComparacoes); */
/* 	trocar(vetor + inicio, vetor + m); */

/* 	temp_selectionSort(vetor, inicio+1, fim, numComparacoes); */
/* } */

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
	int tam = 10;
	if ( !(vetor = malloc(tam * sizeof(int))) ) return 1;
	vetor = le_vetor(tam);
	
	int numComparacoes = selectionSort(vetor, tam);
	/* printf("posicao do minimo: %d\n", menor(vetor, tam, &numComparacoes)); */
	imprime_vetor(vetor, tam);
	printf("numero de comparacoes: %d\n", numComparacoes);
	
	free(vetor);
	return 0;
}
