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

int main() {
	int *vetor;
	int tam = 10;
	vetor = le_vetor(tam);
	
	int num = 0;
	int *numComparacoes = &num;
	printf("busca: %d\n", buscaSequencial(vetor, tam, 10, numComparacoes));
	
	printf("numero de comparacoes: %d\n", *numComparacoes);
	free(vetor);
	return 0;
}
