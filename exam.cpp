
#include <stdio.h>

void selectsort(double *, int);

void insert_push(double *, int, double, double &);


int main()
{
    double number[10] = {1, 2, 3, 6, 8, 99, 88, 100, 123, 9};
    double pushed, moveout;

    selectsort(number, 10);
    printf("Pls input a new number:");
    scanf("%lf", &pushed);
    insert_push(number, 10, pushed, moveout);

    for (int i = 0; i < 10; i++)
        printf("%lf ", number[i]);
    printf("\n");
    printf("%lf", moveout);
    return 0;
}

void selectsort(double *array, int length)
{
    double temp;
    for (int i = 0; i < length - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < length; j++)
        {
            if (array[i] > array[j])
                min = j;
        }
        if (min != i)
        {
            temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }
}

void insert_push(double *array, int length, double insert, double &element)
{
    if (insert >= array[length - 1])
    {
        element = insert;
        return;
    }
    element = array[length - 1];
    bool flag = false;

    for (int i = length - 1; i > 0; i--)
    {
        array[i] = array[i - 1];

        if (insert >= array[i - 1])
        {
            array[i] = insert;
            flag = true;
            break;
        }
    }
    if (!flag)
        array[0] = insert;
}

