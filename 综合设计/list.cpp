#include "list.h"

void InitList(ppStudent head)
{
    *head = NULL;
    puts("list initialized successfully");
}

void Append(ppStudent head, int number, int subject)
{
    pStudent current = *head, after = *head, node;
    //head for the tail of list
    while (after)
    {
        current = after;
        after = after->next;
    }

    char index[6][20] = {"Chinese", "math", "English", "C programming", "Politics", "Engineering"};
    int set[6] = {0};

    //list is empty
    if (*head == NULL)
    {
        puts("请输入科目: exp: Chinese, math, English, C programming, Politics, Engineering");

        char course[20];
        bool find_course = false;
        int temp = 0; // to record the subject you have recorded

        for (int j = 0; j < 6; j++, temp++)
        {
            int find = 0;  //search the subject

            if (temp < subject)
            {
                while (!find_course)
                {
                    puts("请输入科目");
                    s_gets(course, 20);
                    for (find = 0; find < 6; find++)
                    {
                        if (strcmp(course, index[find]) == 0 && set[find] == 0)
                        {
                            find_course = true;
                            set[find] = 1;
                            break;
                        }
                    }
                    if (!find_course)
                        puts("格式不对");
                }
                find_course = false;
            }
        }
    }

        //list is not empty
    else
    {
        for (int now = 0; now < 6; now++)
            if (current->score[now] != 999)
                set[now] = 1;
    }

    //get information
    for (int i = 0; i < number; i++)
    {
        node = (pStudent) malloc(sizeof(Student));
        if (!node)
        {
            puts("memory allocate failure");
            exit(1);
        }
        puts("请输入学生学号");
        while(!s_gets(node->id, 10) || CompareId(*head,node->id))
        {
            puts("错误，请重新输入");
        }
        puts("请输入学生姓名");
        while(!s_gets(node->name, 20) || CompareName(*head,node->name))
        {
            puts("错误，请重新输入");
        }
        puts("请输入学生成绩");

        for (int j = 0; j < 6; j++)
        {
            if (set[j] != 0)
            {
                printf("请输入%s成绩\n", index[j]);
                while (!scanf("%lf", &node->score[j]) || (node->score[j] < 0 || node->score[j] > 100))
                    puts("格式不对，请重新输入");
                clean_cache();

            }
            else
                node->score[j] = 999;
        }

        //initializes
        node->rank = 0;
        node->TotalScore = 0;
        node->AverageScore = 0;


        if (!*head)
        {
            *head = node;
            current = *head;
        }
        current->next = node;
        node->next = NULL;
        current = node;

    }
}

void TraverseList(pStudent head)
{
    pStudent current = head;
    while (current)
    {
        printf("%7s\t\t", current->id);
        printf("%7s\t\t", current->name);
        for (int i = 0; i < 6; i++)
        {
            if (current->score[i] != 999)
                printf("%6.2lf\t\t", current->score[i]);
        }
        printf("\t");
        printf("%.2lf\t\t", current->TotalScore);
        printf("%d\n", current->rank);
        current = current->next;
    }

}

void ClearList(ppStudent node)
{
    pStudent head = *node, tail;
    while (head)
    {
        tail = head->next;
        free(head);
        head = tail;
    }
    *node=NULL;
}

bool CompareId(pStudent current, char* id)
{
    while(current)
    {
        if(strcmp(current->id,id)==0)
            return true;
        current=current->next;
    }
    return false;
}

bool CompareName(pStudent current, char* name)
{
    while(current)
    {
        if(strcmp(current->name,name)==0)
            return true;
        current=current->next;
    }
    return false;
}