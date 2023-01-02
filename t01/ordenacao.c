#include <string.h>
#include "ordenacao.h"

void getNome(char nome[]) {
	//substitua por seu nome
	strncpy(nome, "Pedro Folloni Pesserl", MAX_CHAR_NOME);
	nome[MAX_CHAR_NOME-1] = '\0';//adicionada terminação manual para caso de overflow
}

//a função a seguir deve retornar o seu número de GRR
unsigned int getGRR() {
	return 20220072;
}

int buscaSequencial(int vetor[], int tam, int valor, int *numComparacoes) {
	if (tam < 1) return -1;

	*numComparacoes++;
	if (valor = vetor[tam-1]) return tam-1;

	return buscaSequencial(vetor, tam-1, valor, numComparacoes);
}

int buscaBinaria(int vetor[], int tam, int valor, int *numComparacoes) {
	if (tam < 1) return -1;
	
	int m = (tam + 1) / 2;
	*numComparacoes++;
	if (valor < vetor[m]) return buscaBinaria(vetor, m-1, valor, numComparacoes);
	
	//TODO: não implementado
	*numComparacoes++;
	if (valor > vetor[m]) return buscaBinaria(, m-1, valor, numComparacoes);
}

int insertionSort(int vetor[], int tam) {
	vetor[0] = 99;
	return -1;
}

int selectionSort(int vetor[], int tam) {
	vetor[0] = 99;
	return -1;
}

int mergeSort(int vetor[], int tam) {
	vetor[0] = 99;
	return -1;
}

int quickSort(int vetor[], int tam) {
	vetor[0] = 99;
	return -1;
}

int heapSort(int vetor[], int tam) {
	vetor[0] = 99;
	return -1;
}
