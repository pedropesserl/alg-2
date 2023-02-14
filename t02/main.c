#include <stdio.h>
#include <stdlib.h>

#define MEM_ERROR_EXIT                                    \
	do {                                                  \
		fprintf(stderr, "Erro na alocação de memória.");  \
		exit(1);                                          \
	} while(0)

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

void acha_solucao(int vbin[], presente_t presentes[], int tam, double *valor_maximo, int indices_solucao[], int *tam_solucao) {
	double valor_total = 0;
	int j = 0;

	for (int i = 0; i < tam; i++)
		if (vbin[i])
			valor_total += presentes[i].valor;

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

void vetores_binarios(int vbin[], presente_t presentes[], int tam, int p_max, int i, double *valor_maximo, int indices_solucao[], int *tam_solucao) {
	if (i == tam) {
		if (vetor_valido(vbin, presentes, tam, p_max))
			acha_solucao(vbin, presentes, tam, valor_maximo, indices_solucao, tam_solucao);
		return;
	}

	vbin[i] = 0;
	vetores_binarios(vbin, presentes, tam, p_max, i+1, valor_maximo, indices_solucao, tam_solucao);
	vbin[i] = 1;
	vetores_binarios(vbin, presentes, tam, p_max, i+1, valor_maximo, indices_solucao, tam_solucao);
}

void resolve_papai_noel(int tam, int p_max, presente_t presentes[]) {
	double valor_solucao = 0;
	int tam_solucao;
	int indices_solucao[tam];
	int vbin[tam];
	
	vetores_binarios(vbin, presentes, tam, p_max, 0, &valor_solucao, indices_solucao, &tam_solucao);

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
