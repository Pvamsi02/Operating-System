#include <stdio.h>
#include <pthread.h>
#define n 5
#define m 4
struct processData
{
    int space[n];
    int process_size[m];
    int allocation[m];
    int unallocated[m];
};
void *firstFit(void *p)
{
    struct processData *pd = (struct processData *)p;
    printf("\n\n\t\tFirst fit");

    for (int i = 0; i < m; i++)
        pd->allocation[i] = -1;
    printf("\nProcess id\tProcess Size\tBlock No.\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (pd->space[j] >= pd->process_size[i])
            {
                pd->space[j] -= pd->process_size[i];
                pd->allocation[i] = j;
                break;
            }
        }
        printf("%d\t\t%d\t\t", i + 1, pd->process_size[i]);
        if (pd->allocation[i] == -1)
        {
            printf("Not allocated\n");
        }

        else
            printf("%i\n", pd->allocation[i] + 1);
    }
}
void *bestFit(void *p)
{
    struct processData *pd = (struct processData *)p;
    printf("\n\n\t\tBest fit");

    printf("\nProcess id\tProcess Size\tBlock No.\n");
    for (int i = 0; i < m; i++)
    {
        int x = -1;
        for (int j = 0; j < n; j++)
        {

            if (pd->space[j] >= pd->process_size[i])
            {
                if (x == -1)
                    x = j;
                else if (pd->space[x] > pd->space[j])
                    x = j;
            }
        }
        if (x != -1)
        {
            pd->allocation[i] = x;
            pd->space[x] -= pd->process_size[i];
        }
        printf("%d\t\t%d\t\t", i + 1, pd->process_size[i]);
        if (pd->allocation[i] == -1)
            printf("Not allocated\n");
        else
            printf("%i\n", pd->allocation[i] + 1);
    }
}
void *worstFit(void *p)
{
    struct processData *pd = (struct processData *)p;
    printf("\n\n\t\tWorst fit");

    printf("\nProcess id\tProcess Size\tBlock No.\n");
    for (int i = 0; i < m; i++)
    {
        int x = -1;
        for (int j = 0; j < n; j++)
        {

            if (pd->space[j] >= pd->process_size[i])
            {
                if (x == -1)
                    x = j;
                else if (pd->space[x] < pd->space[j])
                    x = j;
            }
        }
        if (x != -1)
        {
            pd->allocation[i] = x;
            pd->space[x] -= pd->process_size[i];
        }
        printf("%d\t\t%d\t\t", i + 1, pd->process_size[i]);
        if (pd->allocation[i] == -1)
            printf("Not allocated\n");
        else
            printf("%i\n", pd->allocation[i] + 1);
    }
}
int main()
{
    struct processData pd1, pd2, pd3;
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the divison number %d (in GB):", i + 1);
        scanf("%d", &pd1.space[i]);
    }
    for (int i = 0; i < m; i++)
    {
        printf("\nEnter the allocation required for process number %d (in GB):", i + 1);
        scanf("%d", &pd1.process_size[i]);
    }
    for (int i = 0; i < m; i++)
        pd1.allocation[i] = -1;
    pd2 = pd1;
    pd3 = pd1;
    pthread_t first_t, best_t, worst_t;
    pthread_create(&first_t, NULL, (void *)firstFit, (void *)&pd1);
    pthread_join(first_t, NULL);
    int flag = m;
    for (int i = 0; i < m; i++)
    {
        if (pd1.allocation[i] == -1)
        {
            printf("\nProcess Id %d is unallocated\n", i);
            flag--;
        }
    }
    if (m == flag)
        printf("\nAll process are successfully allocated\n");
    pthread_create(&best_t, NULL, (void *)bestFit, (void *)&pd2);
    pthread_join(best_t, NULL);
    flag = m;
    for (int i = 0; i < m; i++)
    {
        if (pd2.allocation[i] == -1)
        {
            printf("\nProcess Id %d is unallocated\n", i);
            flag--;
        }
    }
    if (m == flag)
        printf("\nAll process are successfully allocated\n");
    pthread_create(&worst_t, NULL, (void *)worstFit, (void *)&pd3);
    pthread_join(worst_t, NULL);
    flag = m;
    for (int i = 0; i < m; i++)
    {
        if (pd3.allocation[i] == -1)
        {
            printf("\nProcess Id %d is unallocated\n", i);
            flag--;
        }
    }
    if (m == flag)
        printf("\nAll process are successfully allocated\n");
    return 0;
}