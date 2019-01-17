#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* squeeze(char *s, char c);

int main()
{
    char str[20],c;
    puts("enter a string");
    fgets(str,20,stdin);
    puts("enter a char");
    scanf("%c",&c);
    squeeze(str,c);
    fputs(str,stdout);
    return 0;
}

char* squeeze(char *s,char c)
{
    char *ptr,*str=s;
    ptr=strchr(str,c);

    while(ptr)
    {

        for (str=ptr; *ptr != '\0'; ptr++)
        {
            *ptr = *(ptr + 1);
        }

        ptr=strchr(str,c);
    }
    return s;
}
#endif

