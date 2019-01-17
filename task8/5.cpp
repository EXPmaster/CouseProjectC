#if 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func(double (*matrix)[3], double *max);

void input(double (*matrix)[3]);

void print(double (*matrix)[3]);

int main()
{
    double max[3];
    double num[3][3];
    input(num);
    print(num);
    func(num, max);
    print(num);
    for (int i=0;i<2;i++)
        printf("%g ",max[i]+1);
    printf("\n");
    printf("the max is: %g\n",max[2]);
    return 0;
}

void input(double (*matrix)[3])
{
    for (int row = 0; row < 3; row++)
    {
        for (int column = 0; column < 3; column++)
        {
            scanf("%lf", &matrix[row][column]);
            while (getchar() != '\n');
        }
    }
}

void print(double (*matrix)[3])
{
    for (int row = 0; row < 3; row++)
    {
        for (int column = 0; column < 3; column++)
        {
            printf("%lf\t", matrix[row][column]);

        }
        printf("\n");
    }
    printf("\n");
}

void func(double (*matrix)[3], double *max)
{
    double temp;
    max[0] = 0, max[1] = 1, max[2] = matrix[0][0];
    for (int row = 0; row < 3; row++)
    {
        for (int column = row+1; column < 3; column++)
        {
            if (matrix[row][column] > max[2])
            {
                max[0] = column;
                max[1] = row;
                max[2] = matrix[row][column];
            }

            temp = matrix[row][column];
            matrix[row][column] = matrix[column][row];
            matrix[column][row] = temp;

            if (matrix[row][column] > max[2])
            {
                max[0] = row;
                max[1] = column;
                max[2] = matrix[row][column];
            }
        }
    }
}

#endif