#include "dataset.h"

extern void Append(ppStudent head, int number, int subject);

extern void TraverseList(pStudent head);

void GetInfo(ppStudent student)
{
    int number = 0, subject = 0;
    if (*student == NULL)
    {
        puts("请输入考试科目总数");

        while (!scanf("%d", &subject) || (subject <= 0 || subject > 6))
        {
            puts("格式不对，请重新输入");
            clean_cache();
        }
    }
    puts("请输入要录入的考生人数");
    while (!scanf("%d", &number) || (number <= 0 || number > 30))
    {
        puts("格式不对，请重新输入");
        clean_cache();
    }
    clean_cache();
    Append(student, number, subject);
    puts("录入成功");
}

char *s_gets(char *str, int n)
{
    char *find, *ret_val;
    ret_val = fgets(str, n, stdin);
    if (ret_val)
    {
        find = strchr(str, '\n');
        if (find)
            *find = '\0';
        else
            clean_cache();
    }
    return ret_val;
}

void Traverse(pStudent student)
{
    if (!student)
    {
        puts("请先录入成绩");
        return;
    }
    puts("成绩单");
    printf("   学号\t\t");
    printf("姓名\t\t");
    char index[6][20] = {"Chinese", "math", "English", "C programming", "Politics", "Engineering"};
    for (int i = 0; i < 6; i++)
    {
        if (student->score[i] != 999)
            printf("%s\t\t", index[i]);
    }
    printf("\t");
    printf("总分\t\t");
    printf("排名\n");
    TraverseList(student);
}

void GetFile(ppStudent student)
{
    FILE *fp;
    *student = NULL;
    if ((fp = fopen("studengdata.txt", "r")) == NULL)
    {
        puts("no such file");
        exit(1);
    }

    pStudent node, current = *student;
    /*
    while (after)
    {
        current = after;
        after = after->next;
    }
     */

    while (!feof(fp))   //bug: if the file is empty then it'll get all 0
    {
        node = (pStudent) malloc(sizeof(Student));
        if (!node)
        {
            puts("memory allocate failure");
            exit(1);
        }

        if (!*student)
        {
            *student = node;
            current = *student;
        }
        current->next = node;
        node->next = NULL;
        current = node;

        s_gets(node->id, 10, fp);
        s_gets(node->name, 20, fp);
        fscanf(fp, "\t");
        for (int i = 0; i < 6; i++)
        {
            fscanf(fp, "%lf\t", &node->score[i]);
        }
        fscanf(fp, "%lf\t", &node->TotalScore);
        fscanf(fp, "%d\n", &node->rank);
    }
    fclose(fp);
}

void Output_to_file(ppStudent student)
{
    FILE *fp;
    fp = fopen("studengdata.txt", "w");
    pStudent current = *student;
    while (current)
    {
        fprintf(fp, "%s\n", current->id);
        fprintf(fp, "%s\n", current->name);
        for (int i = 0; i < 6; i++)
        {
            fprintf(fp, "%lf\t", current->score[i]);
        }
        fprintf(fp, "%lf\n", current->TotalScore);
        fprintf(fp, "%d\n", current->rank);
        current = current->next;
    }
    fclose(fp);
    puts("写入文件成功");
}

char *s_gets(char *str, int n, FILE *fp)
{
    char *find, *ret_val;
    ret_val = fgets(str, n, fp);
    if (ret_val)
    {
        find = strchr(str, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n');
    }
    return ret_val;
}

void SearchID(ppStudent student)
{
    if (!*student)
    {
        puts("请先录入成绩");
        return;
    }
    pStudent current = *student;
    char index[6][20] = {"Chinese", "math", "English", "C programming", "Politics", "Engineering"};
    puts("输入你要查找到学号");
    char search[10];
    s_gets(search, 10);
    puts("搜索结果：");
    printf("学号\t\t\t");
    printf("姓名\t\t");
    for (int i = 0; i < 6; i++)
    {
        if ((*student)->score[i] != 999)
            printf("%s\t", index[i]);
    }
    printf("\t");
    printf("总分\t\t");
    printf("排名\n");

    while (current)
    {
        //if find existing student information
        if (strcmp(current->id, search) == 0)
        {
            printf("%s\t\t", current->id);
            printf("%s\t\t", current->name);
            for (int i = 0; i < 6; i++)
            {
                if (current->score[i] != 999)
                    printf("%.2lf\t", current->score[i]);
            }
            printf("\t");
            printf("%.2lf\t\t", current->TotalScore);
            printf("%d\n", current->rank);
            return;
        }
        current = current->next;
    }
    //cannot find information
    puts("找不到结果");
}

void SearchName(ppStudent student)
{
    if (!*student)
    {
        puts("请先录入成绩");
        return;
    }
    pStudent current = *student;
    char index[6][20] = {"Chinese", "math", "English", "C programming", "Politics", "Engineering"};
    puts("输入你要查找到姓名");
    char search[10];
    s_gets(search, 10);
    puts("搜索结果：");
    printf("学号\t\t");
    printf("姓名\t\t");
    for (int i = 0; i < 6; i++)
    {
        if ((*student)->score[i] != 999)
            printf("%s\t", index[i]);
    }
    printf("\t");
    printf("总分\t\t");
    printf("排名\n");
    bool find = false;
    while (current)
    {
        //if find existing student information
        if (strstr(current->name, search))
        {
            find = true;
            printf("%s\t\t", current->id);
            printf("%s\t\t", current->name);
            for (int i = 0; i < 6; i++)
            {
                if (current->score[i] != 999)
                    printf("%.2lf\t", current->score[i]);
            }
            printf("\t");
            printf("%.2lf\t\t", current->TotalScore);
            printf("%d\n", current->rank);

        }
        current = current->next;
    }
    //cannot find information
    if (!find)
        puts("找不到结果");
}

void CalcuCategory(ppStudent student)
{
    if (!*student)
    {
        puts("请先录入成绩");
        return;
    }

    int classify[6][5] = {0}, total = 0;
    double portion[6][5] = {0};
    char index[][10] = {"优秀", "良好", "中等", "及格", "不及格"};
    char subject[][20] = {"Chinese", "math", "English", "C programming", "Politics", "Engineering"};
    pStudent current = *student;
    while (current)
    {
        total++;
        for (int i = 0; i < 6; i++)
        {

            if (current->score[i] != 999)
            {
                if (current->score[i] >= 90 && current->score[i] <= 100)
                    classify[i][0]++;
                else if (current->score[i] >= 80 && current->score[i] < 90)
                    classify[i][1]++;
                else if (current->score[i] >= 70 && current->score[i] < 80)
                    classify[i][2]++;
                else if (current->score[i] >= 60 && current->score[i] < 70)
                    classify[i][3]++;
                else
                    classify[i][4]++;
            }
        }

        current = current->next;
    }
    for (int i = 0; i < 6; i++)
    {
        if ((*student)->score[i] != 999)
        {
            for (int j = 0; j < 5; j++)
                portion[i][j] = (double) classify[i][j] / total;
        }
    }

    puts("总体数据：");
    printf("\t                  ");
    for (int i = 0; i < 5; i++)
        printf("%s                   ", index[i]);

    printf("\n");

    for (int i = 0; i < 6; i++)
    {
        if ((*student)->score[i] != 999)
        {
            printf("%15s:\t", subject[i]);
            for (int j = 0; j < 5; j++)
            {
                printf("人数：%d  占比：%.1lf     ", classify[i][j], portion[i][j]);
            }
            printf("\n");
        }
    }
    printf("\n");
}

void clean_cache()
{
    while (getchar() != '\n');
}