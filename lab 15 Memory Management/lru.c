#include <stdio.h>
#include <stdbool.h>
#define s 3
bool search(int a[], int n)
{
    for (int i = 0; i < s; i++)
    {
        if (a[i] == n)
        {
            return true;
        }
    }
    return false;
}
void insert(int a[])
{
    printf("frame:");
    for (int i = 0; i < s; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main()
{
    int n;
    scanf("%d", &n);
    n = 10;
    int page[n]; // = {2, 3, 1, 0, 3, 0, 1, 4, 5, 6};
    // 2 3 1 0 3 0 1 4 5 6
    // 2 3 1 7 3 7 1 4 5 6
    int frame[s];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &page[i]);
    }
    for (int i = 0; i < s; i++)
        frame[i] = -1;
    int k = 0, fault = 0;
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int i = 0; i < s; i++)
        {
            if (frame[i] != -1) // some value 
                flag++;
        }
        if (search(frame, page[i]) == false) // if value dont exist//fault
        {

            if (flag == s)
            {
                for (int i = 0; i < s - 1; i++)
                {
                    frame[i] = frame[i + 1];
                }
                frame[s - 1] = page[i];
                // printf("%d ",page[i]);
                fault++;
            }
            // insert(frame,page[i]);
            else
            {
                frame[flag] = page[i];
                // printf("%d ",page[i]);
                fault++;
            }
        }
        else
        {
            int temp = frame[0];
            if (flag == s)
            {

                for (int i = 0; i < s - 1; i++)
                {
                    frame[i] = frame[i + 1];
                }
                frame[s - 1] = temp;
            }
            else
            {
                frame[flag] = temp;
            }
        }
        insert(frame);
    }
    printf("\nfault:%d\n", fault);
    printf("\nHit:%d", n - fault);
    return 0;
}