//
// Created by sutaoyu on 2018/10/2.
//
#include<stdio.h>

void recomment(int c);
void in_comment(void);
void echo_quote(int c);
void start_comment();


int main()
{
    int c, d;
    while ((c = getchar()) != EOF)
    {
        recomment(c);
    }
    return 0;
}

//搜索注释的开始位置
void recomment(int c)
{
    int d;
    if (c == '/')
    {
        if ((d = getchar()) == '*')
        {
            in_comment();
        }
        else if (d == '/')
        {
            start_comment();
        }
        else
        {
            putchar(c);
            putchar(d);
        }
    }
    else if (c == '\'' || c == '"')
    {
        echo_quote(c);
    }
    else
    {
        putchar(c);
    }
}


//删除以"//"开始的注释
void start_comment()
{
    int c, d;
    while ((c = getchar()) != '\n')
        ;
    putchar(c);
}

//删除"/*    */"注释 
void in_comment()
{
    int c, d;
    c = getchar();
    d = getchar();
    while (c != '*' || d != '/')// 非/*情况
    {
        c = d;
        d = getchar();
    }
}

//保证引号里面的内容可以完整输出
void echo_quote(int c)
{
    int d;
    putchar(c);
    while ((d = getchar()) != c)
    {
        putchar(d);
        if (d == '\\')
        {
            putchar(getchar());
        }
    }
    putchar(d);
}
