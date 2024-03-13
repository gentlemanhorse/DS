#include <stdio.h>
#include <stdlib.h>

void tamMat(int* lin, int* col){
    printf("Digite a  altura da matriz: ");
    scanf("%d", lin);
    printf("Digite a largura da matriz: ");
    scanf("%d", col);
}

int** initVetP(int lin, int col){
    int **vetP = malloc(lin * sizeof(int*));
    
    for(int i = 0; i < lin; i++)
        vetP[i] = malloc(col * sizeof(int*));
        
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            printf("Digite o elemento [%d][%d]\n>>> ", i + 1, j + 1);
            scanf("%d", &vetP[i][j]);
        }
    }
    
    return vetP;
}

void impVetP(int** vetP, int lin, int col){
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++)
            printf("%d ", vetP[i][j]);
        printf("\n");
    }
    
    printf("Transposta:\n");
    for(int i = 0; i < col; i++){
        for(int j = 0; j < lin; j++)
            printf("%d ", vetP[j][i]);
        printf("\n");
    }
}

int* initVetU(int lin, int col){
    int* mat = malloc(lin * col * sizeof(int));
    
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            printf("lin = %d, col = %d\n", lin, col);
            printf("Digite o valor do elemento [%d][%d]\n>>> ", i, j, (i * col) + j);
            scanf("%d", &mat[(i * col) + j]);
        }
    }
    
    return mat;
}

void impVetU(int* mat, int lin, int col){
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++)
            printf(" %d", mat[(i * col) + j]);
        printf("\n");
    }
    
    printf("Transposta:\n");
    for(int i = 0; i < col; i++){
        for(int j = 0; j < lin; j++)
            printf(" %d", mat[(j * col) + i]);
        
    printf("\n");
    }
}

int main()
{
    // Vetor de ponteiros
    int col, lin;
    tamMat(&lin, &col);
    int **vetP = initVetP(lin, col);
    impVetP(vetP, lin, col);
    
    // Aloc única
    tamMat(&lin, &col);
    int *mat = initVetU(lin, col);
    impVetU(mat, lin, col);
    
    
    free(vetP);
    free(mat);
    return 0;
}
