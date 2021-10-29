#include <stdio.h>

int buscaVetor(int *vetor, int num, int dado)
{
    for(int i = 0; i < num; i++)
    {
        
        if(vetor[i] == dado)
        {
            return 1;
        }
    }
    return 0;
}


int main(void)
{
    int n, q, teste;

    scanf("%d", &n);

    int *vetor = (int *) malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }
    for(int i = 0; i < 2; i++)
    {
        int contador_vetor = 0, contador_in_out = 0, retorno = 0, page_fault = 1, contador_in_out2 = 0;
        scanf("%d", &q);
        int *vetor_in_out = (int *) malloc(sizeof(int) * q);
        vetor_in_out[contador_in_out++] = vetor[0];
        
        for(int i = 1; i < n; i++)
        {
            if(contador_in_out < q)
            {
                retorno = buscaVetor(vetor_in_out, contador_in_out, vetor[i]);
                
                if(retorno == 0)
                {
                    vetor_in_out[contador_in_out] = vetor[i];
                    contador_in_out++;
                    page_fault++;
                }
            }
            else
            {
                // for(int i = 0; i < contador_in_out; i++)
                // {
                //     printf("%d ", vetor_in_out[i]);
                // }
                retorno = buscaVetor(vetor_in_out, q, vetor[i]);
                if(retorno == 0)
                {
                    if(contador_in_out2 >= q) contador_in_out2 = 0;
                    vetor_in_out[contador_in_out2++] = vetor[i];
                    page_fault++;
                }
            }
        }
        printf("%d %d\n", q, page_fault);
        
    }
    
    return 0;
}