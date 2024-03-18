#include <stdio.h>
#include <stdlib.h>

void entTamanho(int* lin1, int* col1, int* lin2, int* col2){
    printf("Digite a quantidade de linhas da matriz 1\n>>> ");
    scanf("%d", lin1);

    printf("Digite a quantidade de colunas da matriz 1\n>>> ");
    scanf("%d", col1);

    printf("Digite a quantidade de linhas da matriz 2\n>>> ");
    scanf("%d", lin2);

    printf("Digite a quantidade de colunas da matriz 2\n>>> ");
    scanf("%d", col2);
}

int** instMatPonteiro(int lin, int col){
    int** mat = malloc(lin * sizeof(int*));
    for(int i = 0; i < lin; i++){
        mat[i] = malloc(col * sizeof(int));
        for(int j = 0; j < col; j++){
            mat[i][j] = 0;
        }
    }

    return mat;
}

void entMatPonteiro(int** mat, int lin, int col){
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            printf("Entre o elemento [%d][%d] da matriz 1\n>>>", i + 1, j + 1);
            scanf("%d", &mat[i][j]);
        }
    }
}

void saidaMatPonteiro(int** mat, int lin, int col){
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
    printf("\n");
}

int* instMatSimples(int lin, int col){
    int* mat = malloc(lin * col * sizeof(int));

    return mat;
}


void entMatSimples(int* mat, int lin, int col){
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            printf("Entre o elemento [%d][%d] da matriz 2\n>>> ", i + 1, j + 1);
            scanf("%d", &mat[(i * col) + j]);
        }
    }
}

void saidaMatSimples(int* mat, int lin, int col){
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++)
            printf("%d ", mat[(i * col) + j]);
        printf("\n");
    }
    printf("\n");
}

int** multipicaMatrizes(int** mat1, int* mat2, int lin1, int col1, int lin2, int col2){
    int** matF = instMatPonteiro(lin1, col2);
    for(int i = 0; i < lin1; i++){
        for(int j = 0; j < col2; j++){
            for(int k = 0; k < lin2; k++){
                matF[i][j] += mat1[i][k] * mat2[(k * col2) + j];
            }
        }
    }
    return matF;
}

int main(int arc, char* argv[]){
    int lin1, lin2, col1, col2;
    
    entTamanho(&lin1, &col1, &lin2, &col2);

    int** matP = instMatPonteiro(lin1, col1);
    int* matS = instMatSimples(lin2, col2);

    if(col1 == lin2){
        entMatPonteiro(matP, lin1, col1);
        entMatSimples(matS, lin2, col2);

        saidaMatPonteiro(matP, lin1, col1);

        saidaMatSimples(matS, lin2, col2);
        int** matF = multipicaMatrizes(matP, matS, lin1, col1, lin2, col2);
        saidaMatPonteiro(matF, lin1, col2);
        free(matF);
    }
    else    
        printf("Nao e possivel multiplicar as matrizes");

    free(matP);
    free(matS);

}
