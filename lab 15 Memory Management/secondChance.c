#include <stdio.h>
#define s 4
// 0 4 1 4 2 4 3 4 2 4 0 4 1 4 2 4 3 4
int full = 0; // To check whether all frames are filled
int a[21];    // To take the input
int ref[s];   // This is for reference bits for each frame
int frame[s];
int repptr = 0; // Initialised to first frame
int count = 0;
int display()
{
    int i;
    printf("\nThe elements in the frame are: ");
    for (i = 0; i < full; i++)
        printf("%d  ", frame[i]);
}
int Pagerep(int ele)
{
    int temp;
    while (ref[repptr] != 0)
    {
        ref[repptr++] = 0;
        if (repptr == s)
            repptr = 0;
    }
    temp = frame[repptr];
    frame[repptr] = ele;
    ref[repptr] = 1; // The latest page reference, hence it is set to 1

    return temp;
}
int Pagefault(int ele)
{
    if (full != s)
    {
        ref[full] = 1; // All the ref bits are set to 1 as each frame is being filled firstly
        frame[full++] = ele;
    }
    else
        printf("\tThe page replaced is %d", Pagerep(ele));
}
int Search(int ele)
{
    int i, flag;
    flag = 0;
    if (full != 0)
    {
        for (i = 0; i < full; i++)
            if (ele == frame[i])
            {
                flag = 1;
                ref[i] = 1; // When ever page reference occurs, it's rference bit is set to 1
                break;
            }
    }
    return flag;
}
int main()
{
    int n, i;
    printf("The number of elements in the reference string are :");
    scanf("%d", &n);
    printf("Enter page refernce string:");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
    {
        if (Search(a[i]) != 1)
        {
            Pagefault(a[i]);
            display();
            count++;
        }
    }
    printf("\nThe number of page faults are %d\n", count);
    getchar();
    return 0;
}
