#include <stdio.h>
#include <stdlib.h>

#define MEM_ERROR_EXIT                                    \
	do {                                                  \
		fprintf(stderr, "Erro na alocação de memória.");  \
		exit(1);                                          \
	} while(0)

typedef struct {
	int valor;
	int peso;
} presente_t;

void le_entrada(presente_t presentes[], int tam) {
	for (int i = 0; i < tam; i++)
		scanf("%d %d", &presentes[i].valor, &presentes[i].peso);
}

void imprime_vetor(int vetor[], int tam) {
	for (int i = 0; i < tam; i++)
		printf("%d ", vetor[i]);
	printf("\n");
}

int vetor_valido(int vbin[], presente_t presentes[], int tam, int p_max) {
	int peso_atual = 0;

	for (int i = 0; i < tam; i++) {
		if (vbin[i])
			peso_atual += presentes[i].peso;

	}

	return peso_atual <= p_max;
}

void vetores_binarios(int vbin[], presente_t presentes[], int tam, int p_max, int i) {
	if (i == tam) {
		if (vetor_valido(vbin, presentes, tam, p_max))
			imprime_vetor(vbin, tam);
		return;
	}

	vbin[i] = 0;
	vetores_binarios(vbin, presentes, tam, p_max, i+1);
	vbin[i] = 1;
	vetores_binarios(vbin, presentes, tam, p_max, i+1);
}

void resolve_papai_noel(int tam, int p_max, presente_t presentes[]) {
	//int valor_solucao;
	int indices_solucao[p_max];
	
	vetores_binarios(indices_solucao, presentes, tam, p_max, 0);

}

int main(void) {
	int n, p_max;
	scanf("%d %d", &n, &p_max);
	presente_t presentes[n];
	le_entrada(presentes, n);

	resolve_papai_noel(n, p_max, presentes);

	return 0;
}
