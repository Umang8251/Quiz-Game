#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct priorityqueue {
    int player;
    int score;
    struct priorityqueue* next;
};
typedef struct priorityqueue QUEUE;
void leaderboard(int* a);
QUEUE* createqueue(QUEUE* head, int score,int player);
void prioritydisplay(QUEUE* queuedisplay);
void freequeue(QUEUE* head);