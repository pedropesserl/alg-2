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

int aux_buscaSequencial(int vetor[], int tam, int valor, int *numComparacoes) {
	(*numComparacoes)++;
	if (valor == vetor[tam-1]) return tam-1;

	return aux_buscaSequencial(vetor, tam-1, valor, numComparacoes);
}

int buscaSequencial(int vetor[], int tam, int valor, int *numComparacoes) {
	if (tam < 1) return -1;

	(*numComparacoes)++;
	if(valor > vetor[tam-1]) return -1;
	
	(*numComparacoes)++;
	if (valor < vetor[0]) return -1;

	return aux_buscaSequencial(vetor, tam, valor, numComparacoes);
}

int aux_buscaBinaria(int vetor[], int inicio, int fim, int valor, int *numComparacoes) {
	if (fim - inicio < 0) return -1;

	int m = (fim + inicio) / 2;

	(*numComparacoes)++;
	if (valor == vetor[m]) return m;

	(*numComparacoes)++;
	if (valor < vetor[m]) return aux_buscaBinaria(vetor, inicio, m-1, valor, numComparacoes);

	return aux_buscaBinaria(vetor, m+1, fim, valor, numComparacoes);
}

int buscaBinaria(int vetor[], int tam, int valor, int *numComparacoes) {
	return aux_buscaBinaria(vetor, 0, tam-1, valor, numComparacoes);
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
