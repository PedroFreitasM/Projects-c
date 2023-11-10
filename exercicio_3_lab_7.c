#include <stdio.h>
#include <stdlib.h>
void buscaMenorMaiorBin(int arr[], int tam, int el, int *menor, int *maior);
int main(){
    int quantidade;
    int* vetor;
    int procura;
    int mai = 0 , men = 0;
    printf("Digite a quantidade de elementos: ");
    scanf("%d", &quantidade);
    vetor = (int *)malloc(quantidade * sizeof(int));
    printf("Digite os elementos do vetor: ");
    for(int i = 0; i < quantidade; i++){
        scanf("%d", &vetor[i]);
    }
    printf("Digite o elemento procurado: ");
    scanf("%d", &procura);
    buscaMenorMaiorBin(vetor, quantidade, procura, &men, &mai);
    printf("Elementos maiores: %d\nElementos menores: %d", mai, men);
    return 0;
}

void buscaMenorMaiorBin(int arr[], int tam , int el, int *menor, int *maior){
int fim = tam - 1;
    int ini = 0;
    int iteracao = 0;
    int disc = 0;
    while (ini <= fim){
        iteracao++;
        int meio = (fim + ini)/2;
        if (arr[meio] < el){
            disc = meio - ini + 1;
            *menor += disc;
            ini = meio + 1;
        } 
        else{
            if (arr[meio] > el){
                disc = fim - meio + 1;
                *maior+= disc;
                fim = meio - 1;
            }
            else {
                *menor += (meio - ini);
                *maior += (fim - meio);
            }
        }
    }
}