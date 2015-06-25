#include<stdio.h>
#define MAXSIZE 3
//I am checking github for the first time.
struct stack //defined a structure which accounts for a node.
{
    int top;
    int Elements[MAXSIZE];
};
int push(int,struct stack*);
int pop(int *,struct stack*);
void display(int *,struct stack*);
int main()
{
    int n,flag=0,out,value,errorCode=0;
    struct stack object;
    object.top=-1;
    while(flag==0)
    {
        printf("\n\n\n--------------------------STACK--------------------------");
        printf("\n\n1.------------->Push in stack.");
        printf("\n\n2.------------->Pop out of stock.");
        printf("\n\n3.------------->Display stack.");
        printf("\n\n0.------------->Exit.");
        printf("\n\n-----------------------------------------------------------");
        printf("\n\n                      Input:");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            printf("\n\nPlease enter the value to be pushed:");
            scanf("%d",&value);
            errorCode=push(value,&object);
            if(errorCode==-1)
            {
                printf("\n\nSorry stack is full,first pop some values out.");
                errorCode=0;
            }
            else
            {
                printf("\n\tpushed successfully");
            }
            break;
        case 2:
            out=pop(&errorCode,&object);
            if(errorCode==-1)
            {
                errorCode=0;
                printf("\n\nSorry! stack is already empty,first insert some elements in stack.");
            }
            else
            {
                printf("\n\n\tPoped out element is:%d",out);
            }
            break;
        case 3:
            display(&errorCode,&object);
            if(errorCode==-1)
            {
                errorCode=0;
                printf("\n\nSorry! stack is already empty,first insert some elements in stack.");
            }
            break;
        case 0:
            flag=1;
            break;
        default:
            printf("\n\n\tWrong input!Try again.");
        }
        getch();
    }
    printf("\n\n\n\n\t\t\t\tThanks!");
}
int push(int value,struct stack* ob2)
{
    if(ob2->top<(MAXSIZE-1))
    {
        (ob2->top)++;
        ob2->Elements[ob2->top]=value;
    }
    else
    {
        return -1;
    }
}
int pop(int *error,struct stack* ob2)
{
    if(ob2->top==-1)
    {
        *error=-1;
    }
    else
    {
        (ob2->top)--;
        return ob2->Elements[(ob2->top)+1];
    }
}
void display(int *error,struct stack* ob2)
{
    int a;
    a=ob2->top;
    if(a==-1)
    {
        *error=-1;
    }
    else
    {
        printf("\n      :Displaying stack below:");
        while(a>=0)
        {
            printf("\n%d",ob2->Elements[a]);
            a--;
        }
    }
}
