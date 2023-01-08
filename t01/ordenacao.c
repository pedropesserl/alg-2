#include <stdlib.h>
#include <string.h>
#include <stdio.h>
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
	if (valor == vetor[tam-1])
		return tam-1;

	return aux_buscaSequencial(vetor, tam-1, valor, numComparacoes);
}

int buscaSequencial(int vetor[], int tam, int valor, int *numComparacoes) {
	if (tam < 1)
		return -1;

	(*numComparacoes)++;
	if(valor > vetor[tam-1])
		return -1;
	
	(*numComparacoes)++;
	if (valor < vetor[0])
		return -1;

	return aux_buscaSequencial(vetor, tam, valor, numComparacoes);
}

int aux_buscaBinaria(int vetor[], int inicio, int fim, int valor, int *numComparacoes) {
	if (inicio > fim)
		return -1;

	int m = (fim + inicio) / 2;

	(*numComparacoes)++;
	if (valor == vetor[m])
		return m;

	(*numComparacoes)++;
	if (valor < vetor[m])
		return aux_buscaBinaria(vetor, inicio, m-1, valor, numComparacoes);

	return aux_buscaBinaria(vetor, m+1, fim, valor, numComparacoes);
}

int buscaBinaria(int vetor[], int tam, int valor, int *numComparacoes) {
	return aux_buscaBinaria(vetor, 0, tam-1, valor, numComparacoes);
}

void troca(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int insereUltimo(int vetor[], int tam) {
	if (tam <= 1)
		return 0;

	if (vetor[tam-1] >= vetor[tam-2])
		return 1;
	
	troca(vetor + tam-1, vetor + tam-2);

	return insereUltimo(vetor, tam-1) + 1;
}

int insertionSort(int vetor[], int tam) {
	if (tam <= 1)
		return 0;

	return insertionSort(vetor, tam-1) + insereUltimo(vetor, tam);
}

int maximo(int vetor[], int tam, int *numComparacoes) {
	if (tam == 1)
		return 0;

	int maior = maximo(vetor, tam-1, numComparacoes);
	
	(*numComparacoes)++;
	return vetor[tam-1] > vetor[maior] ? tam-1 : maior;
}

//para não precisar de uma função auxiliar, o selectionSort ordena
//colocando o maior elemento na última posição, em vez do menor elemento
//na primeira.
int selectionSort(int vetor[], int tam) {
	if (tam < 1)
		return 0;
	
	int comparacoesMaximo = 0;

	int m = maximo(vetor, tam, &comparacoesMaximo);
	troca(vetor + tam-1, vetor + m);

	return selectionSort(vetor, tam-1) + comparacoesMaximo;
}

int intercala(int vetor[], int posA, int posB, int tamA, int tamB, int novo[], int posNovo) {
	if (tamA < 1 && tamB < 1)
		return 0;

	if (tamA > 0 && (tamB <= 0 || vetor[posA] < vetor[posB])) {
		novo[posNovo] = vetor[posA];
		return intercala(vetor, posA+1, posB, tamA-1, tamB, novo, posNovo+1) + 1;
	}

	novo[posNovo] = vetor[posB];
	return intercala(vetor, posA, posB+1, tamA, tamB-1, novo, posNovo+1) + 1;
}

int aux_mergeSort(int vetor[], int inicio, int fim, int novo[]) {
	if (inicio >= fim)
		return 0;

	int meio = (fim + inicio) / 2;

	int numComparacoes = 0;
	
	numComparacoes += aux_mergeSort(vetor, inicio, meio, novo);
	numComparacoes += aux_mergeSort(vetor, meio + 1, fim, novo);
	numComparacoes += intercala(vetor, inicio, meio + 1, meio - inicio + 1, fim - meio, novo, 0);

	for (int i = 0; i <= fim - inicio; i++)
		vetor[i + inicio] = novo[i];

	return numComparacoes;
}

int mergeSort(int vetor[], int tam) {
	int *novo;
	if ( !(novo = malloc(tam * sizeof(int))) )
		return 0;

	int numComparacoes = aux_mergeSort(vetor, 0, tam-1, novo);

	free(novo);

	return numComparacoes;
}

int particiona(int vetor[], int inicio, int fim, int *pivo) {
	if (inicio > fim)
		return 0;
	
	if (vetor[inicio] <= vetor[fim]) {
		(*pivo)++;
		troca(vetor + *pivo, vetor + inicio);
	}

	return particiona(vetor, inicio + 1, fim, pivo) + 1;
}

int aux_quickSort(int vetor[], int inicio, int fim) {
	if (inicio >= fim)
		return 0;

	int pivo = inicio - 1;

	int numComparacoes = 0;

	numComparacoes += particiona(vetor, inicio, fim, &pivo);
	numComparacoes += aux_quickSort(vetor, inicio, pivo-1);
	numComparacoes += aux_quickSort(vetor, pivo+1, fim);

	return numComparacoes;
}

int quickSort(int vetor[], int tam) {
	return aux_quickSort(vetor, 0, tam-1);
}

int heapSort(int vetor[], int tam) {
	vetor[0] = 99;
	return -1;
}
