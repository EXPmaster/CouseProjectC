#if 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 100

void count_substr(char *str, char *sub_str, int *number);

int main()
{
    char input[NUM], target[NUM];
    int number = 0;
    puts("string?");
    scanf("%s", input);
    while(getchar()!='\n');
    puts("sub string?");
    scanf("%s", target);
    count_substr(input, target, &number);
    printf("%d\n", number);
    return 0;
}

void count_substr(char *str, char *sub_str, int *number)
{
    char *ptr = str;
    while ((ptr = strstr(ptr, sub_str)) != NULL && ptr - str <= strlen(str))
    {
        (*number)++;
        ptr += strlen(sub_str);
    }
}

#endif

