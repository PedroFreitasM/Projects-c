#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct aux1{
    char c;
    float n;
    struct aux1 *prox;
} ELEMENTO;

typedef struct {
    ELEMENTO* topo;
} PILHA;

void inicializarPilha(PILHA* p){
    p->topo = NULL;
}

void pushNum(PILHA* pil, float numero);
void pushChar(PILHA* pil, char ch);
bool popPilhaNum(PILHA* p, float* x);
bool popPilhaChar(PILHA* p, char* x);
float executarOperacao(float op1, float op2, char operando);

int main(){
    int res;
    PILHA* numeros = (PILHA *)malloc(sizeof(PILHA));
    PILHA* operandos = (PILHA *)malloc(sizeof(PILHA));
    inicializarPilha(operandos);
    int d;
    float aux = 0.0, aux2 = 0.0;
    char aux_char;
    pushNum(numeros, 0.0);
    char expressao[100];
    fgets(expressao, 99, stdin);
    for(int i = 0; i < sizeof(expressao); i++){
        if(expressao[i] >= '0' && expressao[i] <= '9'){
            if(expressao[i-1] >= '0' && expressao[i-1] <= '9'){
                popPilhaNum(numeros, &aux);
                aux = (aux*10) + (expressao[i]-'0');
                pushNum(numeros,aux);
                continue;
            }
            else{
                d = expressao[i]-'0';
                aux = d;
                pushNum(numeros, aux);
                continue;
            }
        }
        if(expressao[i] == '(' || expressao[i] == '+' || expressao[i] == '*' || expressao[i] == '-' || expressao[i] == '/'){
            pushChar(operandos,expressao[i]);
            continue;
        }
        if(expressao[i] == ')'){
            while(operandos->topo->c != '('){
                popPilhaChar(operandos, &aux_char);
                popPilhaNum(numeros, &aux2);
                popPilhaNum(numeros, &aux);
                aux = executarOperacao(aux, aux2, aux_char);
                pushNum(numeros, aux);
            }
            popPilhaChar(operandos, &aux_char);
        } 
    }
    popPilhaNum(numeros, &aux);
    res = aux;
    printf("%d", res);
    return 0;
}

void pushNum(PILHA* pil, float numero){
    ELEMENTO* el;
    el = (ELEMENTO*)malloc(sizeof(ELEMENTO));
    el->n = numero;
    el->prox = pil->topo;
    pil->topo = el;
}

void pushChar(PILHA* pil, char ch){
    ELEMENTO* el;
    el = (ELEMENTO*)malloc(sizeof(ELEMENTO));
    el->c = ch;
    el->prox = pil->topo;
    pil->topo = el;
}

bool popPilhaNum(PILHA* p, float* x){
    if(p->topo == NULL){
        return false;
    }
    ELEMENTO* del;
    *x = p->topo->n;
    del = p->topo;
    p->topo = p->topo->prox;
    free(del);
    return true;
}

bool popPilhaChar(PILHA* p, char* x){
    if(p->topo == NULL){
        return false;
    }
    ELEMENTO* del;
    *x = p->topo->c;
    del = p->topo;
    p->topo = p->topo->prox;
    free(del);
    return true;
}

float executarOperacao(float op1, float op2, char operando){
    if(operando == '+'){
        return(op1 + op2);
    }
    if(operando == '-'){
        return(op1 - op2);
    }
    if(operando == '*'){
        return(op1 * op2);
    }
    if(operando == '/'){
        return(op1/op2);
    }
}

