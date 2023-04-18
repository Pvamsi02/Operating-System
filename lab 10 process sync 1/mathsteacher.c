#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
int readcount = 0,  i = 0, j = 0, k = 0, arr[20];
sem_t teach;//, mutex;
pthread_mutex_t mutex;

void *teacher()
{
    j=0;
    sem_wait(&teach);
    printf("Teacher entry to critical section.");
    printf("Data by teacher:");
    for (i = 0; i < 5; i++)
    {
        arr[j++] = rand() % 100;
        printf("%d ", arr[j - 1]);
    }
    sleep(1);
    sem_post(&teach);
    printf("\nTeacher exit to critical section.\n");
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
    for (i = 0; i < 5; i++)
    {
        printf("%d ", arr[k++]);
    }
    //printf("\n");
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
    //sem_init(&mutex, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    sem_init(&teach, 0, 1);
    pthread_t t[10];
    for (int i = 0; i < 5; i++)
    {
        pthread_create(&t[0], NULL, teacher, NULL);
        sleep(2);
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
