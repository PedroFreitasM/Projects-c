#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;


typedef int TIPOCHAVE;
typedef struct {
	TIPOCHAVE chave;
} REGISTRO;

typedef struct aux {
	REGISTRO reg;
	struct aux* prox;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
	PONT topo;
} PILHA;

void conversao(int num);
void inicializarPilha(PILHA* p);
bool inserirElemPilha(PILHA* p, REGISTRO reg);
bool excluirElemPilha(PILHA* p, REGISTRO* reg);
bool estaVazia(PILHA* p);

int main(){
	int x;
	printf("Digite o numero a ser convertido\n");
	scanf("%d", &x);
	conversao(x);
return 0;
}

void inicializarPilha(PILHA* p)
{
	p->topo = NULL;
}

bool inserirElemPilha(PILHA* p, REGISTRO reg) {
	PONT novo = (PONT) malloc(sizeof(ELEMENTO));
	novo->reg = reg;
	novo->prox = p->topo;
	p->topo = novo;
	return true;
}
void conversao(int num){
	PILHA bin;
	REGISTRO digito;
	inicializarPilha(&bin);
	while(num > 1){
		digito.chave = num%2;
		inserirElemPilha(&bin, digito);
		num = num/2;
	}
	digito.chave = num;
	inserirElemPilha(&bin, digito);
	while(!(estaVazia(&bin))){
	excluirElemPilha(&bin, &digito);
	printf("%d", digito.chave);
	}
}		
bool excluirElemPilha(PILHA* p, REGISTRO* reg) {
	if ( p->topo == NULL) return false;
	*reg = p->topo->reg;
	PONT apagar = p->topo;
	p->topo = p->topo->prox;
	free(apagar);
	return true; 
	}
bool estaVazia(PILHA* p) {
	if (p->topo == NULL){
		return true;
		}
	return false;
}
