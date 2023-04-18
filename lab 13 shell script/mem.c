#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int n, pgsize = 4, addr, pgno, offset;
    pgsize *= 1024;
    for (int i = 0; i < atoi(argv[1]); i++)
    {
        addr = atoi(argv[i + 2]);
        pgno = addr / pgsize;
        offset = addr % pgsize;
        printf("Page size:%d\nOffset:%d\n", pgno, offset);
    }
    return 0;
}
