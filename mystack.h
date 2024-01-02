#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 20

typedef struct stack1  //Structure to represent questions in the stack
{
	int top;
    char stackQ[MAX][500];
}STACK1;

typedef struct stack2  //Structure to represent answers in the stack
{
	int top;
    int stackAns[MAX];
}STACK2;
