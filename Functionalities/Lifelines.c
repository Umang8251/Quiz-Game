#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Lifelines.h"

int fiftyfifty(int question,STACK2 *ptr)
{
    //get the question no and the answer corresponding to it.
    int userAns; 
    int ans=peepAns(ptr);
    printf("Choose between options %d and 3\n",ans);
    scanf("%d",&userAns);   
    return userAns;
}

int watson(int question)  //need to give hints for each question
{
    int userAns;
    switch(question)   //printing a hint related to the answer
    {
        case 1: printf("Hint: The hint for the question is to think about which operation in a stack data structure is specifically designed to remove an item from the top of the stack. This operation is commonly used to access and remove the most recently added element.\n"); break;
        case 2: printf("Hint: The primary purpose of a priority queue is to maintain elements based on their priority, ensuring efficient retrieval of the highest-priority element. It is not about maintaining elements in a FIFO, LIFO, or sorted order. So, the hint is to focus on the concept of priority and how the data structure organizes elements based on it.\n"); break;
        case 3: printf("Hint : Consider the structure of a balanced binary search tree, which typically has a height of O(log n) for n elements.In the worst case, the time complexity to search for an element in a balanced binary search tree is determined by its height, which is O(log n), not O(n*2^n).\n"); break;
        case 4: printf("Hint : Min-Heap is a specific type of binary heap used in data structures, and it has a particular property regarding the order of its elements.Consider the definition of a complete binary tree and how it relates to the properties of a min-heap. Determine if a min-heap is always a complete binary tree or not.\n"); break;
        case 5: printf("Hint : Consider the nature of a circularly linked list and how you can optimize enQueue and deQueue operations with a single pointer.Think about the role of the pointer 'p' in managing the queue and which node it should point to in order to support constant-time enQueue and deQueue operations.\n"); break;
        case 6: printf("Hint : Clustering in a hash table occurs when multiple keys map to the same index, often leading to inefficient performance. Consider how different hash functions distribute keys.Focus on the characteristics of each hash function and assess how they might lead to clustering. Specifically, consider the distribution of keys and the likelihood of collisions.\n"); break;
        case 7: printf("Hint : Consider the characteristics of a directed acyclic graph (DAG) and how it relates to various scenarios and their specific requirements.Think about scenarios where there should be no cycles in the graph and the relationships between elements have a clear direction, making a DAG most suitable.\n"); break;
        case 8: printf("Hint : To find the number of binary trees with unlabeled nodes, you can consider the concept of Catalan numbers and the ways to arrange nodes.Use combinatorics to determine how many different binary trees you can construct with three unlabeled nodes. Consider the different structures and arrangements.\n"); break;
        case 9: printf(" Hint : Consider the definitions and properties of complete and full binary trees. Think about whether one implies the other or if they can exist independently.Full binary trees and complete binary trees have distinct characteristics. Pay attention to the definitions and properties of each to determine which statement is true.\n"); break;
        case 10: printf(") Hint : Think about how you can use stacks to mimic the behavior of a queue. One stack might not be sufficient for this purpose.To implement a queue using stacks, you may need two stacks to handle enqueue and dequeue operations efficiently.\n"); break;
        default: break;
    }
    printf("Enter your answer\n");
    scanf("%d",&userAns);
    return userAns;
}

int doubleDip(int question,STACK2 *ptr,int times)
{    
    int userAns;
    if(times==2)
    {
        printf("You have been given one more chance to answer this question.\n");
        printf("Enter your answer\n");
        scanf("%d",&userAns);
        return userAns;
    }
    printf("Enter your answer\n");
    scanf("%d",&userAns);
    if(userAns==peepAns(ptr))
    {
        return userAns;
    }
    else
    {
        doubleDip(question,ptr,2);
    }   
}

int lifelines(int question,STACK2* ptr)
{
    int choice,userAns;   
    printf("Enter the number corresponding to the lifeline\n");
    printf("1.50-50\n2.Elementary Watson\n3.Double Dip\n");
    scanf("%d",&choice);
    
        switch(choice)
        {
            case 1: printf("You have now activated the Fifty-Fifty lifeline.\n");
                    userAns=fiftyfifty(question,ptr);
                    break;
            case 2: printf("You have now activated the Elementary Watson lifeline.\n");
                    userAns=watson(question);
                    break;
            case 3: printf("You have now activated the Double Dip lifeline. This allows you to answer this question one more time\n");
                    userAns=doubleDip(question,ptr,1);
                    break;
            default: printf("Enter valid number");
        }
    
    return userAns;
}
