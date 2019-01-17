#if 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fun(char *str, int *number, char *target);

char *s_gets(char *);

int main()
{
    int number = 0;
    char str[100], target[100];
    s_gets(str);
    fun(str, &number, target);
    printf("%s\n%d\n", target, number);

    return 0;
}

char *s_gets(char *str)
{
    char *ret_val, *find;
    puts("请输入单词，以空格结束");
    ret_val = fgets(str, 100, stdin);
    if (ret_val)
    {
        find = strchr(str, '\n');
        if (*(find - 1) != ' ')
        {
            puts("错误格式！");
            exit(1);
        }
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n');
    }
    return ret_val;
}

void fun(char *str, int *number, char *target)
{
    char *begin, *end;
    char data[50][20] = {'\0'};
    int i = 0, j = 0, k = 0;
    begin = str;
    end = strstr(begin, " ");
    while (end)
    {
        for (j = 0; begin <= end; begin++, j++)
            data[i][j] = *begin;
        begin = end + 1;
        end = strstr(begin, " ");
        i++;
    }

    char max[20] = "0";
    for (int key = 0; key < i; key++)
    {
        if (strcmp(data[key], max) > 0)
            strcpy(max, data[key]);
    }
    //printf("%s\n%s\n",max,data[0]);
    //printf("k=%d\n",k);

    while (strcmp(max, data[k]) == 0 && k < i)
    {
        k++;
    }
    if (k == i)
    {
        puts("nothing in the array now!");
        exit(0);
    }
    if (data[k][0] >= 'a' && data[k][0] <= 'z')
    {
        data[k][0] = data[k][0] - ('a' - 'A');
    }

    for (int index = k; index < i; index++)
    {
        if (strcmp(max, data[index]) != 0)
        {

            if (data[index][0] >= 'a' && data[index][0] <= 'z')
            {
                data[index][0] = data[index][0] - ('a' - 'A');
            }

            strcat(target, data[index]);
            (*number)++;
        }

    }
    //printf("%s\n",data[k]);
}

#endif