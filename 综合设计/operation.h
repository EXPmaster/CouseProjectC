//calculate scores, arrangement, search for information of a certain student

#ifndef FINAL_TASK_OPERATION_H
#define FINAL_TASK_OPERATION_H

#include "dataset.h"


void CalcuAll(ppStudent student);  //calculate all students' scores
void CalcuSingle(ppStudent student);  //calculate every students' scores
void ArrangeID(ppStudent head);  //arrange by students' id
void ArrangeScore(ppStudent head);  //arrange by students' total scores
void ArrangeName(ppStudent head);  //arrange by students' name (dictionary index)

#endif //FINAL_TASK_OPERATION_H
