//Why stack suits our problem statement
//1.Question Popping - we can get the most recent question by popping it from the top of the stack
//2.LIFO - focus on the most recent questions and prioritize questions that have been added more recently.
//3.Efficient Memory Usage - as we only access the top element of stack not all the elements.Can be more advantageous in a resource-constrained environment.
//4.Simplified Logic - LIFO nature of stack is simpler when dealing with sequential processes.
//5.Dynamic Question Handling:Using a stack allows for dynamic handling of questions. Questions can be pushed onto the stack as they are presented, and popping questions off the stack corresponds to the natural flow of the quiz as users progress.
//6.Lifeline Support:The stack is also used for managing lifelines, providing additional support for users who may need assistance during the quiz.

//This file has the contents of the real quiz_main.c
#include<stdio.h>    
#include<string.h>
#include<stdlib.h>
#include "quiz_main.h"
#include"Leaderboard.h"
int a[3];   //global variable/array

void push1(STACK1 *ptr,char* a)
{
    if(ptr->top==MAX-1)//overflow conditon
	{
		printf("stack overflow\n");
	}
	else
	{
		
		strcpy(ptr->stackQ[++(ptr->top)],a);
    }
  
}

void push2(STACK2 *ptr,int a)
{
    if(ptr->top==MAX-1)//overflow conditon
	{
		printf("stack overflow\n");
	}
	else
	{
		
		ptr->stackAns[++(ptr->top)]=a;
    }
  
}

char* pop1(STACK1 *ptr)
{
    if(ptr->top==-1)
		return "\0";
	else
		return(ptr->stackQ[ptr->top--]);
}

void pop2(STACK2 *ptr)
{
        ptr->top--;
}

int peepAns(STACK2 *ptr)   //used in lifelines
{
    if(ptr->top==-1)
        return -1;
    else    
        return(ptr->stackAns[ptr->top]);
}

void displayrules()
{
    printf("\nDisplaying the rules here");
    printf("\n\n\n\tThis game is very easy to play. You'll be asked some dsa related");
    printf("\n\n\tQuestions and the right answer is to be chosen among");
    printf("\n\n\tThe four options provided. Your score will be calculated at the end.");
    printf("\n\n\tYour score will be calculated and displayed at the end.");
    printf("\n\n\tIf you secure highest score, your score will be recorded.");
    printf("\n\n\tSo BEST OF LUCK.");
    printf("\n\n\n");
    
}

int quizgame()
{
	printf("A miniproject brought to you by\nUmang and Namita\n");
	printf("A quizeria using STACK as the data structure to pop the first and most valued question at last.\n");
    STACK1 *ptr1=NULL,s1;//Declaring
	ptr1=&s1;
	s1.top=-1;
    STACK2 *ptr2=NULL,s2;
	ptr2=&s2;
	s2.top=-1;
	int points=0,i,ans;
	char name[30];
    int maxscore[100];

    char q10[] ="[10]How many stacks are needed to implement a queue. Consider the situation where no other data structure like arrays,linked list is available to you.1) 1\t2) 2\t3) 3\t4) 4";
    char q9[] ="[9]Which of the following is true about Binary Trees?\t1) Every binary tree is either complete or full.\t\t2) Every complete binary tree is also a full binary tree.\t3) Every full binary tree is also a \tcomplete binary tree.\t4) None of the above";
    char q8[] ="[8]The maximum number of binary trees that can be formed with three unlabelled nodes is:\t1)1\t2)5\t3) 4\t4) 3";
    char q7[] ="[7]In which scenario would a directed acyclic graph (DAG) be most suitable?\t1) Representing \t\tdependencies between tasks in a project schedule\t2) Modeling a social network with friend connections\t3) Finding the shortest path between two nodes in a weighted graph\t4) Performing breadth-first search (BFS) on a graph";
    char q6[] ="[6]Which of the following hash functions is most likely to cause clustering in a hash table?\t\t\t\t\t 1) h(k) = k % m\t2) h(k) = floor(m * (kA mod 1))\t3) h(k) = k\t4) h(k) = ((k / m) + k * m) + k % m";
    char q5[] ="[5]A circularly linked list is used to represent a Queue. A single variable p is used to access the Queue. To \twhich node should p point such that both the operations enQueue and deQueue can be performed in \tconstant time?  (GATE 2004) \t1) rear node\t2) front node\t3) not possible with a single pointer\t4) node next to front";
    char q4[] ="[4]A min-Heap is a complete binary tree.\t1) True\t2) False\t3) all of these\t4) none of these";
    char q3[] ="[3]The worst case running time to search for an element in a balanced in a binary search tree with n*2^n \telements is\t1) O(n logn)\t2) O(n*2^n)\t3) O(n)\t4) O(logn)";
    char q2[] ="[2]What is the primary purpose of a priority queue?\t1) To maintain elements in a first-in, first-out (FIFO) order.\t2) To maintain elements in a last-in, first-out (LIFO) order.\t3) To maintain elements based on their priority, ensuring efficient retrieval of the highest-priority element.\t4) To maintain elements in sorted order.";
    char q1[] ="[1]In a stack data structure, which operation allows you to remove an item from the top of the stack?\t\t1) Push \t2) Pop\t3) Peek\t4) Insert";

    //Write the questions
    push1(ptr1,q10);
    push1(ptr1,q9);
    push1(ptr1,q8);
    push1(ptr1,q7);
    push1(ptr1,q6);
    push1(ptr1,q5);
    push1(ptr1,q4);
    push1(ptr1,q3);
    push1(ptr1,q2);
    push1(ptr1,q1);


    //Write the answers
	push2(ptr2,2);
    push2(ptr2,4);
    push2(ptr2,2);
    push2(ptr2,1);
    push2(ptr2,1);
    push2(ptr2,1);
    push2(ptr2,1);
    push2(ptr2,4);
    push2(ptr2,2);
    push2(ptr2,2);

	

	printf("\nWelcome to Quizeria.\n");
	printf("Enter your name.  \n");
	scanf("%s",name);
    printf("Hello ");
	printf(name);
    
    for(i=1;i<=10;i++)
	{
		printf("\n\nThis question is for 1 point\n");		
        char* q= pop1(ptr1);
        printf("%s\n",q);
        printf("Do you need a lifeline? Press 505 to activate lifelines\n");
		printf("Enter your ans.\n");
		scanf("%d",&ans);
		if(ans==peepAns(ptr2))
		{
			points=points+1;
			printf("Congrats!!!\t You earn %d points\n",points);
		}

        else if(ans==505)
        {
            int userAns=lifelines(i,ptr2); //args are question no. and stack ptr
            if(userAns==peepAns(ptr2) || userAns==10)
            {
                points=points+1;
			    printf("Congrats!!!\t You earn %d points\n",points);
            }               
            else if(userAns==20)
            {
                printf("Sorry, Game Over\n");
                break;
            }   
            else
            {
                printf("Sorry, Game Over\n");
                break;
            }             
        }

		else if(ans==0)
		{
			printf("You chose to quit\n");
			//exit(1);
			break;
		}

		else
		{
			printf("Sorry, game over . \n");
			break;
		}
        pop2(ptr2);   //pop out the ans and change top position to next answer's index

    }
    Comment(points);
    return points;
}

int main()
{
    int i;
    displayrules();
    //For executing multiplayer
    for(i=0;i<3;i++)
    {
        printf("\nEnter Player %d\n",i+1);
        a[i]=quizgame();
        printf("\n---------------------------------------------------------------------\n");
    }
    max_score(a);
    leaderboard(a);
    return 0;
}
  

