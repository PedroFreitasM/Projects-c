#include <stdio.h>
#include <stdlib.h>
void buscaseqOrdRep(int arr[], int tam, int el ,int *pos, int *quant);
int main(){
    int q;
    int *vec;
    int ele, p, qua;
    
    printf("Digite a quantidade de elementos: ");
    scanf("%d", &q);
    vec = (int *)malloc(q * sizeof(int));
    printf("Digite os elementos do vetor: ");
    for(int i = 0; i < q; i++){
        scanf("%d", &vec[i]);
    }
    printf("Digite o elemento procurado");
    scanf("%d", &ele);
    buscaseqOrdRep(vec, q, ele, &p, &qua);
    printf("Posicao da primeira occorencia: %d\n", p);
    printf("Quantidade de ocorrencias: %d\n", qua);
    return 0;
}

void buscaseqOrdRep(int arr[], int tam, int el, int *pos, int *quant){
    *pos = -1;
    *quant = 0;
    for(int i = 0; i < tam; i++){
        if(arr[i] == el && *pos == -1){
            *pos = i;
        }
        if(arr[i] == el){
            *quant += 1;
        }
    }

}