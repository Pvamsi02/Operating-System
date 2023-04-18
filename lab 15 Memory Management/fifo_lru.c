#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#define s 4
#define n 20
struct details
{
    int frame[s];
    int page[n];
    int hit;
    int fault;
};
// 1 2 3 4 2 1 5 6 2 1 2 3 7 6 3 2 1 2 3 6
bool search(int a[], int n1)
{
    for (int i = 0; i < s; i++)
    {
        if (a[i] == n1)
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
void *fifo(void *a)
{
    struct details *fif = (struct details *)a;
    printf("---------------Implimenting FIFO Page replacement algorithm----------------\n");
    fif->hit = 0;
    fif->fault = 0;
    for (int i = 0; i < n; i++)
    {
        if (search(fif->frame, fif->page[i]) == false) // if value dont exist
        {
            printf("Fault: ");
            int flag = 0;
            for (int i = 0; i < s; i++)
            {
                if (fif->frame[i] != -1) // some value 
                    flag++;
            }
            if (flag == s)
            {
                for (int i = 0; i < s - 1; i++)
                {
                    fif->frame[i] = fif->frame[i + 1];
                }
                fif->frame[s - 1] = fif->page[i];
                fif->fault++;
            }
            else
            {
                fif->frame[flag] = fif->page[i];
                fif->fault++;
            }
        }
        else
        {
            printf("Hit: ");
            fif->hit++;
        }
        pr_frame(fif->page[i], fif->frame);
    }
}
void *lru(void *b)
{
    struct details *lr = (struct details *)b;
    printf("---------------Implimenting LRU Page replacement algorithm----------------\n");
    lr->hit = 0, lr->fault = 0;
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int i = 0; i < s; i++)
        {
            if (lr->frame[i] != -1) // some value 
                flag++;
        }
        if (search(lr->frame, lr->page[i]) == false) // if value dont exist//fault
        {
            printf("Fault: ");

            if (flag == s)
            {
                for (int i = 0; i < s - 1; i++)
                {
                    lr->frame[i] = lr->frame[i + 1];
                }
                lr->frame[s - 1] = lr->page[i];
                // printf("%d ",page[i]);
                lr->fault++;
            }
            // insert(frame,page[i]);
            else
            {
                lr->frame[flag] = lr->page[i];
                // printf("%d ",page[i]);
                lr->fault++;
            }
        }
        else
        {
            printf("Hit: ");
            int pos;
            for (int j = 0; j < s; j++)
            {
                if (lr->page[i] == lr->frame[j])
                    pos = j;
            }

            int temp = lr->frame[pos];
            if (flag == s)
            {

                for (int i = pos; i < s - 1; i++)
                {
                    lr->frame[i] = lr->frame[i + 1];
                }
                lr->frame[s - 1] = temp;
            }
            else
            {
                lr->frame[flag] = temp;
            }
            lr->hit++;
        }
        pr_frame(lr->page[i], lr->frame);
    }
}
int main()
{
    struct details fi, lr;
    printf("Enter page reference string:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &fi.page[i]);
    }
    for (int i = 0; i < s; i++)
        fi.frame[i] = -1;
    lr = fi;
    pthread_t t1, t2;
    pthread_create(&t1, NULL, (void *)fifo, (void *)&fi);
    pthread_join(t1, NULL);
    printf("\nFIFO:\nFault:%d\nHit:%d\n", fi.fault, fi.hit);
    pthread_create(&t2, NULL, (void *)lru, (void *)&lr);
    pthread_join(t2, NULL);
    printf("\nLRU:\nFault:%d\nHit:%d\n", lr.fault, lr.hit);
    return 0;
}