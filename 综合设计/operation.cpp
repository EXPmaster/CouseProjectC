#include "operation.h"
#include "dataset.h"

void CalcuAll(ppStudent student)
{
    if (!*student)
    {
        puts("请先录入成绩");
        return;
    }
    pStudent current = *student;
    double total_all[6] = {0}, average_all[6] = {0};
    int calcu = 0;
    //calculation
    while (current)
    {
        calcu++;
        for (int i = 0; i < 6; i++)
        {
            if (current->score[i] != 999)
                total_all[i] += current->score[i];
        }
        for (int i = 0; i < 6; i++)
            if (total_all[i] != 0)
                average_all[i] = total_all[i] / calcu;

        current = current->next;
    }
    puts("总体情况：");
    //print score
    char subject[][20] = {"Chinese", "math", "English", "C programming", "Politics", "Engineering"};

    for (int i = 0; i < 6; i++)
    {
        if ((*student)->score[i] != 999)
        {
            printf("%15s:\t", subject[i]);
                printf("总分：%.2lf  平均分：%.2lf", total_all[i], average_all[i]);
            printf("\n");
        }
    }

}

void CalcuSingle(ppStudent student)
{
    if (!*student)
    {
        puts("请先录入成绩");
        return;
    }
    pStudent current = *student;

    while (current)
    {
        bool flag = false;
        int calcu = 0;
        if (current->TotalScore == 0)
            flag = true;

        //flag!=true means that we'd down calculation before
        if (flag)
        {
            for (int i = 0; i < 6; i++)
            {
                if (current->score[i] != 999)
                {
                    calcu++;
                    current->TotalScore += current->score[i];
                }
            }
            current->AverageScore = current->TotalScore / calcu;
        }
        current = current->next;
    }
    puts("计算完成");
}

void ArrangeID(ppStudent head)
{
    if (!*head)
    {
        puts("请先录入成绩");
        return;
    }
    pStudent current, insert, node, first = (*head)->next;
    (*head)->next = NULL;
    while (first)
    {
        for (node = first, current = *head; (current && \
        (strcmp(current->id, node->id) < 0)); insert = current, current = current->next);
        first = first->next;
        if (current == *head)
            *head = node;
        else
            insert->next = node;
        node->next = current;
    }
    puts("排序成功");
}

void ArrangeName(ppStudent head)  //cannot receive the correct dictionary arrangement
{
    if (!*head)
    {
        puts("请先录入成绩");
        return;
    }
    pStudent current, insert, node, first = (*head)->next;
    (*head)->next = NULL;
    while (first)
    {
        for (node = first, current = *head; (current && \
        (current->name[0] < node->name[0])); insert = current, current = current->next);
        first = first->next;
        if (current == *head)
            *head = node;
        else
            insert->next = node;
        node->next = current;
    }
    puts("排序成功");
}
//arrangement 1: strcmp(current->name, node->name) < 0)

void ArrangeScore(ppStudent head)
{

    if (!*head)
    {
        puts("请先录入成绩");
        return;
    }
    int count = 1, rank = 1;
    pStudent current, insert, node, first = (*head)->next;
    (*head)->next = NULL;
    while (first)
    {
        for (node = first, current = *head; (current && \
        (current->TotalScore > node->TotalScore)); insert = current, current = current->next);
        first = first->next;
        if (current == *head)
            *head = node;
        else
            insert->next = node;
        node->next = current;
    }
    puts("排序成功");

    // rank
    pStudent  traversal_pre=*head, traversal=traversal_pre->next;
    traversal_pre->rank=1;
    while (traversal)
    {
        count++;
        bool is_equal = false;
        if (traversal->TotalScore == traversal_pre->TotalScore)
            is_equal = true;

        if (is_equal)
            traversal->rank = rank;

        else
        {
            traversal->rank = count;
            rank = count;
        }
        traversal_pre = traversal;
        traversal = traversal->next;

    }

}
