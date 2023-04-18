#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdbool.h>
bool state[5];
int forks[5], count = 0;
sem_t mutex;
int think(int i)
{
    state[i] = true;
    printf("The philosopher %d is thinking...\n", i + 1);
}
int eat(int i)
{
    state[i] = false;
    printf("Philospher %d is eating...\n", i + 1);
}
int takeforks(int i)
{
    sem_wait(&mutex);
    if (state[i] != false && forks[i] != 0)
    {
        forks[i] = 0;
        sem_post(&mutex);
        return 1;
    }
    else
    {
        sem_post(&mutex);
        return 0;
    }
}
void putforks(int i, int k)
{
    sem_wait(&mutex);
    state[i] = true;
    forks[i] = 1;
    forks[k] = 1;
    printf("The philospher %d finished eating\n", i + 1);
    sem_post(&mutex);
}
void philosopher(void *p)
{
    int i = *(int *)p;
    int k;
    while (1)
    {
        if (i > 4)
        {
            printf("No philosopher availalbe:\n");
            break;
        }
        else
        {
            think(i);
            int a = takeforks(i);
            int b = takeforks((i + 1) % 5);
            if (b == 1)
            {
                if (a == 1)
                {
                    eat(i);
                }
                else
                {
                    printf("The philospher %d cannot eat due to less availability of forks\n", i + 1);
                    sleep(2);
                }
            }
            else
            {
                printf("The philospher %d cannot eat due to less availability of forks\n", i + 1);
                break;
            }
            if (count == 0)
            {
                printf("Request is made by the philosopher:\n");
                scanf("%d", &k);
                int t = k - 1;
                philosopher((void *)&t);
                count = count + 1;
            }
            putforks(i, (i + 1) % 5);
            break;
        }
    }
}
int main()
{
    int j, i;
    pthread_t t;
    sem_init(&mutex, 0, 1);
    for (i = 0; i < 5; i++)
    {
        state[i] = true;
        forks[i] = 1;
    }
    printf("Enter the philosopher number:\n");
    scanf("%d", &j);
    i = j - 1;
    pthread_create(&t, NULL, (void *)philosopher, (void *)&i);
    pthread_join(t, NULL);
    sem_destroy(&mutex);
}