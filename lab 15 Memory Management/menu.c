#include <stdio.h>
#include <stdbool.h>
#define s 3
// 1 2 3 4 2 1 5 6 2 1 2 3 7 6 3 2 1 2 3 6
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
void fifo()
{
    printf("---------------Implimenting FIFO Page replacement algorithm----------------\n");
    int n;
    printf("String Length:");
    scanf("%d", &n);
    // n = 10;
    printf("Enter page reference string:");
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
    int hit = 0, fault = 0;
    for (int i = 0; i < n; i++)
    {
        if (search(frame, page[i]) == false) // if value dont exist
        {
            printf("Fault: ");
            int flag = 0;
            for (int i = 0; i < s; i++)
            {
                if (frame[i] != -1) // some value 
                    flag++;
            }
            if (flag == s)
            {
                for (int i = 0; i < s - 1; i++)
                {
                    frame[i] = frame[i + 1];
                }
                frame[s - 1] = page[i];
                fault++;
            }
            else
            {
                frame[flag] = page[i];
                fault++;
            }
        }
        else
        {
            printf("Hit: ");
            hit++;
        }
        pr_frame(page[i], frame);
    }
    printf("\nFault:%d\n", fault);
    printf("Hit:%d\n", hit);
}
void lru()
{
    printf("---------------Implimenting LRU Page replacement algorithm----------------\n");
    int n;
    printf("String Length:");
    scanf("%d", &n);
    // n = 10;
    printf("Enter page reference string:");
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
    int hit = 0, fault = 0;
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
            printf("Fault: ");

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
            printf("Hit: ");
            int pos;
            for (int j = 0; j < s; j++)
            {
                if (page[i] == frame[j])
                    pos = j;
            }

            int temp = frame[pos];
            if (flag == s)
            {

                for (int i = pos; i < s - 1; i++)
                {
                    frame[i] = frame[i + 1];
                }
                frame[s - 1] = temp;
            }
            else
            {
                frame[flag] = temp;
            }
            hit++;
        }
        pr_frame(page[i], frame);
    }
    printf("\nfault:%d\n", fault);
    printf("\nHit:%d", hit);
}
void optimal()
{
    printf("---------------Implimenting Optimal Page replacement algorithm----------------\n");
    int n;
    printf("String Length:");
    scanf("%d", &n);
    // n = 10;
    printf("Enter page reference string:");
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
    int hit = 0, fault = 0, k = 0;
    for (int i = 0; i < n; i++)
    {
        if (search(frame, page[i]) == false) // if value dont exist
        {
            printf("Fault: ");
            fault++;
            int flag = 0;
            for (int i = 0; i < s; i++)
            {
                if (frame[i] == -1) // some value 
                    flag++;
            }
            if (flag <= s && flag != 0)
            {
                frame[k] = page[i];
                k++;
            }
            else
            {
                int flag2 = 0;
                int flag1 = 0;
                int max = -1, pos;
                for (int x = 0; x < s; x++) // frame
                {
                    flag1 = 0;
                    for (int y = i + 1; y < n; y++) // future string
                    {

                        if (page[y] == frame[x]) // fram
                        {
                            if (y > max)
                            {
                                max = y;
                                pos = x;
                            }
                            flag1 = 1;
                            break;
                        }
                    }
                    if (flag1 == 0) // not in future
                    {
                        // printf("not in future%d%d%d%d\t", x, s - 1, page[i], frame[s - 1]);
                        flag2 = 1;
                        for (int i = x; i < s - 1; i++)
                        {
                            frame[i] = frame[i + 1];
                        }
                        frame[s - 1] = page[i];
                        break;
                    }
                }
                if (flag2 != 1)
                    frame[pos] = page[i];
            }
        }
        else
        {
            printf("Hit: ");
            hit++;
        }
        pr_frame(page[i], frame);
    }
    printf("\nFault:%d\n", fault);
    printf("Hit:%d\n", hit);
}
int main()
{
    printf("Menu:\n1.FIFO\n2.LRU\n3.Optimal\nEnter your choice:");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        fifo();
        break;
    case 2:
        lru();
        break;
    case 3:
        optimal();
        break;
    default:
        printf("Wrong Input!");
        break;
    }
    return 0;
}