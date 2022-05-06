#include <stdio.h>
#include <stdlib.h>

typedef struct fila_prioridade{
    long long int qtd;
    struct ItemFP dados[262000];
}FilaPrio;

typedef struct ItemFP
{
    long long int x;
    long long int y;
    long long int prio;
}ItemFP;

typedef struct Item
{
    long long int x;
    long long int y;
}Item;

FilaPrio* cria_FilaPrio(){
    FilaPrio *fp;
    fp = (FilaPrio*) malloc(sizeof(struct fila_prioridade));
    if(fp != NULL)
        fp->qtd = 0;
    return fp;
}


Item* consulta_FilaPrio(FilaPrio* fp){
    Item *retorno = (Item *) malloc(sizeof(struct Item));
    retorno->x = fp->dados[0].x;
    retorno->y = fp->dados[0].y;
    return retorno;
}


void libera_FilaPrio(FilaPrio* fp){
    free(fp);
}

void promoverElemento(FilaPrio* fp, long long int filho){
    long long int pai;
    struct ItemFP temp;
    pai = (filho - 1) / 2;
    while(filho > 0 && fp->dados[pai].prio <= fp->dados[filho].prio){
        temp = fp->dados[filho];
        fp->dados[filho] = fp->dados[pai];
        fp->dados[pai] = temp;

        filho = pai;
        pai = (pai - 1) / 2;
    }
}

int insere_FilaPrio(FilaPrio* fp, long long int xis,long long int yps, long long int prioridade){
    if(fp == NULL)
        return 0;
    if(fp->qtd == MAX)//fila cheia
        return 0;
    /* insere na primeira posi��o livre */
    fp->dados[fp->qtd].x = xis;
    fp->dados[fp->qtd].y = yps;
    fp->dados[fp->qtd].prio = prioridade;
    /* desloca elemento para posi��o correta */
    promoverElemento(fp, fp->qtd);
    /* incrementa n�mero de elementos no heap */
    fp->qtd++;
    return 1;
}

void rebaixarElemento(FilaPrio* fp, long long int pai){
    struct ItemFP temp;
    long long int filho = 2 * pai + 1;
    while(filho < fp->qtd){

        if(filho < fp->qtd-1) /* verifica se tem 2 filhos */
            if(fp->dados[filho].prio < fp->dados[filho+1].prio)
                filho++; /*filho aponta para filho menor */

        if(fp->dados[pai].prio >= fp->dados[filho].prio)
            break; /* encontrou lugar */

        temp = fp->dados[pai];
        fp->dados[pai] = fp->dados[filho];
        fp->dados[filho] = temp;

        pai = filho;
        filho = 2 * pai + 1;
    }
}

Item* remove_FilaPrio(FilaPrio* fp){
    
    Item *retorno = (Item *) malloc(sizeof(struct Item));
    retorno->x = fp->dados[0].x;
    retorno->y = fp->dados[0].y;

    fp->qtd--;
    fp->dados[0] = fp->dados[fp->qtd];
    rebaixarElemento(fp,0);

    return retorno;
}

long long int tamanho_FilaPrio(FilaPrio* fp){
    if(fp == NULL)
        return -1;
    else
        return fp->qtd;
}

// int estaCheia_FilaPrio(FilaPrio* fp){
//     if(fp == NULL)
//         return -1;
//     return (fp->qtd == MAX);
// }

int estaVazia_FilaPrio(FilaPrio* fp){
    if(fp == NULL)
        return -1;
    return (fp->qtd == 0);
}

void imprime_FilaPrio(FilaPrio* fp){
    if(fp == NULL)
        return;
    long long int i;
    for(i=0; i < fp->qtd ; i++){
        printf("%lld) Prio: %lld \tx: %lld \ty: %lld\n", i, fp->dados[i].prio,fp->dados[i].x, fp->dados[i].y);
    }
}

{

}