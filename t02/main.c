#include <stdio.h>
#include <stdlib.h>

#define MEM_ERROR_EXIT                                    \
	do {                                                  \
		fprintf(stderr, "Erro na alocação de memória.");  \
		exit(1);                                          \
	} while(0)

void le_entrada(int tam, int **valores, int **pesos) {
	if ( !(*valores = malloc(tam * sizeof(int))) )
		MEM_ERROR_EXIT;
	if ( !(*pesos = malloc(tam * sizeof(int))) )
		MEM_ERROR_EXIT;
	
	for (int i = 0; i < tam; i++)
		scanf("%d %d", *valores+i, *pesos+i);
}

void imprime_vetor(int *vetor, int tam) {
	for (int i = 0; i < tam; i++)
		printf("%d ", vetor[i]);
	printf("\n");
}

void resolve_papai_noel(int tam, int p_max, int *valores, int *pesos) {
	// TODO: nao implementado
}

void resolve_papai_noel_aux() {
	// TODO: nao implementado
}

int main(void) {
	int n, p_max;
	int *valores, *pesos;
	scanf("%d %d", &n, &p_max);
	le_entrada(n, &valores, &pesos);

	resolve_papai_noel(n, p_max, valores, pesos);

	free(valores);
	free(pesos);
	return 0;
}
