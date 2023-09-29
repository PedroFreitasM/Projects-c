#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char nome[100];
    double nota[3];
    double media;
} TAluno;
int main(){
    TAluno aluno;
    aluno.nome[0] = '\0';
    FILE *arq = fopen("alunos.dat", "wb+");
    if (arq == NULL){
        printf("Deu merda, nao abriu");
        return -1;
    }
    while(1){
        aluno.nome[0] = '\0';
        printf("Digite o nome do aluno\n");
        scanf("%[^\n]", aluno.nome);
        if(aluno.nome[0] == '\0') break;
        printf("Digite as tres notas do aluno\n");
        scanf("%lf %lf %lf", &aluno.nota[0], &aluno.nota[1], &aluno.nota[2]);
        getchar();
        aluno.media = (aluno.nota[0] + aluno.nota[1] + aluno.nota[2])/3;
        fwrite(&aluno, sizeof(TAluno), 1, arq);
    }
    return 0;
}
