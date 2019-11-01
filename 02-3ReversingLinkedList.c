/*
这块的内容比较偷懒，基本上是通过栈的先进后出和链表的组合来实现序列的反转，所以分数也不是满分，
测试点5 最大N,最后剩K-1不反转 和
测试点6 有多余结点不在链表上 的分数并没有拿到。
最后分数是21/25。
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node * List;
typedef struct SNode * Stack;

struct Node
{
    int address;
    int data;
    int next;
    List link;
};

struct SNode
{
    int address;
    int data;
    int next;
    Stack link;
};


int main()
{
    List L,L1,L2,L3;
    List T,T1,T2;
    List R;
    L=(List)malloc(sizeof(struct Node));
    L->link=NULL;
    L1=L;
    int start;
    int number;
    int task;
    scanf("%d %d %d",&start,&number,&task);
    for(int i=0;i<number;i++)
    {
        T=(List)malloc(sizeof(struct Node));
        scanf("%d %d %d",&T->address,&T->data,&T->next);
        L1->link=T;
        L1=T;
        T->link=NULL;
    }
    L1->link=NULL;
    T1=L;
    L=L->link;
    free(T1);
   /*    while(L)        //测试代码
        {
            printf("%d %d %d\n",L->address,L->data,L->next);
            L=L->link;
        }*/

/*排序*/
    List c;
    c=(List)malloc(sizeof(struct Node));
    L3=c;
    c->link=NULL;
    for(int i=0;i<number;i++)
    {
        L2=L;
        for(int j=0;j<number;j++)
        {
          if(i==0)
          {
              if(L2->address==start )
              {
                T2=(List)malloc(sizeof(struct Node));
                T2->address=L2->address;
                T2->data=L2->data;
                T2->next=L2->next;
                L3->link=T2;
                T2->link=NULL;
                L3=T2;
                L2=L2->link;
                break;
              }
              else
              {
                  L2=L2->link;
              }
          }
          else
          {
              if(L2->address==L3->next)
              {
                  T2=(List)malloc(sizeof(struct Node));
                  T2->address=L2->address;
                  T2->data=L2->data;
                  T2->next=L2->next;
                  L3->link=T2;
                  L3=T2;
                  T2->link=NULL;
                  L2=L2->link;
                  break;
              }
              else
              {
                  L2=L2->link;
              }
          }
        }
    }

/*    c=c->link;
           while(c)        //测试代码
        {
            printf("\n");
            printf("%d %d %d\n",c->address,c->data,c->next);
            c=c->link;
        }
*/

//翻转
    Stack S,S1;
    List L4,L5,L6;
    List T3;
    c=c->link;
    L4=c;
    R=(List)malloc(sizeof(struct Node));
    R->link=NULL;
    L5=R;
    int limit;
    int count;
    limit=number/task;
    if(number>=task)
    {
        for(int i=0; i<limit;i++)
        {
            count=0;
            S=(Stack)malloc(sizeof(struct SNode));
            S->link=NULL;
            S1=S;
                for(int j=0;j<task;j++)
                {
                    if(L4)
                    {
                        S1=(Stack)malloc(sizeof(struct SNode));
                        S1->address=L4->address;
                        S1->next=L4->next;
                        S1->data=L4->data;
                        S1->link=S->link;
                        S->link=S1;
                        L4=L4->link;
                        count++;
                    }
                    else
                    {
                        break;
                    }
                }
                if(count==task)
                {
                    while(S->link)
                    {
                        T3=(List)malloc(sizeof(struct Node));
                        T3->address=S->link->address;
                        T3->data=S->link->data;
                        T3->next=S->link->next;
                        L5->link=T3;
                        L5=T3;
                        T3->link=NULL;
                        S=S->link;
                    }
                }
            }
    }
    while(L4)
    {
        T3=(List)malloc(sizeof(struct Node));
        T3->address=L4->address;
        T3->data=L4->data;
        T3->next=L4->next;
        L5->link=T3;
        L5=T3;
        T3->link=NULL;
        L4=L4->link;
    }
    L6=R->link;
    while(L6)
    {
        int temp;
        if(L6->link)
        {
            temp=L6->link->address;
        }
        else
        {
            temp=-1;
        }
        L6->next=temp;
        L6=L6->link;
    }
    R=R->link;
          while(R)        //测试代码
        {
            if(R->link)
            {
             printf("%05d %d %05d\n",R->address,R->data,R->next);
            }
            else
            {
                printf("%05d %d %d\n",R->address,R->data,R->next);
            }
            R=R->link;
        }
    return 0;
}

