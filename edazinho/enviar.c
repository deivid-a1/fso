#include <stdio.h>
#include <stdlib.h>
#define MAX 50000

// void libera_FilaPrio(FilaPrio* fp);
// int consulta_FilaPrio(FilaPrio* fp, char* nome);
// int insere_FilaPrio(FilaPrio* fp, long int x, long int y, long int  prioridade);
// int remove_FilaPrio(FilaPrio* fp);
// int tamanho_FilaPrio(FilaPrio* fp);
// int estaCheia_FilaPrio(FilaPrio* fp);
// int estaVazia_FilaPrio(FilaPrio* fp);
// void imprime_FilaPrio(FilaPrio* fp);
long long int flag = 0;

typedef struct Item
{
    long long int x;
    long long int y;
}Item;

typedef struct vetSond
{
    Item *vet;
    long long int tam;
}vetSond;

typedef struct ItemFP
{
    long long int x;
    long long int y;
    long long int prio;
}ItemFP;

typedef struct fila_prioridade{
    long long int qtd;
    struct ItemFP dados[MAX];
}FilaPrio;

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
    rebaixarElemento(fp, 0);

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

Item* zeraPosicao(Item *posicao)
{
    Item *util = (Item *) malloc(sizeof(struct Item));
    util->x = posicao->x * -1; // se a referencia for negativa -> soma, se não subtrai; 
    util->y = posicao->y * -1; // se a referencia for positiva -> subtrai, se não soma;
    
    return util;
}

Item* transforma(Item *posicao, Item *referencia)
{
    Item *util = (Item *) malloc(sizeof(struct Item));

    util->x = posicao->x + referencia->x + 250;
    util->y = posicao->y + referencia->y + 250;
    // printf("Transformação %ld %ld\n", util->x, util->y);
    return util;
}
// 100 > -100
// -100 > 100

// 130 > 130 -100 = 30 + -100*-1  = 130
// 150 > 150 - 100 = 50 + -100*-1
                    
// -70 > -70 + 100 = 30 + 100*-1 = -70
// -30> -30 + 100 = 70 + 100*-1 = -30 
typedef struct vetChar
{
    char y[1000];
}vetChar;

long long int getbackItem(long long int dado, long long int referencia)
{
    return (dado + (referencia*-1) - 250);
}

void gerenciaEdazinho(Item *pilha, long long int tamPilha, Item *posicaoCerta, vetChar *hashx, long long int qtdSondagem, Item *_referencia)
{
    // printf("posicao passada %ld %ld\n", posicaoCerta->x, posicaoCerta->y);
    pilha[tamPilha].x=posicaoCerta->x;
    pilha[tamPilha].y=posicaoCerta->y;
    

    if(flag != 0) 
    {
        printf("dominar %lld %lld\n", getbackItem(posicaoCerta->x, _referencia->x), getbackItem(posicaoCerta->y, _referencia->y));
        fflush(stdout);
        scanf(" %*s %*lld");
    }
    else{
        flag = 1;
    }
    // printf("%ld %ld\n", pilha[tamPilha].x, pilha[tamPilha].y);
    // printf("%ld %ld\n", posicaoCerta->x, posicaoCerta->y);
    
    // dominacao P
    hashx[posicaoCerta->x].y[posicaoCerta->y] = 1; //quando for EDAzinho, marca na hash = 1;
}
// typedef struct vetor
// {
//     Item *v;
//     long int tamanho;
// }vetor;

// Item* transformaDeVolta(Item *dado, Item *referencia)
// {
//     if(referencia->x > 0)
//     {
//         dado->x = dado->x + (referencia->x*-1);
//     }
//     else dado->x = dado->x - referencia->x;
// }



vetSond *procura_items_sondar(Item *pilha, long long int tamanhoPilha, long long int qtdSondagem, vetChar *hashx, Item *_referencia)
{
    Item *vetSondar = (Item *) malloc(sizeof(Item) * qtdSondagem);
    vetSond *vetRetorno = (vetSond *) malloc(sizeof(struct vetSond));
    
    long long int tamPilha = tamanhoPilha, tamVetor = 0;

    
    for(long long int i = 0; i < tamPilha; tamPilha--)
    {
    // printf("%ld %ld != %ld %ld\n", pilha[tamPilha-1].x, pilha[tamPilha-1].y, pilha[tamPilha].x, pilha[tamPilha].y);

        //esquerda
        if (pilha[tamPilha-1].y - 1 >= 0)
        {
            if (hashx[pilha[tamPilha-1].x + 0].y[pilha[tamPilha-1].y - 1] == 0) 
            {
                hashx[pilha[tamPilha-1].x + 0].y[pilha[tamPilha-1].y - 1] = 2;
                vetSondar[tamVetor].x = pilha[tamPilha-1].x + 0; vetSondar[tamVetor++].y = pilha[tamPilha-1].y - 1;
                if(tamVetor == qtdSondagem)
                {
                    vetRetorno->vet = vetSondar;
                    vetRetorno->tam = tamVetor;
                    return vetRetorno;
                }
            }
        }

        //cima esquerda(diagonal superior esquerda) //testado lixo de mais
        if ((pilha[tamPilha-1].x - 1 >= 0) && (pilha[tamPilha-1].y - 1 >= 0))
        {
            if (hashx[pilha[tamPilha-1].x - 1].y[pilha[tamPilha-1].y - 1] == 0)
            {
                hashx[pilha[tamPilha-1].x - 1].y[pilha[tamPilha-1].y - 1] = 2;
                vetSondar[tamVetor].x = pilha[tamPilha-1].x - 1; vetSondar[tamVetor++].y = pilha[tamPilha-1].y - 1;
                if(tamVetor == qtdSondagem)
                {
                    vetRetorno->vet = vetSondar;
                    vetRetorno->tam = tamVetor;
                    return vetRetorno;
                }
            }
        }

         //cima
        if (pilha[tamPilha-1].x - 1 >= 0)//testado lixo
        {
            if(hashx[pilha[tamPilha-1].x - 1].y[pilha[tamPilha-1].y + 0] == 0)
            {
                hashx[pilha[tamPilha-1].x - 1].y[pilha[tamPilha-1].y + 0] = 2;
                vetSondar[tamVetor].x = pilha[tamPilha-1].x - 1; vetSondar[tamVetor++].y = pilha[tamPilha-1].y + 0;
                if(tamVetor == qtdSondagem)
                {
                    vetRetorno->vet = vetSondar;
                    vetRetorno->tam = tamVetor;
                    return vetRetorno;
                }
            }
        }

        //baixo
        if(hashx[pilha[tamPilha-1].x + 1].y[pilha[tamPilha-1].y + 0] == 0) // testado lixo
        {
            hashx[pilha[tamPilha-1].x + 1].y[pilha[tamPilha-1].y + 0] = 2;
            vetSondar[tamVetor].x = pilha[tamPilha-1].x + 1; vetSondar[tamVetor++].y = pilha[tamPilha-1].y + 0;
            if(tamVetor == qtdSondagem)
            {
                vetRetorno->vet = vetSondar;
                vetRetorno->tam = tamVetor;
                return vetRetorno;
            }
        }


        //direita
        
        if(hashx[pilha[tamPilha-1].x + 0].y[pilha[tamPilha-1].y + 1] == 0) //testado e foi o melhor
        {
            hashx[pilha[tamPilha-1].x + 0].y[pilha[tamPilha-1].y + 1] = 2;
            vetSondar[tamVetor].x = pilha[tamPilha-1].x + 0; vetSondar[tamVetor++].y = pilha[tamPilha-1].y + 1;
            
            if(tamVetor == qtdSondagem){
                vetRetorno->vet = vetSondar;
                vetRetorno->tam = tamVetor;
                return vetRetorno;
            }   
        }

        //direita cima (diagonal superior direita)
        if ((pilha[tamPilha-1].x - 1 >= 0)) //testado
        {
            if((hashx[pilha[tamPilha-1].x - 1].y[pilha[tamPilha-1].y + 1] == 0))
            {
                hashx[pilha[tamPilha-1].x - 1].y[pilha[tamPilha-1].y + 1] = 2;
                vetSondar[tamVetor].x = pilha[tamPilha-1].x + -1; vetSondar[tamVetor++].y = pilha[tamPilha-1].y + 1;
                if(tamVetor == qtdSondagem)
                {
                    vetRetorno->vet = vetSondar;
                    vetRetorno->tam = tamVetor;
                    return vetRetorno;
                }
            }
        }
        //diagonal inferior direita
        if(hashx[pilha[tamPilha-1].x + 1].y[pilha[tamPilha-1].y + 1] == 0) //testado
        {
            hashx[pilha[tamPilha-1].x + 1].y[pilha[tamPilha-1].y + 1] = 2;
            vetSondar[tamVetor].x = pilha[tamPilha-1].x + 1; vetSondar[tamVetor++].y = pilha[tamPilha-1].y + 1;
            if(tamVetor == qtdSondagem){
                vetRetorno->vet = vetSondar;
                vetRetorno->tam = tamVetor;
                return vetRetorno;
            }
        }
        
        
        //baixo esquerda (diagonal inferior esquerda)
        if ((pilha[tamPilha-1].y - 1 >= 0))
        {
            if(hashx[pilha[tamPilha-1].x + 1].y[pilha[tamPilha-1].y - 1] == 0)
            {
                hashx[pilha[tamPilha-1].x + 1].y[pilha[tamPilha-1].y - 1] = 2;
                vetSondar[tamVetor].x = pilha[tamPilha-1].x + 1; vetSondar[tamVetor++].y = pilha[tamPilha-1].y - 1;
                if(tamVetor == qtdSondagem)
                {
                    vetRetorno->vet = vetSondar;
                    vetRetorno->tam = tamVetor;
                    return vetRetorno;
                }
            }
        }
    }
    vetRetorno->vet = vetSondar;
    vetRetorno->tam = tamVetor;
    return vetRetorno;
}

void sondar(vetSond *vetorSondagem, long long int qtdSondagem, Item *_referenciaCerta, FilaPrio *fp) //heap)
{  
    long long int xis, yps, prio;
    char util[20];
    for(long long int i = 0; i < vetorSondagem->tam; i++)
    {
        // printf("sondar programa %ld %ld\n", vetorSondagem[i].x, vetorSondagem[i].y);
        //sondagem -5270 22141
        printf("sondar %lld %lld\n", getbackItem(vetorSondagem->vet[i].x, _referenciaCerta->x), getbackItem(vetorSondagem->vet[i].y, _referenciaCerta->y));
        fflush(stdout);
        scanf(" %s %lld %lld %lld", util, &xis, &yps, &prio);
        insere_FilaPrio(fp, xis, yps, prio);
    }
}

int main(void)
{
    vetSond *vetorSondagem;
    
    Item *pilha = (Item *) malloc(sizeof(struct Item) * 7500);
    Item *posicao = (Item *) malloc(sizeof(struct Item));
    Item *_referenciaCerta = (Item *) malloc(sizeof(struct Item));
    Item *posicaoCerta;
    
    FilaPrio *fp;

    fp = cria_FilaPrio();
    
    long long int turnos, tamPilha = 0, qtdSondagem = 0;

    vetChar *hashx = (vetChar *) calloc(1000,sizeof(vetChar));

    fflush(stdout);
    scanf("%lld %lld %*lld %lld", &posicao->x, &posicao->y, &turnos);
    

    _referenciaCerta = zeraPosicao(posicao);
    // printf("referencia certa de x %ld  de y %ld\n", _referenciaCerta->x, _referenciaCerta->y);
    posicaoCerta = transforma(posicao, _referenciaCerta);
    // printf("posicao certa de x %ld  de y %ld\n", posicaoCerta->x, posicaoCerta->y);
    
    gerenciaEdazinho(pilha, tamPilha, posicaoCerta, hashx, qtdSondagem, _referenciaCerta); tamPilha++; qtdSondagem++;
    
    // printf("pilha de 0 %ld %ld\n", pilha[tamPilha - 1].x, pilha[tamPilha - 1].y);
    // printf("hash 0 0 %ld\n", hashx[pilha[tamPilha-1].x].y[pilha[tamPilha-1].y]);

    vetorSondagem = procura_items_sondar(pilha, tamPilha, qtdSondagem, hashx, _referenciaCerta);


    sondar(vetorSondagem, qtdSondagem, _referenciaCerta, fp); //heap)

    free(vetorSondagem);
    // imprime_FilaPrio(fp);
    // for(int x = 0; x < 10; x ++)
    // {
    //     for(int y = 0; y < 20; y++)
    //     {
    //         if(y == 19) printf("%d\n", hashx[x].y[y]);
    //         else printf("%ld ", hashx[x].y[y]);
    //     }
    // }

    printf("fimturno\n");    
    fflush(stdout);

    Item *heap = (Item *) malloc(sizeof(struct Item));

    int flag2 = 0;
    for(long long int i = 1; i < turnos; i++)
    {
        
        // if(fp->dados[0].prio > -19)
        // {
            heap = remove_FilaPrio(fp);
            gerenciaEdazinho(pilha, tamPilha, transforma(heap, _referenciaCerta), hashx, qtdSondagem, _referenciaCerta);
            flag2 = 1;
        // }
        // else
        // {
        //     flag2 = 0;
        // }
        // printf("dominar edazinho %ld %ld", pilha[tamPilha].x, pilha[tamPilha].y);
        // printf("Qtd de sondagem do round %ld\n", qtdSondagem);

        
        vetorSondagem = procura_items_sondar(pilha, tamPilha, qtdSondagem, hashx, _referenciaCerta);
        
        // for(int k = 0; k<vetorSondagem->tam; k++)
        // {
        //     printf("v %ld %ld\n", vetorSondagem->vet[k].x, vetorSondagem->vet[k].y);
        // }

        sondar(vetorSondagem, qtdSondagem, _referenciaCerta, fp);

        if(flag2 == 1)
        {
            tamPilha++;
            qtdSondagem++;
        }
    
        
        // for(int k = 0; k<tamPilha; k++)
        // {
        //     printf("PILHA %ld %ld\n", pilha[k - 1].x, pilha[k - 1].y);=
        // }

        // for(int x = 490; x < 510; x ++)
        // {
        //     for(int y = 490; y < 510; y++)
        //     {
        //         if(y == 509) printf("%d\n", hashx[x].y[y]);
        //         else printf("%ld ", hashx[x].y[y]);
        //     }
        // }
        // imprime_FilaPrio(fp);


        printf("fimturno\n");    
        fflush(stdout);
    }
    return 0;
}

