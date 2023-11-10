#include <stdio.h>
#include <stdlib.h>
int buscaBinMod(int arr[], int tam, int el);
int main(){
    int quantidade;
    int* vetor;
    int procura;
    int pos;
    printf("Digite a quantidade de elementos: ");
    scanf("%d", &quantidade);
    vetor = (int *)malloc(quantidade * sizeof(int));
    printf("Digite os elementos do vetor: ");
    for(int i = 0; i < quantidade; i++){
        scanf("%d", &vetor[i]);
    }
    printf("Digite o elemento procurado: ");
    scanf("%d", &procura);
    pos = buscaBinMod(vetor, quantidade, procura);
    printf("Posicao do elemento: %d", pos);
    return 0;
}

int buscaBinMod(int arr[], int tam, int el){
    int fim = tam - 1;
    int ini = 0;
    int iteracao = 0;
    int disc = 0;
    while (ini <= fim){
        iteracao++;
        int meio = (fim + ini)/2;
        if (arr[meio] < el){
            disc = meio - ini + 1;
            printf("%da. iteracao: %d\n", iteracao, disc);
            ini = meio + 1;
        } 
        else{
            if (arr[meio] > el){
                disc = fim - meio + 1;
                printf("%da. iteracao: %d\n", iteracao, disc);
                fim = meio - 1;
            }
            else {
                disc = fim - ini;
                printf("%da. iteracao: %d\n", iteracao, disc);
                return meio;
            }
        }
    }
    return -1;
} 
