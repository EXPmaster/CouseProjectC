//to store information of students and read & write info to file
//get information from keyboard
//search information

#ifndef FINAL_TASK_DATASET_H
#define FINAL_TASK_DATASET_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct dataset
{
    char name[20];
    double score[6];
    char id[10];
    double AverageScore;
    double TotalScore;
    int rank;
    struct dataset *next;
}Student, *pStudent, **ppStudent;

void GetInfo(ppStudent student); //input information from keyboard
void GetFile(ppStudent student);  //get data from file

void Output_to_file(ppStudent student); //save data to file

void SearchID(ppStudent student); // search for information through ID
void SearchName(ppStudent student); //search for information thorough name (first name and full name)
void CalcuCategory(ppStudent student); //calculate category
void Traverse(pStudent student); //show all elements of students

char *s_gets(char* str, int n);  //replace '\n' by '\0'
char *s_gets(char *str, int n, FILE *fp);  //replace '\n' by '\0'

void clean_cache();


#endif //FINAL_TASK_DATASET_H
