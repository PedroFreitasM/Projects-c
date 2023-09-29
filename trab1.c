#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv){
    FILE *arq = fopen(argv[1], "wb+");
    if(arq == NULL){
        printf("Deu merda, n abriu\n");
        return -1;
    }
    int n;
    printf("Digite o valor de N\n");
    scanf("%d", &n);
    int *vec = (int *)malloc(n * sizeof(int));
    for (int i = n; i  > 0; i--){
        fwrite(&i, sizeof(int), 1 , arq);
    }
    rewind(arq);
    fread(vec, sizeof(int), n, arq);
    for(int i = 0; i < n; i++){
        printf("%d\n", vec[i]);
    }
    fclose(arq);
    return 0;
}

