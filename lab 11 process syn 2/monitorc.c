#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define N 5
typedef enum
{
    THINKING,
    HUNGRY,
    EATING
} state_t;
pthread_mutex_t monitor_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t philo_cond[N] = {PTHREAD_COND_INITIALIZER};
state_t state[N] = {THINKING};
int philo_id[N] = {0, 1, 2, 3, 4};
void pickup_forks(int philo_id)
{
    pthread_mutex_lock(&monitor_mutex);
    state[philo_id] = HUNGRY;
    test(philo_id);
    if (state[philo_id] != EATING)
    {
        pthread_cond_wait(&philo_cond[philo_id], &monitor_mutex);
    }
    pthread_mutex_unlock(&monitor_mutex);
}
void putdown_forks(int philo_id)
{
    pthread_mutex_lock(&monitor_mutex);
    state[philo_id] = THINKING;
    test((philo_id + N - 1) % N);
    test((philo_id + 1) % N);
    pthread_mutex_unlock(&monitor_mutex);
}
void test(int philo_id)
{
    if (state[(philo_id + N - 1) % N] != EATING &&
        state[philo_id] == HUNGRY &&
        state[(philo_id + 1) % N] != EATING)
    {
        state[philo_id] = EATING;
        pthread_cond_signal(&philo_cond[philo_id]);
    }
}
void *philosopher(void *arg)
{
    int *philo_id = (int *)arg;
    while (1)
    {
        printf("Philosopher %d is thinking...\n", *philo_id);
        sleep(1);
        printf("Philosopher %d is hungry...\n", *philo_id);
        pickup_forks(*philo_id);
        printf("Philosopher %d is eating...\n", *philo_id);
        sleep(1);
        putdown_forks(*philo_id);
    }
}
int main()
{
    pthread_t philo_threads[N];
    int i;
    for (i = 0; i < N; i++)
    {
        pthread_create(&philo_threads[i], NULL, philosopher, &philo_id[i]);
    }
    for (i = 0; i < N; i++)
    {
        pthread_join(philo_threads[i], NULL);
    }
    return 0;
}