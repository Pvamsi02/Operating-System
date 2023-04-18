#include <stdio.h>
void firstFit(int process_size[], int m, int space[], int n)
{
    printf("\n\n\t\tFirst fit");
    int allocation[m];
    for (int i = 0; i < m; i++)
        allocation[i] = -1;
    printf("\nProcess id\tProcess Size\tBlock No.\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (space[j] >= process_size[i])
            {
                space[j] -= process_size[i];
                allocation[i] = j;
                break;
            }
        }
        printf("%d\t\t%d\t\t", i + 1, process_size[i]);
        if (allocation[i] == -1)
            printf("Not allocated\n");
        else
            printf("%i\n", allocation[i] + 1);
    }
}
void bestFit(int process_size[], int m, int space[], int n)
{
    printf("\n\n\t\tBest fit");
    int allocation[m];
    for (int i = 0; i < m; i++)
        allocation[i] = -1;
    printf("\nProcess id\tProcess Size\tBlock No.\n");
    for (int i = 0; i < m; i++)
    {
        int x = -1;
        for (int j = 0; j < n; j++)
        {

            if (space[j] >= process_size[i])
            {
                if (x == -1)
                    x = j;
                else if (space[x] > space[j])
                    x = j;
            }
        }
        if (x != -1)
        {
            allocation[i] = x;
            space[x] -= process_size[i];
        }
        printf("%d\t\t%d\t\t", i + 1, process_size[i]);
        if (allocation[i] == -1)
            printf("Not allocated\n");
        else
            printf("%i\n", allocation[i] + 1);
    }
}
void worstFit(int process_size[], int m, int space[], int n)
{
    printf("\n\n\t\tWorst fit");
    int allocation[m];
    for (int i = 0; i < m; i++)
        allocation[i] = -1;
    printf("\nProcess id\tProcess Size\tBlock No.\n");
    for (int i = 0; i < m; i++)
    {
        int x = -1;
        for (int j = 0; j < n; j++)
        {

            if (space[j] >= process_size[i])
            {
                if (x == -1)
                    x = j;
                else if (space[x] < space[j])
                    x = j;
            }
        }
        if (x != -1)
        {
            allocation[i] = x;
            space[x] -= process_size[i];
        }
        printf("%d\t\t%d\t\t", i + 1, process_size[i]);
        if (allocation[i] == -1)
            printf("Not allocated\n");
        else
            printf("%i\n", allocation[i] + 1);
    }
}
int main()
{
    int n;
    printf("Enter the number of sections memory of 10GB divided:");
    scanf("%d", &n);
    int space1[n];
    int space2[n];
    int space3[n];
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the divison number %d (in GB):", i + 1);
        scanf("%d", &space1[i]);
        space2[i] = space1[i];
        space3[i] = space1[i];
    }

    int m;
    printf("Enter the number process:");
    scanf("%d", &m);
    int process_size[m];

    for (int i = 0; i < m; i++)
    {
        printf("\nEnter the allocation required for process number %d (in GB):", i + 1);
        scanf("%d", &process_size[i]);
    }

    firstFit(process_size, m, space1, n);
    bestFit(process_size, m, space2, n);
    worstFit(process_size, m, space3, n);
    return 0;
}