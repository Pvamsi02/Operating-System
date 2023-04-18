#include <stdio.h>
#include <stdbool.h>
#define row 5
#define col 3
bool final[row];
void initailFinal()
{
        for (int i = 0; i < row; i++)
                final[i] = false;
}
void pout(int a[row][col])
{
        for (int i = 0; i < row; i++)
        {
                for (int j = 0; j < col; j++)
                        printf("%d ", a[i][j]);
                printf("\n");
        }
        printf("\n");
}

void pr(int a[col])
{

        for (int i = 0; i < col; i++)
        {
                printf("%d ", a[i]);
        }
        printf("\n");
}

int main()
{
        char name[30];
        FILE *fp = fopen("a.txt", "r");
        int allocation[row][col];
        fscanf(fp, "%s", name);
        printf("%s\n", name);
        for (int i = 0; i < row; i++)
                for (int j = 0; j < col; j++)
                        fscanf(fp, "%d", &allocation[i][j]);
        pout(allocation);

        fscanf(fp, "%s", name);
        int max[row][col];
        for (int i = 0; i < row; i++)
                for (int j = 0; j < col; j++)
                        fscanf(fp, "%d", &max[i][j]);
        printf("%s\n", name);
        pout(max);

        int request[row][col];
        fscanf(fp, "%s", name);
        printf("%s\n", name);
        int available[col];
        for (int i = 0; i < col; i++)
                fscanf(fp, "%d", &available[i]);
        pr(available);
        fclose(fp);
        int cavailable[col];
        int x = row;

        for (int i = 0; i < row; i++)
                for (int j = 0; j < col; j++)
                        request[i][j] = max[i][j] - allocation[i][j];
        printf("Request matrix:\n");
        pout(request);

        initailFinal();

        for (int i = 0; i < col; i++)
        {
                cavailable[i] = available[i];
        }

        // pr(cavailable);

        int j = 0, count = 0;
        for (int k = 0; k < row; k++)
        // while(x!=0)
        {
                for (int i = 0; i < row; i++)
                {
                        if (final[i] == false)
                        {
                                count = 0;
                                for (int j = 0; j < col; j++)
                                {
                                        if (cavailable[j] >= request[i][j])
                                        {
                                                count++;
                                        }
                                }
                                if (count == col)
                                {
                                        printf("P[%d]->", i + 1);
                                        for (int j = 0; j < col; j++)
                                        {
                                                cavailable[j] += allocation[i][j];
                                        }
                                        final[i] = true;
                                        x--;
                                }
                        }
                }
        }

        for (int i = 0; i < row; i++)
        {
                if (final[i] == 0)
                        x = 1;
        }
        if (x != 1)
        {
                printf("No Dead lock\nTotal resources left:");
                pr(cavailable);
        }

        else
                printf("Dead lock occurs");
        // pout(request);
        return 0;
}
