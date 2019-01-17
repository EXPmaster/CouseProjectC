#include "dataset.h"
#include "operation.h"
#include "list.h"

//constructed on Ubuntu 18.10
void menu();

int main()
{
    int operate;
    pStudent L;
    InitList(&L);
    puts("---------全国大学生成绩管理系统----------");
    while (true)
    {
        menu();
        while (!scanf("%d", &operate))
        {
            puts("错误指令，请重新输入");
            clean_cache();
        }
        clean_cache();
        switch (operate)
        {
            case 1:
                GetInfo(&L);
                break;

            case 2:
                CalcuAll(&L);
                break;

            case 3:
                CalcuSingle(&L);
                break;

            case 4:
                ArrangeScore(&L);
                break;

            case 5:
                ArrangeID(&L);
                break;

            case 6:
                ArrangeName(&L);
                break;

            case 7:
                SearchID(&L);
                break;

            case 8:
                SearchName(&L);
                break;

            case 9:
                CalcuCategory(&L);
                break;

            case 10:
                Traverse(L);
                break;

            case 11:
                Output_to_file(&L);
                break;

            case 12:
                GetFile(&L);
                Traverse(L);
                break;

            case 13:
                puts("退出系统成功");
                ClearList(&L);
                if(!L)
                    puts("list cleared successfully");
                return 0;


            default:
                puts("没有该指令");
        }
        printf("\n\n\n\n\n");
    }
}

void menu()
{
    puts("             菜单");
    puts("请输入指令进行相应操作：");
    puts("（1）录入学生学号、姓名和各科考试成绩；");
    puts("（2）计算每门课程的所有学生的总分和平均分；");
    puts("（3）计算每个学生所有科目的总分和平均分；");
    puts("（4）按每个学生的总分由高到低排出名次表；");
    puts("（5）按学号由小到大排出成绩表；");
    puts("（6）按姓名的字典顺序排出成绩表；");
    puts("（7）按学号查询学生排名及其考试成绩；");
    puts("（8）按姓名查询学生排名及其考试成绩；");
    puts("（9）按优秀（90-100）、良好（80-89）、中等（70-79）、"
         "及格（60-69）、不及格（0-59）5个类别，对每门课程分别统计各类别人数和所占比例；");
    puts("（10）输出每个学生学号、姓名、各科考试成绩和总分及排名；");
    puts("（11）学生记录信息写入文件；");
    puts("（12）从文件中读出学生记录信息并显示；");
    puts("（13）退出系统");
    puts("-------------------------------");
}