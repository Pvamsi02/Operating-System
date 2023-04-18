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
                  if (page[y] == frame[x]) // frame
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
   return 0;
}