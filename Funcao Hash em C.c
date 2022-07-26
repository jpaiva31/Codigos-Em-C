#include <stdio.h>     //Função hash
#include <string.h>
#include <stdlib.h>
#include <math.h>

int hash(char *palavra)  //a função hash recebe um vetor, de forma que a gente consiga manusear letra por letra
{
    unsigned long aux=0, soma=0;

    for(aux=0; aux<strlen(palavra); aux++) // strlen serve pra saber o numero de letras da palavra
    {
        soma+= (palavra[aux]-'A')*pow(26,aux);  //esse palavra[aux] - 'A', devido a tabela ASCII, faz com que o resultado dessa subtração seja a posição da letra palavra[aux] do alfabeto
    }
    return soma%11;     //retorna o resto da soma
}
int main()
{
    int n=0,j=0;
    char vetor[100]; //nesse vetor que serao armazenadas as palavras de ate 100 letras
    int chave[11]= {0}; //criei a chave de 11 posições, como pedido no exercicio

    printf("Digite a quantidade de palavras que serao colocadas na tabela Hash\n");
    scanf("%d", &n); //scanf pra saber quantas palavras o usuario vai digitar
    printf("Digite as %d palavras que vao para a tabela:\n",n);
    for(int i=0; i<n; i++)
    {
        scanf("%s", &vetor); //escaneia as palavras e manda pro vetor
        j=hash(vetor); //coloca o valor de J como o numero da chave que a palavra vai ficar
        chave[j]++; //sempre que uma palavra for pra uma chave, incremento 1 nessa chave pra saber quantas palavras foram pra la
    }

    for(int i=0; i<11; i++) //esse while é pra imprimir cada uma das chaves e dizer quantas palavras foram mandadas pra la
    {
        printf("%d:%d chave(s)\n",i,chave[i]);
    }


    return 0;
}
