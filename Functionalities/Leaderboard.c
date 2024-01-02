#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"Leaderboard.h"
void leaderboard(int *a)
{
    int playnum=3;
    QUEUE* queueplay = NULL;

    // Initialize the queue
    for (int i = 0; i < playnum; i++) {
        queueplay = createqueue(queueplay,a[i],i+1);
    }

    // Display the priority queue
    prioritydisplay(queueplay);

    // Free the allocated memory
    freequeue(queueplay);
}

QUEUE* createqueue(QUEUE* head,int score,int player) {
    // Create a new node
    QUEUE* newPlayer = (QUEUE*)malloc(sizeof(QUEUE));
    if (newPlayer == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newPlayer->player = player;
    newPlayer->score = score;
    newPlayer->next = NULL;

    // Insert the new node in the priority queue based on score
    if (head == NULL || score > head->score) {
        newPlayer->next = head;
        head = newPlayer;
    } else {
        QUEUE* current = head;
        while (current->next != NULL && score <= current->next->score) {
            current = current->next;
        }
        newPlayer->next = current->next;
        current->next = newPlayer;
    }

    return head;
}

void prioritydisplay(QUEUE* queuedisplay) {
    QUEUE* temp = queuedisplay;
    printf("\nPlayer\tScore\n");
    while (temp != NULL) {
        printf("%d\t\t\t%d\n", temp->player, temp->score);
        temp = temp->next;
    }
}

void freequeue(QUEUE* head) {
    while (head != NULL) {
        QUEUE* temp = head;
        head = head->next;
        free(temp);
    }
}