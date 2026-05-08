#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5  // Number of philosophers

sem_t chopsticks[N];

void *philosopher(void *num) {
    int id = *(int *)num;

    while (1) {
        printf("Philosopher %d is thinking...\n", id);
        sleep(1);

        // Pick up chopsticks
        sem_wait(&chopsticks[id]);
        sem_wait(&chopsticks[(id + 1) % N]);

        printf("Philosopher %d is eating...\n", id);
        sleep(2);

        // Put down chopsticks
        sem_post(&chopsticks[id]);
        sem_post(&chopsticks[(id + 1) % N]);

        printf("Philosopher %d finished eating.\n", id);
    }
}

int main() {
    pthread_t tid[N];
    int ids[N];

    for (int i = 0; i < N; i++) {
        sem_init(&chopsticks[i], 0, 1);
    }

    for (int i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&tid[i], NULL, philosopher, &ids[i]);
    }

    for (int i = 0; i < N; i++) {
        pthread_join(tid[i], NULL);
    }

    return 0;
}
