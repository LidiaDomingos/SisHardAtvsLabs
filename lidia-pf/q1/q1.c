// Leia o README antes de iniciar este exercício!


// inclua as bibliotecas necessárias
// #include ...
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

sem_t sem1, sem2, sem3, sem4;

void *thread1(void *_arg) {
    //primeiro RDV
    sem_wait(&sem4);

    //segundo RDV
    sem_post(&sem1);
    sem_wait(&sem2);
    sem_wait(&sem3);

    printf("A\n");
    return NULL;
}

void *thread2(void *_arg) {
    
    //primeiro RDV
    sem_wait(&sem4);
    printf("B\n");

    //segundo RDV
    sem_post(&sem2);
    sem_wait(&sem3);
    sem_post(&sem2); 
    printf("C\n");

    return NULL;
}

void *thread3(void *_arg) {
    //primeiro RDV
    sem_wait(&sem4);

    //segundo RDV
    printf("D\n");
    sem_post(&sem3);
    sem_wait(&sem2);
    sem_post(&sem3); 

    printf("E\n");

    return NULL;
}

void *thread4(void *_arg) {

    printf("F\n");
    //primeiro RDV
    sem_post(&sem4);
    sem_post(&sem4);
    sem_post(&sem4);

    return NULL;
}

int main(int argc, char *argv[]) {

    // Crie TODAS as threads. Voce deve utilizar semaforos para sincronizacao.
    sem_init(&sem1, 0, 0);
    sem_init(&sem2, 0, 0);
    sem_init(&sem3, 0, 0);
    sem_init(&sem4, 0, 0);

    pthread_t *tid = malloc(4 * sizeof(pthread_t));

    int erro1 = pthread_create(&tid[0], NULL, thread1, NULL);
    int erro2 = pthread_create(&tid[1], NULL, thread2, NULL);
    int erro3 = pthread_create(&tid[2], NULL, thread3, NULL);
    int erro4 = pthread_create(&tid[3], NULL, thread4, NULL);

    // Espere por TODAS as threads
    for (int i = 0; i < 4;i++) {
        pthread_join(tid[i], NULL);
    }

    sem_destroy(&sem1);
    sem_destroy(&sem2);
    sem_destroy(&sem3);
    sem_destroy(&sem4);
    return 0;
}