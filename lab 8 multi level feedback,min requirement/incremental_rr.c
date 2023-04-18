#include <stdio.h>
#define row 5
#define col 4
int compare(int a[col], int b[col])
{
    int x = 0;
    for (int i = 0; i < col; i++)
    {
        if (a[i] <= b[i])
            x++;
    }
    if (x == col)
        return 1;
    else
        return 0;
}
void print_2d(int a[row][col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("\n");
}
int safers(int required[][col], int allocation[][col], int available[col])
{
    int current[col];
    int flag = 0, rc = 0;
    int final[row];
    for (int i = 0; i < row; i++)
        final[i] = 0;
    for (int i = 0; i < col; i++)
        current[i] = available[i];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
         
            if (final[j] == 0)
            {
                flag=0;
                for (int k = 0; k < col; k++)
                {
                    if (current[k] >= required[j][k])
                        flag++;
                }
                if (flag == col)
                {
                    for (int k = 0; k < col; k++)
                    {
                        current[k] += allocation[j][k];
                    }
                    final[j] = 1;
                    printf("P[%d]=>", j);
                }
            }
        }
    }
    for (int i = 0; i < row; i++)
    {
        if (final[i] == 1)
            rc++;
    }

    if (rc == row)
    {
        return 0;
    }
    else
        return 1;
}
void process(int x, int resources_required[][col], int allocation[row][col], int required[row][col], int available[col], int k)
{
    int t;
    int new_allocation[row][col], new_required[row][col], new_available[col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            new_allocation[i][j] = allocation[i][j];
            new_required[i][j] = required[i][j];
            new_available[j] = available[j];
        }
    }
    if (compare(resources_required[k], new_available))
    {
        for (int i = 0; i < col; i++)
        {
            t = resources_required[k][i];
            new_allocation[x][i] = new_allocation[x][i] + t;
            new_available[i] = new_available[i] - t;
            new_required[x][i] = new_required[x][i] - t;
        }
        if (safers(new_required, new_allocation, new_available) == 0)
        {
            printf("\nProcess %d Request is safe to add.\n", x + 1);
            for (int i = 0; i < col; i++)
            {
                t = resources_required[k][i];
                allocation[x][i] = allocation[x][i] + t;
                available[i] = available[i] - t;
                required[x][i] = required[x][i] - t;
            }
        }
        else
            printf("\nProcess %d required makes a deadlock.\n", x);
    }
    else
        printf("\nProcess %d Request cannot be accepted due to less resources available.\n", x);
}
void resourcerequired(int allocation[row][col], int required[row][col], int available[col])
{
    int n, x;
    printf("No of Request:");
    scanf("%d", &n);
    int process_required[n];
    int resources_required[n][col];
    for (int i = 0; i < n; i++)
    {
        printf("Process id:");
        scanf("%d", &process_required[i]);
        printf("Request resources:");
        for (int j = 0; j < col; j++)
            scanf("%d", &resources_required[i][j]);
    }
    for (int i = 0; i < n; i++)
    {
        process(process_required[i], resources_required, allocation, required, available, i);
    }
}
void getRequired(int max[][col], int allocation[][col], int required[][col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            required[i][j] = max[i][j] - allocation[i][j];
        }
    }
}
int main()
{
    printf("Row:%d\nColumn:%d\n", row, col);
    printf("Max Matrix input:\n");
    int max[row][col]; //5 1 1 7 3 2 1 1 3 3 2 1 4 6 1 2 6 3 2 5
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }
    printf("Allocation Matrix:\n");
    int allocation[row][col];// 3 0 1 4 2 2 1 0 3 1 2 1 0 5 1 0 4 2 1 2
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }
    printf("Available Matrix:\n");
    int available[col];// 0 3 0 1
    for (int i = 0; i < col; i++)
        scanf("%d", &available[i]);
    int required[row][col];
    getRequired(max, allocation, required);
    printf("Required Matrix:\n");
    print_2d(required);
    int new_allocation[row][col], new_required[row][col], new_available[col];
   
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            new_allocation[i][j] = allocation[i][j];
            new_required[i][j] = required[i][j];
            new_available[j] = available[j];
        }
    }
    print_2d(new_required);
        print_2d(new_allocation);
    int res = safers(required, allocation, available);
    if (res == 1)
        printf("Gives DeadLock\n\n");
    else
        printf("Safe\n\n");

    resourcerequired(new_allocation, new_required, new_available);

    return 0;
}
