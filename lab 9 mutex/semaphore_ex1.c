#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
pthread_mutex_t mutex;
sem_t writeMutex;
int readCount = 0;
int value = 42;
void *Reader(void *i)
{

    int *n = (int *)i;
    pthread_mutex_lock(&mutex);
    readCount++;
    if (readCount > 0)
        sem_wait(&writeMutex);

    pthread_mutex_unlock(&mutex);

    printf("Reader %d reads %d value\n", *n, value);

    pthread_mutex_lock(&mutex);
    readCount--;
    if (readCount == 0)
        sem_post(&writeMutex);

    pthread_mutex_unlock(&mutex);
}
void *WriterInc(void *i)
{
    int *n = (int *)i;
    sem_wait(&writeMutex);
    value = value - 1;
    printf("Writer %d modifies to %d value\n", *n, value);
    sem_post(&writeMutex);
}
void *WriterDec(void *i)
{
    int *n = (int *)i;
    sem_wait(&writeMutex);
    value = value + 1;
    printf("Writer %d modifies to %d value\n", *n, value);
    sem_post(&writeMutex);
}
int main()
{

    pthread_mutex_init(&mutex, NULL);
    sem_init(&writeMutex, 0, 1);
    pthread_t readers[2], writers[2];

    for (int t = 1, i = 0; i < 2; i++, t++)
    {
        pthread_create(&readers[i], NULL, (void *)Reader, (void *)&t);
        sleep(1);

        if (i % 2 == 0)
            pthread_create(&writers[i], NULL, (void *)WriterInc, (void *)&t);
        else
            pthread_create(&writers[i], NULL, (void *)WriterDec, (void *)&t);

        sleep(1);
    }
    for (int i = 0; i < 2; i++)
    {
        pthread_join(readers[i], NULL);
        pthread_join(writers[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    sem_destroy(&writeMutex);
    return 0;
}