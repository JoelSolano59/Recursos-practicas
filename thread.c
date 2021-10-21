#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define NUM_THREADS 10
int balance;

void *printHola(void *arg)
{
    int localBalance = balance;
    localBalance += 100;
    balance = localBalance;
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    balance = 0;
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, printHola, NULL);
    }
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }
    printf("Balance: %d", balance);
    pthread_exit(NULL);
}