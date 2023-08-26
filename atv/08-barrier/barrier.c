#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

int num_barrier = 0;
sem_t sem_barrier;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_barreira(void *arg) {
    pthread_mutex_lock(&mutex);
    printf("Antes da barreira %d\n", num_barrier);
    pthread_mutex_unlock(&mutex);

    if (num_barrier > 2){
        sem_post(&sem_barrier);
        sem_post(&sem_barrier);
        sem_post(&sem_barrier);
    }
    else{
        pthread_mutex_lock(&mutex);
        num_barrier++;
        pthread_mutex_unlock(&mutex);

        sem_wait(&sem_barrier);
    }
    // TODO: implemente a barreira aqui
    pthread_mutex_lock(&mutex);
    printf("Depois da barreira %d\n", num_barrier);
    pthread_mutex_unlock(&mutex);
    
    return NULL;
}

int main() {
    pthread_mutex_init(&mutex, NULL);
    sem_init(&sem_barrier, 0, 0);
    // TODO: crie 4 threads rodando o código acima
    pthread_t *tid = malloc(4 * sizeof(pthread_t));
    for (int i = 0; i < 4; i++) {
        int error = pthread_create(&tid[i], NULL, thread_barreira, NULL);
    }    

    // TODO: espere por elas
    for (int i = 0; i < 4;i++) {
        pthread_join(tid[i], NULL);
    }

    sem_destroy(&sem_barrier);
    pthread_mutex_destroy(&mutex);
    return 0;
}
