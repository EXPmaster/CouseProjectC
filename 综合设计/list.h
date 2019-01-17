//basic operation of one-way-list

#ifndef FINAL_TASK_LIST_H
#define FINAL_TASK_LIST_H

#include "dataset.h"

void InitList(ppStudent head);  //initialize list
void Append(ppStudent head, int number, int subject);  //add a new element to the end of th list
void TraverseList(pStudent head);  //show all elements of the list
void ClearList(ppStudent node);  //destroy list, which is used at the end of file
bool CompareId(pStudent, char*);  //search if there exists the same id, if same return true
bool CompareName(pStudent, char*); //search if there exists the same name, if same return true

#endif //FINAL_TASK_LIST_H
