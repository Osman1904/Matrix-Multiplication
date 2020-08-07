#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    FILE *file;
    file = fopen(argv[1], "rt");
    int n, x=0;
    int matrix[7][15][15], mult[15][15],matrix2[15][15], answer[15][15],square[1][15][15], j, k, i,ging;
    int rows[15], column[15];
    fscanf(file, "%d", &n);
    while(x<2){
    fscanf(file, "%d%d", &rows[x], &column[x]);
    j = k = 0;
    for(j=0;j<rows[x];j++){
            for(k=0;k<column[x];k++){
                fscanf(file, "%d", &matrix[x][j][k]);
            }
        }
    x++;
    }
    if(column[0] != rows[1]){
        printf("Error matrices.");
        exit(1);
    }
    for(x=0;x<2;x++){
    for (int i = 0; i < rows[x]; ++i) {
        for (int j = 0; j < column[x+1]; ++j) {
            for (int k = 0; k < column[x]; ++k) {
                mult[i][j] += matrix[x][i][k] * matrix[x+1][k][j];

            }
        }
    }
    }
    for(x=0;x<2;x++){
            if(rows[x] == column[x]){
    for (int i = 0; i < rows[x]; ++i) {
        for (int j = 0; j < column[x]; ++j) {
            for (int k = 0; k < column[x]; ++k) {
                square[x][i][j] += matrix[x][i][k] * matrix[x][k][j];

            }
        }
    }
    printf("Square of matrice(when row is equal to column): \n");
     for(i=0;i<rows[x];++i){
                for(j=0;j<column[x];j++){
                    printf("%d \t", square[x][i][j]);
        }printf("\n");
     }
            }
    }
   if(n<=2){
        printf("Products of the matrices:\n");
        for(i=0;i<rows[0];++i){
        for(j=0;j<column[1];j++){
            printf("%d \t", mult[i][j]);
        }printf("\n");
     }
    }
    if(n>2){
        int c = n-2;
        while(c--){
        int a, b;
        fscanf(file, "%d%d", &a, &b);
        int matrix2[a][b];
        ging = b;
        for(j=0;j<a;j++){
            for(k=0;k<b;k++){
                fscanf(file, "%d", &matrix2[j][k]);
                answer[j][k] = mult[j][k];
            }
    }

     for (int i = 0; i < rows[0]; ++i) {
        for (int j = 0; j < column[1]; ++j) {
            mult[i][j] = 0;
        }
    }
     for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            for (int k = 0; k < b; ++k) {
                    mult[i][j] += answer[i][k] * matrix2[k][j];
    }
}
     }
     if(column[0] != a){
        printf("Error Matrices");
        exit(1);
     }
     for(i = 0;i<a;i++){
        for(j=0;j<b;j++){
            square[0][i][j] = 0;
        }
     }
     if(a==b){
        for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            for (int k = 0; k < b;k++){
                square[0][i][j] += matrix2[i][k] * matrix2[k][j];

            }
        }
    }
     printf("Square of matrice(when row is equal to column): \n");
    for(i=0;i<a;++i){
        for(j=0;j<b;j++){
            printf("%d \t", square[0][i][j]);
        }printf("\n");
     }
        }
    }

        printf("Product of the matrices: \n");
     for(i=0;i<rows[1];++i){
        for(j=0;j<ging;j++){
            printf("%d \t", mult[i][j]);
        }printf("\n");
     }

    }
    fclose(file);
    return 0;
    }
