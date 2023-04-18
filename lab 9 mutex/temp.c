#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int main()
{
    char string[] = "abcdefghijklmnopqrstuvwxyz";
    size_t stringLen = strlen(string);
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
        printf("%c", string[rand() % stringLen]);
}
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// #define STRING_LENGTH 10

// int main()
// {
//     char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
//     char random_string[STRING_LENGTH + 1];
//     int i;

//     srand(time(NULL));

//     for (i = 0; i < STRING_LENGTH; i++)
//     {
//         random_string[i] = alphabet[rand() % 26];
//     }
//     random_string[STRING_LENGTH] = '\0';

//     printf("Random string: %s\n", random_string);

//     return 0;
// }