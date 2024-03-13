#include <stdio.h>
#include <stdlib.h>

void tamMat(int* lin, int* col){
    printf("Digite a  largura da matriz: ");
    scanf("%d", lin);
    printf("Digite a altura da matriz: ");
    scanf("%d", col);
}

int** initVetP(int lin, int col){
    int **vetP = malloc(lin * sizeof(int*));
    
    for(int i = 0; i < lin; i++)
        vetP[i] = malloc(col * sizeof(int*));
        
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            printf("Digite o elemento vetP[%d][%d] ", i + 1, j + 1);
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

int main()
{
    int col, lin;
    tamMat(&lin, &col);
    int **vetP = initVetP(lin, col);
    impVetP(vetP, lin, col);
    
    
    
    
    
    
    free(vetP);
    return 0;
}
