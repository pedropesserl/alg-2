#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

void inicializarOrdenado(int *vetor, int tam) {
	for (int i = 0; i < tam; i++)
		vetor[i] = i;
}

void inicializarAoContrario(int *vetor, int tam) {
	for (int i = 0; i < tam; i++)
		vetor[i] = tam - i;
}

void inicializarAleatorio(int *vetor, int tam) {
	for (int i = 0; i < tam; i++)
		vetor[i] = rand() % (tam + 1);
}

int inicializarVetoresParaTeste(int *ordenado, int *copia_ordenado,
								int *aoContrario, int *copia_aoContrario,
								int *aleatorio, int * copia_aleatorio) {
	if ( !(ordenado = malloc((tamVetor + 10) * sizeof(int))) )
		return 0;
	inicializarOrdenado(ordenado, tamVetor);

	if ( !(copia_ordenado = malloc((tamVetor + 10) * sizeof(int))) )
		return 0;
	memcpy(copia_ordenado, ordenado, tamVetor);

	if ( !(aoContrario = malloc((tamVetor + 10) * sizeof(int))) )
		return 0;
	inicializarAoContrario(aoContrario, tamVetor);

	if ( !(copia_aoContrario = malloc((tamVetor + 10) * sizeof(int))) )
		return 0;
	memcpy(copia_aoContrario, aoContrario, tamVetor);

	if ( !(aleatorio = malloc((tamVetor + 10) * sizeof(int))) )
		return 0;
	inicializarAleatorio(aleatorio, tamVetor);

	if ( !(copia_aleatorio = malloc((tamVetor + 10) * sizeof(int))) )
		return 0;
	memcpy(copia_aleatorio, aleatorio, tamVetor);

	return 1;
}

int main() {
	srand(0);

	char nome[MAX_CHAR_NOME];
	int idxBusca;
	int numComp;

	const int tamVetor = 65000;

	int *ordenado, ordenado_, aoContrario, aoContrario_, aleatorio, aleatorio_;

	if ( !(inicializarVetoresParaTeste(ordenado, ordenado_, aoContrario, aoContrario_, aleatorio, aleatorio_)) ) {
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	} // inicializa 3 vetores para testes

	getNome(nome);
	printf("Trabalho de %s\n", nome);
	printf("GRR %u\n", getGRR());

	//Para medir o tempo, inclua time.h, e siga o exemplo:
	clock_t start, end;//variáveis do tipo clock_t
    double total;

	start = clock();//start recebe o "ciclo" corrente
	numComp = insertionSort(vetor, 3);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f", total);

	numComp = selectionSort(vetor, 3);
	numComp = mergeSort(vetor, 3);
	numComp = quickSort(vetor, 3);
	numComp = heapSort(vetor, 3);

	for (int i=0; i < 3; i++) {
		printf("%d ", vetor[i]);
	}
	idxBusca = buscaSequencial(vetor, 3, 10, &numComp);
	idxBusca = buscaBinaria(vetor, 3, 10, &numComp);

	printf("\n%d %d", idxBusca, numComp);
	printf("\n");

	//É obrigatório que você libere a memória alocada dinamicamente via free
	free(ordenado);
	free(aoContrario);
	free(aleatorio);

	return 0;
}
