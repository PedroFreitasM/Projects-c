#include <stdio.h>
void insertionRecursivo(int v[], int tam);
void bubbleRecursivo(int v[], int tam);
void selecaoRecursivo(int v[], int tam);
int main(){
    int vec[5] = {4, 5, 3, 1, 2};
    selecaoRecursivo(vec, 5);
    for(int k = 0; k < 5; k++){
        printf("%d ", vec[k]);
    }
    return 0;
}

void bubbleRecursivo(int v[], int tam){
    int aux;
        for(int i = 0; i < (tam - 1); i++){
            if (v[i] > v[i+1]) {
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux; }
        }
        if ((tam) > 0)
        bubbleRecursivo(v, (tam - 1));
}

void insertionRecursivo(int v[], int tam){
    if (tam > 1){
    insertionRecursivo(v, (tam-1));
    }
    int a = tam - 1;
    int aux = v[a];
    int j = a;
    while ((j>0)&&(aux<v[j-1])){
        v[j] = v[j-1];
        j--; 
        v[j] = aux;
    }
}
void selecaoRecursivo(int v[], int tam) {
    int i, p, aux, posMenor;
    i = tam - 1;
    if(tam > 0){
        selecaoRecursivo(v, i);
    }
        posMenor = i;
        for (p=i+1; p<tam; p++){
            if (v[p] < v[posMenor]){
                posMenor = p;
            }
            aux = v[i];
        v[i] = v[posMenor];
        v[posMenor] = aux;  
}
}