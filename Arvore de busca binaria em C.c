#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int chave;
    void *cont;
    struct nodo *esq,*dir;

} nodo;

int busca(nodo * raiz, int x)
{
    if(raiz==NULL)
        return 0;

    if(x==raiz->chave)
        return 1;


    if(x<raiz->chave)
        return busca(raiz->esq, x);

    if(x>raiz->chave)
        return busca(raiz->dir, x);

}


nodo *cria_arv()
{
    return NULL;
}


nodo *insere(nodo *raiz, int x)
{
    if(raiz==NULL)
    {
        nodo *novo= (nodo*) malloc(sizeof(nodo));
        novo->chave= x;
        novo->dir= NULL;
        novo->esq= NULL;
        return novo;
    }
    if(x<raiz->chave)
        raiz->esq= insere(raiz->esq, x);

    else if(x>raiz->chave)
        raiz->dir= insere(raiz->dir, x);

    return raiz;
}
void imprime(nodo* raiz)
{
    nodo* aux = raiz;
    printf("%d ",aux->chave);

}

nodo *pre_ordem(nodo *raiz)
{
    if(raiz==NULL) return 0;
    imprime(raiz);
    pre_ordem(raiz->esq);
    pre_ordem(raiz->dir);

}

nodo *in_order(nodo *raiz)
{
    if(raiz==NULL) return 0;
    in_order(raiz->esq);
    imprime(raiz);
    in_order(raiz->dir);

}

int main()
{
    int a=0;
    int i;
    nodo *arv= cria_arv();
    printf("digite os numeros que serao colocados na BST\n");
    while(a!=-1)
    {
        scanf("%d", &a);
        if(a!=-1)
        {
            arv=insere(arv, a);
        }
    }
    a=0;
    printf("digite os numeros que quer procurar\n");
    while(a!=-1)
    {
        scanf("%d", &a);
        if(a!=-1)
        {
            i=busca(arv,a);
            if(i==0)
                printf("%d nao encontrado\n", a);
            if(i==1)
                printf("%d encontrado\n", a);

        }

    }

    pre_ordem(arv);
    printf("\n");
    in_order(arv);
    return 0;
}
