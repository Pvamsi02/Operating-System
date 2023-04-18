#include <stdio.h>
int main()
{
    int i, j, count = 0, tot = 0, row = 3, col = 3;
    int request[row][col]; // 3 4 5 4 5 6 5 6 7
    printf("Need Matrix:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &request[i][j]);
        }
    }
    for (i = 0; i < row; i++)
    {
        count = 0;
        tot = 0;
        for (j = 0; j < row; j++)
        {
            count += request[j][i] - 1;
        }
        tot += count + 1;
        printf("Minimum requirement of resouce R%d is %d\n", i, tot);
    }
    return 0;
}