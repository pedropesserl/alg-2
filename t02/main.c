#include <stdio.h>
#include <stdlib.h>

typedef struct {
	double valor;
	double peso;
} presente_t;

void le_entrada(presente_t presentes[], int tam) {
	for (int i = 0; i < tam; i++)
		scanf("%lf %lf", &presentes[i].valor, &presentes[i].peso);
}

void imprime_vetor(int vetor[], int tam) {
	for (int i = 0; i < tam-1; i++)
		printf("%d ", vetor[i]);
	printf("%d\n", vetor[tam-1]);
}

void trata_solucao(int vbin[], presente_t presentes[], int tam, double *valor_maximo, int indices_solucao[], int *tam_solucao) {
	double valor_total = 0;

	for (int i = 0; i < tam; i++)
		if (vbin[i])
			valor_total += presentes[i].valor;

	int j = 0;
	if (valor_total > *valor_maximo) {
		for (int i = 0; i < tam; i++)
			if (vbin[i]) {
				indices_solucao[j] = i + 1;
				j++;
			}

		*tam_solucao = j;
		*valor_maximo = valor_total;
	}
}

int vetor_valido(int vbin[], presente_t presentes[], int tam, int p_max) {
	double peso_presentes = 0;

	for (int i = 0; i < tam; i++)
		if (vbin[i])
			peso_presentes += presentes[i].peso;

	return peso_presentes <= p_max;
}

void acha_solucoes(int vbin[], presente_t presentes[], int tam, int p_max, double *valor_maximo, int indices_solucao[], int *tam_solucao, int i) {
	// essa função implementa o backtracking do algoritmo criando recursivamente todos os
	// possíveis vetores binários de tamanho tam

	if (i == tam) { // caso base
		// checa se o subconjunto do conjunto de presentes gerado pelo
		// vetor binário tem peso válido
		if (vetor_valido(vbin, presentes, tam, p_max))
			// escreve o vetor de indices dos presentes encontrados e
			// define o valor sentimental máximo encotrado até o momento
			trata_solucao(vbin, presentes, tam, valor_maximo, indices_solucao, tam_solucao);
		return;
	}

	vbin[i] = 0;
	acha_solucoes(vbin, presentes, tam, p_max, valor_maximo, indices_solucao, tam_solucao, i+1);
	vbin[i] = 1;
	acha_solucoes(vbin, presentes, tam, p_max, valor_maximo, indices_solucao, tam_solucao, i+1);
}

void resolve_papai_noel(int tam, int p_max, presente_t presentes[]) {
	double valor_solucao = 0;
	int tam_solucao;
	int indices_solucao[tam];
	int vbin[tam];
	
	acha_solucoes(vbin, presentes, tam, p_max, &valor_solucao, indices_solucao, &tam_solucao, 0);

	imprime_vetor(indices_solucao, tam_solucao);
	printf("%lf\n", valor_solucao);
}

int main(void) {
	int n;
	double p_max;
	scanf("%d %lf", &n, &p_max);
	presente_t presentes[n];
	le_entrada(presentes, n);

	resolve_papai_noel(n, p_max, presentes);

	return 0;
}
