#include <stdio.h>
#include <stdlib.h>

int main()
{
    int col, lin;
    printf("Digite a  largura da matriz: ");
    scanf("%d", &lin);
    printf("Digite a altura da matriz: ");
    scanf("%d", &col);
    
    int **vetP = malloc(lin * sizeof(int*));
    
    for(int i = 0; i < lin; i++)
        vetP[i] = malloc(col * sizeof(int*));
        
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            printf("Digite o elemento vetP[%d][%d] ", i + 1, j + 1);
            scanf("%d", &vetP[i][j]);
        }
    }
    
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            printf("%d ", vetP[i][j]);
        }
        printf("\n");
    }
    
    printf("Transposta:\n");
    for(int i = 0; i < col; i++){
        for(int j = 0; j < lin; j++){
            printf("%d ", vetP[j][i]);
        }
        printf("\n");
    }
    

    return 0;
}
