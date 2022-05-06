#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int v1[2000000000], v2[2000000000];
int tam = 0;


int comparar(const void* x, const void* y){
    if(*(int *)x > *(int *)y) return 1;
    if(*(int *)x < *(int *)y) return -1;
    return 0;
}

void *ordenaThread(void *vetor){
    int *vetorOrdenar=(int *)vetor;
    qsort(vetorOrdenar, tam, sizeof(int), comparar);
}

int main(void){
    int n;
    int diferente = 0;
    pthread_t thread1, thread2;
    scanf("%d", &n);
    tam = n;
    
    for(int i = 0; i < n; i++){
        scanf("%d", &v1[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &v2[i]);
    }

    pthread_create(&thread1, NULL, ordenaThread, (void *)&v1);
    pthread_create(&thread2, NULL, ordenaThread, (void *)&v2);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    for(int i = 0; i < n; i++){
        if(v1[i] != v2[i]){
        diferente = 1;
        }
    }

    if(diferente == 0){
        printf("Mesmos elementos\n");
    }else{
        printf("Diferentes\n");
    }

    return 0;
}