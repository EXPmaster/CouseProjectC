#if 0

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 15

void func1(int *, int, int);

int *func2(int *, int);

int main()
{
    printf("二分法的缺陷：不能找出重复的数\n");
    int num[NUM], data;
    int *target = NULL;
    srand((unsigned) time(0));

    for (int i = -1; i < NUM-1; num[++i] = rand() % 100 + 1);
    func1(num, 0, NUM);
    for (int i = -1; i < NUM-1; printf("%d ", num[++i]));
    printf("\n");

    puts("data?");
    scanf("%d", &data);


    target = func2(num, data);

    if (target)
    {
        printf("it's the %d element\n", *target + 1);
    }
    else
        printf("it's not in the array\n");

    return 0;
}

void func1(int *num, int low, int high)
{
    int left = low, right = high;
    int key = num[left];
    if (low > high)
        return;
    while (left < right)
    {
        while (left < right && num[right] >= key)
            right--;
        num[left] = num[right];
        while (left < right && num[left] <= key)
            left++;
        num[right] = num[left];
    }
    num[left] = key;
    func1(num, low, left - 1);
    func1(num, right + 1, high);
}

int *func2(int *num, int data)
{
    int *ptr = NULL;
    int left = 0, right = NUM - 1, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (data > num[mid])
            left = mid + 1;
        else if (data < num[mid])
            right = mid - 1;
        else if (data == num[mid])
        {
            ptr = &mid;
            break;
        }
    }
    return ptr;
}

#endif

