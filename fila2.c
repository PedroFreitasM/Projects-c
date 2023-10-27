#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;
typedef int TIPOCHAVE;
typedef struct {
int produtos;
char nome[20];
int chegada;
//outros campos...
} REGISTRO;

typedef struct aux {
REGISTRO reg;
struct aux* prox;
} ELEMENTO;

typedef ELEMENTO* PONT;
typedef struct {
PONT inicio;
PONT fim;
} FILA;

void inicializarFila(FILA* f) {
f->inicio = NULL;
f->fim = NULL;
}

int tamanho(FILA* f) {
PONT end = f->inicio;
int tam = 0;
while (end != NULL) {
tam++;
end = end->prox; }
return tam; }

bool inserirNaFila(FILA* f,REGISTRO reg) {
PONT novo = (PONT) malloc(sizeof(ELEMENTO));
novo->reg = reg;
novo->prox = NULL;
if (f->inicio==NULL) f->inicio = novo;
else f->fim->prox = novo;
f->fim = novo;
return true;
}

bool excluirDaFila(FILA* f, REGISTRO* reg) {
if (f->inicio==NULL) return false;
*reg = f->inicio->reg;
PONT apagar = f->inicio;
f->inicio = f->inicio->prox;
free(apagar);
if (f->inicio == NULL) f->fim = NULL;
return true; }

int main(){
    FILA caixa;
    inicializarFila(&caixa);
    int vel;
    int clientes;
    int tempotot = 0;
    REGISTRO r;
    printf("Digite a velocidade de atendimento\n");
    scanf("%d", &vel);
    printf("Digite a quantia de clientes\n");
    scanf("%d", &clientes);
    for(int i = 0; i < clientes; i++){
        printf("Digite as info. do cliente\n");
        scanf("%s %d %d", r.nome, &r.chegada, &r.produtos);
        inserirNaFila(&caixa, r);
    }
    while(excluirDaFila(&caixa, &r)){
        printf("%s ", r.nome);
        if(tempotot < r.chegada){
            tempotot = r.chegada;
        }
        tempotot += (10 + (vel*(r.produtos)));
        printf("%d ", r.chegada);
        printf("%d\n", tempotot);
    }

    return 0;
}