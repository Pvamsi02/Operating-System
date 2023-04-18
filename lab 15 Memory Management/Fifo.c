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
void pr_frame(int pg, int a[])
{
    printf("%d->frame:", pg);
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
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &page[i]);
    }
    int frame[s];
    for (int i = 0; i < s; i++)
        frame[i] = -1;
    int hit = 0, fault = 0, index = -1;
    for (int i = 0; i < n; i++)
    {
        if (search(frame, page[i]) == false) // if value dont exist
        {

            index = (index + 1) % s;
            frame[index] = page[i];
            fault++;
        }
        else
        {
            // check[check_pos(frame, page[i])] = 1;
            hit++;
        }
        // if (search(frame, page[i]) == false) // if value dont exist
        // {
        //     int flag = 0;
        //     for (int i = 0; i < s; i++)
        //     {
        //         if (frame[i] != -1) // some value 
        //             flag++;
        //     }
        //     if (flag == s)
        //     {
        //         for (int i = 0; i < s - 1; i++)
        //         {
        //             frame[i] = frame[i + 1];
        //         }
        //         frame[s - 1] = page[i];
        //         fault++;
        //     }
        //     else
        //     {
        //         frame[flag] = page[i];
        //         fault++;
        //     }
        // }
        // else
        // {
        //     hit++;
        // }
        pr_frame(page[i], frame);
    }
    printf("\nFault:%d\n", fault);
    printf("Hit:%d\n", hit);

    return 0;
}
/*
 if (search(frame, page[i]) == false) // if value dont exist
        {

            index = (index + 1) % s;
            frame[index] = page[i];
            fault++;
        }
        else
        {
            // check[check_pos(frame, page[i])] = 1;
            hit++;
        }
*/