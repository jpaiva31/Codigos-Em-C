#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 11
typedef struct{
int v[MAX];
int inicio, fim;
}Fila;

void push(Fila *f, int x){
    f->v[f->fim]= x;
    f->fim= (f->fim+1)%MAX;
}

int pop(Fila *f){
    char x=f->v[f->inicio];
    f->inicio=(f->inicio+1)%MAX;
        return x;
}

Fila *cria_fila(){
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->inicio=0;
    f->fim=0;
        return f;
}

int filavazia(Fila *f){
if(f->inicio==f->fim)
    return 1;
    return 0;


}

int main(){
    char str[20];
    char * pch;
    char a[30];
    int num=0;
    Fila *f= cria_fila();
    printf("Digite os comandos:\n\nPush X-Para enfileirar X\n\nPop-Para desenfileirar\n\nF-Para finalizar o programa\n\n");
    while(a!="F"){
    scanf("%s", &str);
    if(strcmp(str,"push")==0){
            scanf("%d", &num);
        push(f,num );
    printf("%d foi enfileirado\n",num );
    }

    else if(strcmp(str,"pop")==0){
            if(filavazia(f)==1) printf("Fila vazia!\n");
    else
        printf("%d foi desenfileirado\n",pop(f));
    }

    else if(strcmp(str,"F")==0){
        break;
    }
    }
return 0;
}
