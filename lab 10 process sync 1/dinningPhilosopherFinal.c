#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdbool.h>
bool state[5];
int forks[5], count = 0;
sem_t semaphore_1;
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
    sem_wait(&semaphore_1);
    if (state[i] != false && forks[i] != 0)
    {
        forks[i] = 0;
        sem_post(&semaphore_1);
        return 1;
    }
    else
    {
        sem_post(&semaphore_1);
        return 0;
    }
}
void putforks(int i, int k)
{
    sem_wait(&semaphore_1);
    state[i] = true;
    forks[i] = 1;
    forks[k] = 1;
    printf("The philospher %d finished eating\n", i + 1);
    sem_post(&semaphore_1);
}
void philosopher(int i)
{
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
                philosopher(k - 1);
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
    sem_init(&semaphore_1, 0, 1);
    for (i = 0; i < 5; i++)
    {
        state[i] = true;
        forks[i] = 1;
    }
    int n;
    printf("Enter no.of requests:\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the philosopher number:\n");
        scanf("%d", &j);
        i = j - 1;
        philosopher(i);
    }
}