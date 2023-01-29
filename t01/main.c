#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ordenacao.h"

int *criaOrdenado(int tam) {
	int *v;
	if ( !(v = malloc(tam * sizeof(int))) )
		return NULL;

	for (int i = 0; i < tam; i++)
		v[i] = i;

	return v;
}

int *criaAoContrario(int tam) {
	int *v;
	if ( !(v = malloc(tam * sizeof(int))) )
		return NULL;

	for (int i = 0; i < tam; i++)
		v[i] = tam - i;

	return v;
}

int *criaAleatorio(int tam) {
	int *v;
	if ( !(v = malloc(tam * sizeof(int))) )
		return NULL;

	for (int i = 0; i < tam; i++)
		v[i] = rand() % (tam + 1);

	return v;
}

void imprime_vetor(int *v, int tam) {
	for (int i = 0; i < tam; i++)
		printf("%d ", v[i]);
	printf("\n");
}

int main() {
	srand(0);

	char nome[MAX_CHAR_NOME];
	int i;
	int idxBusca;
	int numComp;

	const int tamVetorGrande = 65000; //tamanho máximo para representar o número de
									  //comparações com int, já que 65000 * 65001 / 2 < 2^31

	getNome(nome);
	printf("Trabalho de %s\n", nome);
	printf("GRR %u\n\n", getGRR());

	// alocação e inicialização dos vetores para teste:
	int *ordenado, *ordenado_, *aoContrario, *aoContrario_, *aleatorio, *aleatorio_;

	if ( !(ordenado = criaOrdenado(tamVetorGrande)) ) {
		printf("Falha fatal. Impossível alocar memória.");
		return 1;
	}
	if ( !(ordenado_ = malloc(tamVetorGrande * sizeof(int))) ) {
		printf("Falha fatal. Impossível alocar memória.");
		return 1;
	}
	memcpy(ordenado_, ordenado, tamVetorGrande * sizeof(int));

	if ( !(aoContrario = criaAoContrario(tamVetorGrande)) ) {
		printf("Falha fatal. Impossível alocar memória.");
		return 1;
	}
	if ( !(aoContrario_ = malloc(tamVetorGrande * sizeof(int))) ) {
		printf("Falha fatal. Impossível alocar memória.");
		return 1;
	}
	memcpy(aoContrario_, aoContrario, tamVetorGrande * sizeof(int));
	
	if ( !(aleatorio = criaAleatorio(tamVetorGrande)) ) {
		printf("Falha fatal. Impossível alocar memória.");
		return 1;
	}
	if ( !(aleatorio_ = malloc(tamVetorGrande * sizeof(int))) ) {
		printf("Falha fatal. Impossível alocar memória.");
		return 1;
	}
	memcpy(aleatorio_, aleatorio, tamVetorGrande * sizeof(int));
	
	int vetorPequeno[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	// FIM: alocação e inicialização dos vetores para teste

	clock_t start, end;
    double total;

	printf("Testes dos algoritmos de ordenação:\n\n");

	printf("Teste de funcionalidade -- ordenar em ordem crescente um vetor pequeno (10 posições), inicialmente em ordem decrescente:\n");

	printf("Vetor pequeno: ");
	imprime_vetor(vetorPequeno, 10);
	printf("-- Insertion sort --\n");
	insertionSort(vetorPequeno, 10);
	printf("Vetor pequeno ordenado: ");
	imprime_vetor(vetorPequeno, 10);
	for (i = 0; i < 10; i++) vetorPequeno[i] = 10 - i;
	printf("\n");

	printf("Vetor pequeno: ");
	imprime_vetor(vetorPequeno, 10);
	printf("-- Selection sort --\n");
	selectionSort(vetorPequeno, 10);
	printf("Vetor pequeno ordenado: ");
	imprime_vetor(vetorPequeno, 10);
	for (i = 0; i < 10; i++) vetorPequeno[i] = 10 - i;
	printf("\n");

	printf("Vetor pequeno: ");
	imprime_vetor(vetorPequeno, 10);
	printf("-- Merge sort --\n");
	mergeSort(vetorPequeno, 10);
	printf("Vetor pequeno ordenado: ");
	imprime_vetor(vetorPequeno, 10);
	for (i = 0; i < 10; i++) vetorPequeno[i] = 10 - i;
	printf("\n");

	printf("Vetor pequeno: ");
	imprime_vetor(vetorPequeno, 10);
	printf("-- Quick sort --\n");
	quickSort(vetorPequeno, 10);
	printf("Vetor pequeno ordenado: ");
	imprime_vetor(vetorPequeno, 10);
	for (i = 0; i < 10; i++) vetorPequeno[i] = 10 - i;
	printf("\n");

	printf("Vetor pequeno: ");
	imprime_vetor(vetorPequeno, 10);
	printf("-- Heap sort --\n");
	heapSort(vetorPequeno, 10);
	printf("Vetor pequeno ordenado: ");
	imprime_vetor(vetorPequeno, 10);
	for (i = 0; i < 10; i++) vetorPequeno[i] = 10 - i;
	printf("\n");

	printf("Teste de tempo -- medir o tempo necessário para ordenar três vetores de 65000 posições cada; um já ordenado, um em ordem reversa, e um aleatorizado:\n");

	printf("Insertion sort:\n");
	printf("	Vetor ordenado...\n");
	start = clock(); //start recebe o "ciclo" corrente
	numComp = insertionSort(ordenado_, tamVetorGrande);
	end = clock();   //end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("	Pronto. Tempo total: %f s.\n", total);
	printf("	Número de comparações: %d.\n\n", numComp);

	printf("	Vetor em ordem reversa...\n");
	start = clock();
	numComp = insertionSort(aoContrario_, tamVetorGrande);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("	Pronto. Tempo total: %f s.\n", total);
	printf("	Número de comparações: %d.\n\n", numComp);
	
	printf("	Vetor aleatório...\n");
	start = clock();
	numComp = insertionSort(aleatorio_, tamVetorGrande);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("	Pronto. Tempo total: %f s.\n", total);
	printf("	Número de comparações: %d.\n\n", numComp);
	
	printf("Restabelecendo cópias...\n");
	memcpy(ordenado_, ordenado, tamVetorGrande * sizeof(int));
	memcpy(aoContrario_, aoContrario, tamVetorGrande * sizeof(int));
	memcpy(aleatorio_, aleatorio, tamVetorGrande * sizeof(int));
	printf("Pronto.\n\n");

	
	printf("Selection sort:\n");
	printf("	Vetor ordenado...\n");
	start = clock();
	numComp = selectionSort(ordenado_, tamVetorGrande);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("	Pronto. Tempo total: %f s.\n", total);
	printf("	Número de comparações: %d.\n\n", numComp);

	printf("	Vetor em ordem reversa...\n");
	start = clock();
	numComp = selectionSort(aoContrario_, tamVetorGrande);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("	Pronto. Tempo total: %f s.\n", total);
	printf("	Número de comparações: %d.\n\n", numComp);
	
	printf("	Vetor aleatório...\n");
	start = clock();
	numComp = selectionSort(aleatorio_, tamVetorGrande);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("	Pronto. Tempo total: %f s.\n", total);
	printf("	Número de comparações %d.\n\n", numComp);
	
	printf("Restabelecendo cópias...\n");
	memcpy(ordenado_, ordenado, tamVetorGrande * sizeof(int));
	memcpy(aoContrario_, aoContrario, tamVetorGrande * sizeof(int));
	memcpy(aleatorio_, aleatorio, tamVetorGrande * sizeof(int));
	printf("Pronto.\n\n");
	

	printf("Merge sort:\n");
	printf("	Vetor ordenado...\n");
	start = clock();
	numComp = mergeSort(ordenado_, tamVetorGrande);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("	Pronto. Tempo total: %f s.\n", total);
	printf("	Número de comparações: %d.\n\n", numComp);

	printf("	Vetor em ordem reversa...\n");
	start = clock();
	numComp = mergeSort(aoContrario_, tamVetorGrande);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("	Pronto. Tempo total: %f s.\n", total);
	printf("	Número de comparações: %d.\n\n", numComp);
	
	printf("	Vetor aleatório...\n");
	start = clock();
	numComp = mergeSort(aleatorio_, tamVetorGrande);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("	Pronto. Tempo total: %f s.\n", total);
	printf("	Número de comparações: %d.\n\n", numComp);
	
	printf("Restabelecendo cópias...\n");
	memcpy(ordenado_, ordenado, tamVetorGrande * sizeof(int));
	memcpy(aoContrario_, aoContrario, tamVetorGrande * sizeof(int));
	memcpy(aleatorio_, aleatorio, tamVetorGrande * sizeof(int));
	printf("Pronto.\n\n");
	

	printf("Quick sort:\n");
	printf("	Vetor ordenado...\n");
	start = clock();
	numComp = quickSort(ordenado_, tamVetorGrande);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("	Pronto. Tempo total: %f s.\n", total);
	printf("	Número de comparações: %d.\n\n", numComp);

	printf("	Vetor em ordem reversa...\n");
	start = clock();
	numComp = quickSort(aoContrario_, tamVetorGrande);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("	Pronto. Tempo total: %f s.\n", total);
	printf("	Número de comparações: %d.\n\n", numComp);
	
	printf("	Vetor aleatório...\n");
	start = clock();
	numComp = quickSort(aleatorio_, tamVetorGrande);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("	Pronto. Tempo total: %f s.\n", total);
	printf("	Número de comparações: %d.\n\n", numComp);
	
	printf("Restabelecendo cópias...\n");
	memcpy(ordenado_, ordenado, tamVetorGrande * sizeof(int));
	memcpy(aoContrario_, aoContrario, tamVetorGrande * sizeof(int));
	memcpy(aleatorio_, aleatorio, tamVetorGrande * sizeof(int));
	printf("Pronto.\n\n");
	

	printf("Heap sort:\n");
	printf("	Vetor ordenado...\n");
	start = clock();
	numComp = heapSort(ordenado_, tamVetorGrande);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("	Pronto. Tempo total: %f s.\n", total);
	printf("	Número de comparações: %d.\n\n", numComp);

	printf("	Vetor em ordem reversa...\n");
	start = clock();
	numComp = heapSort(aoContrario_, tamVetorGrande);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("	Pronto. Tempo total: %f s.\n", total);
	printf("	Número de comparações: %d.\n\n", numComp);
	
	printf("	Vetor aleatório...\n");
	start = clock();
	numComp = heapSort(aleatorio_, tamVetorGrande);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("	Pronto. Tempo total: %f s.\n", total);
	printf("	Número de comparações: %d.\n\n", numComp);
	

	numComp = 0;
	printf("Testes dos algoritmos de busca:\n");
	
	printf("Buscando pelo número 0 no vetor ordenado (posição esperada: 0):\n");
	printf("Busca sequencial...\n");
	start = clock();
	idxBusca = buscaSequencial(ordenado, tamVetorGrande, 0, &numComp);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Pronto. Tempo total: %f s.\n", total);
	printf("Posição: %d.\n", idxBusca);
	printf("Número de comparações: %d.\n\n", numComp);
	numComp = 0;

	printf("Busca binária...\n");
	start = clock();
	idxBusca = buscaBinaria(ordenado, tamVetorGrande, 0, &numComp);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Pronto. Tempo total: %f s.\n", total);
	printf("Posição: %d.\n", idxBusca);
	printf("Número de comparações: %d.\n\n", numComp);
	numComp = 0;
	
	printf("Buscando pelo número 32499 no vetor ordenado (posição esperada: 32499):\n");
	printf("Busca sequencial...\n");
	start = clock();
	idxBusca = buscaSequencial(ordenado, tamVetorGrande, 32499, &numComp);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Pronto. Tempo total: %f s.\n", total);
	printf("Posição: %d.\n", idxBusca);
	printf("Número de comparações: %d.\n\n", numComp);
	numComp = 0;

	printf("Busca binária...\n");
	start = clock();
	idxBusca = buscaBinaria(ordenado, tamVetorGrande, 32499, &numComp);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Pronto. Tempo total: %f s.\n", total);
	printf("Posição: %d.\n", idxBusca);
	printf("Número de comparações: %d.\n\n", numComp);
	numComp = 0;

	printf("Buscando pelo número 64999 no vetor ordenado (posição esperada: 64999):\n");
	printf("Busca sequencial...\n");
	start = clock();
	idxBusca = buscaSequencial(ordenado, tamVetorGrande, 64999, &numComp);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Pronto. Tempo total: %f s.\n", total);
	printf("Posição: %d.\n", idxBusca);
	printf("Número de comparações: %d.\n\n", numComp);
	numComp = 0;

	printf("Busca binária...\n");
	start = clock();
	idxBusca = buscaBinaria(ordenado, tamVetorGrande, 64999, &numComp);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Pronto. Tempo total: %f s.\n", total);
	printf("Posição: %d.\n", idxBusca);
	printf("Número de comparações: %d.\n\n", numComp);
	numComp = 0;

	printf("Buscando pelo número 65000 no vetor ordenado (posição esperada: -1):\n");
	printf("Busca sequencial...\n");
	start = clock();
	idxBusca = buscaSequencial(ordenado, tamVetorGrande, 65000, &numComp);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Pronto. Tempo total: %f s.\n", total);
	printf("Posição: %d.\n", idxBusca);
	printf("Número de comparações: %d.\n\n", numComp);
	numComp = 0;

	printf("Busca binária...\n");
	start = clock();
	idxBusca = buscaBinaria(ordenado, tamVetorGrande, 65000, &numComp);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Pronto. Tempo total: %f s.\n", total);
	printf("Posição: %d.\n", idxBusca);
	printf("Número de comparações: %d.\n\n", numComp);

	// liberando a memória alocada dinamicamente
	free(ordenado);
	free(ordenado_);
	free(aoContrario);
	free(aoContrario_);
	free(aleatorio);
	free(aleatorio_);

	return 0;
}
