#if 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char name[20];
	double score[3];
	double ave;
} Student, *Stptr;

void Average(Stptr);
void Bubblesort(Stptr,int);

int main()
{
	int number;
	puts("student number?");
	scanf("%d",&number);
	Student stu[30];
	for(int i=0;i<number;i++)
	{
		puts("student name?");
		scanf("%s",stu[i].name);
		while(getchar()!='\n');
		puts("linear algebra?");
		scanf("%lf",&stu[i].score[0]);
		while(getchar()!='\n');
		puts("communicate?");
		scanf("%lf",&stu[i].score[1]);
		while(getchar()!='\n');
		puts("C programming?");
		scanf("%lf",&stu[i].score[2]);
		while(getchar()!='\n');
		Average(&stu[i]);
	}
	Bubblesort(stu,number);
	for(int i=0;i<number;i++)
	{
		printf("rank: %d\tname: %s\taverage: %lf",i+1,stu[i].name,stu[i].ave);
		printf("\n");
	}
	return 0;
}

void Average(Stptr stu)
{
	stu->ave = (stu->score[0] + stu->score[1] + stu->score[2])/3;
}

void Bubblesort(Stptr stu, int number)
{
	Student temp;
	for(int i=0;i<number-1;i++)
	{
		bool flag=false;
		for(int j=0;j<number-1-i;j++)
		{
			if(stu[j].ave < stu[j+1].ave)
			{
				flag=true;
				temp=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=temp;
			}
			else if(stu[j].ave == stu[j+1].ave)
			{
				if(strcmp(stu[j].name,stu[j+1].name)>0)
				{
					flag=true;
					temp=stu[j];
					stu[j]=stu[j+1];
					stu[j+1]=temp;
				}
			}
		}
		if(!flag) break;
	}
}
#endif