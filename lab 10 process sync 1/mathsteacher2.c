#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int readcount = 0, i = 0, j = 0, k = 0, arr[5];
sem_t teach; //, mutex;
pthread_mutex_t mutex;

void *teacher()
{
    j = 0;
    sem_wait(&teach);
    printf("Teacher entry to critical section.");
    printf("Data by teacher:");
    srand(time(NULL));
    int x = rand() % 5;
    for (i = 0; i < x; i++)
    {
        arr[j] = rand() % 10;
        printf("%d ", arr[j]);
        j++;
    }
    sleep(1);
    sem_post(&teach);
    printf("Teacher exit to critical section.\n");
}
void *student()
{
    // printf("student");
    pthread_mutex_lock(&mutex);
    readcount++;
    if (readcount == 1)
    {
        sem_wait(&teach);
    }
    pthread_mutex_unlock(&mutex);
    printf("Student entry to critical section.");
    printf("Data displyed:");
    srand(time(NULL));
    int x = rand() % 6;
    for (i = 0; i < x; i++)
    {
        printf("%d ", arr[i]);
    }
    // printf("\n");
    sleep(1);
    pthread_mutex_lock(&mutex);
    printf("Student exit critical section.\n");
    readcount--;
    if (readcount == 0)
    {
        sem_post(&teach);
    }
    pthread_mutex_unlock(&mutex);
}
int main()
{
    // sem_init(&mutex, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    sem_init(&teach, 0, 1);
    pthread_t t[10];
    for (int i = 0; i < 20; i++)
    {
        srand(time(NULL));
        int x = rand() % 20;
        if (x % 4 == 0)
        {
            pthread_create(&t[0], NULL, teacher, NULL);
            sleep(2);
        }
        // printf("hello");
        pthread_create(&t[1], NULL, student, NULL);
        sleep(2);
        pthread_join(t[0], NULL);
        pthread_join(t[1], NULL);
    }
    pthread_mutex_destroy(&mutex);
    sem_destroy(&teach);
    return 0;
}
