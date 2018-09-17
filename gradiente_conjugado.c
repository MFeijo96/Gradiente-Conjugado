#include <stdio.h>
#include <stdlib.h>

void matriz_transposta (int l, int c, int matriz[][5]) {
	int matrizC[l][c];
	for (int i = 0; i < l; i++) {
		for (int j = i; j < c; j++) {
			if (j != i) {
				matrizC[i][j] = matriz[j][i];
				matrizC[j][i] = matriz[i][j];
			} else {
				matrizC[i][j] = matriz[j][i];
			}
		}
	}
}

void subtracao_matriz (int l, int c, int matriz[][5], int valor) {
	int matrizC[l][c];
	for (int i = 0; i < l; i++) {
		for (int j = i; j < c; j++) {
				matrizC[i][j] = valor - matriz[i][j];
		}
	}
}

void adicao_matriz (int l, int c, int matriz[][5], int valor) {
	int matrizC[l][c];
	for (int i = 0; i < l; i++) {
		for (int j = i; j < c; j++) {
				matrizC[i][j] = valor + matriz[i][j];
		}
	}
}

void multiplicacao_matriz(int l1, int c1, int matriz1[][5], int l2, int c2, int matriz2[][5]) {
	int matrizC[l1][c2];
	for(int i=0; i<l1; i++){
         for(int j=0; j<c2; j++){
             matrizC[i][j]=0;
             int aux = 0;
             for(int x=0; x<c1; x++){
                 aux+= matriz1[i][x] * matriz2[x][j];
             }
             matrizC[i][j]=aux;
         }
     }
}

void divisao_matriz(int l1, int c1, int matriz1[][5], int l2, int c2, int matriz2[][5]) {
	int matrizC[l1][c2];
	for(int i=0; i<l1; i++){
         for(int j=0; j<c2; j++){
             matrizC[i][j]=0;
             int aux = 0;
             for(int x=0; x<c1; x++){
                 aux+= matriz1[i][x] / matriz2[x][j];
             }
             matrizC[i][j]=aux;
         }
     }
}

void matriz_copy (void * destmat, void * srcmat) 
{
  memcpy(destmat,srcmat, ROWCOUNT*COLUMNCOUNT*sizeof(int));
}

int **gradiente_conjugado(int Rows, int A[], int Asize, int b)
{    
    int **x = (int **)malloc(Rows * sizeof(int *)); 
    int row;

    // for each row allocate Cols ints
    for (row = 0; row < Rows; row++) {
        x[row] = (int *)malloc(Rows * sizeof(int));
    }

    int imax = 1000;
	float erro = 0.00001f;
	int n = Asize;
	int i = 1;

	//zeros
	for (int i = 0; i < Rows; i++) {
		x[1][i] = t0;
	}

	int aux[Rows][1] = multiplicacao_matriz(Rows, Rows, A, 1, Rows, x);
	int r[Rows][1] = subtracao_matriz(Rows, 1, aux[][], b);
	int d[Rows][1];
	matriz_copy(d, r);
	int aux2[1][Rows] = matriz_transposta(Rows, 1, R);
	int sigma_novo[1][1] = multiplicacao_matriz(1, Rows, aux2, Rows, 1, R);
	int sigma0[1][1] 
	matriz_copy(sigma0, sigma_novo);

	while (i < imax && sigma_novo > erro^2 * sigma0) {
		int q[Rows][1] = multiplicacao_matriz(Rows, Rows, A, Rows, 1, d)
		int aux3[1][Rows] = matriz_transposta(Rows, 1, d);
		int aux4[1][1] = multiplicacao_matriz(1, Rows, aux3, Rows, 1, q);
		alpha[1][1] = divisao_matriz(1,1,sigma_novo, 1, 1, aux4);
		x[][] = subtracao_matriz(1,1,multiplicacao_matriz(1,1,alpha,Rows,1,d,), x);
		if (i % 50 == 0)
			r[Rows][1] = adicao_matriz(Rows, Rows, multiplicacao_matriz(Rows, Rows, A, 1, Rows, x), x);
		else
			r[Rows][1] = subtracao_matriz(Rows, Rows, multiplicacao_matriz(1, 1, alpha, 1, Rows, x), r);

		int sigma_velho[1][1] 
		matriz_copy(sigma_velho, sigma_novo);
		int sigma_novo[1][1] = multiplicacao_matriz(1, Rows, matriz_transposta(Rows, 1, R);, Rows, 1, R);
		int beta[1][1] = divisao_matriz(1,1,sigma_novo,1,1,sigma_velho);
		d[Rows][1] = adicao_matriz(Rows, Rows, multiplicacao_matriz(1, 1, beta, Rows, 1, d), r);
		i++;
	}
	
	//matriz_transposta(Rows, Rows, x);


	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Rows; j++) {
			printf("%d ", matrizC[i][j]);
		}
		printf("\n");
	}
	
    return x;
}

int main() {
	int teste[5] = {1000, 2, 3, 17, 50};
	gradiente_conjugado(2, teste, 5, 100);
}
