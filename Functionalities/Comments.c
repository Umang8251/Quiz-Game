#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Comments.h"

//Function to give comments based on each player's score
void Comment(int score)
{
        switch(score)
        {

        case 0:{
                printf("Your score is 0.Maybe you can do better next time.\n");
                break;
                }
        case 1:{
                printf("Your score is 1.Don't be discouraged by the result.Try again.\n");
                break;
                }
        case 2:{
                printf("Your score is 2.Better luck next time\n");
                break;
                }
        case 3:{
                printf("Your score is 3.Your performance needs significant improvement\n");
                break;
                }
        case 4:{
                printf("Your score is 4.An average performance\n");
                break;
                }
        case 5:{
                printf("Your score is 5.Well done!\n");
                break;
                }
        case 6:{
                printf("Your score is 6.Keep up the good work!\n");
                break;
                }
        case 7:{
                printf("Your score is 7.You absolutely nailed your performance!\n");
                break;
                }
        case 8:{
                printf("Your score is 8.An impressive performance!\n");
                break;
                }
        case 9:{
                printf("Your score is 9.Your performance was simply outstanding.\n");
                break;
                }
        case 10:{
                printf("Your score is 10.Your performance was absolutely exceptional.\n");
                break;
                }
        default:{break;}   
    }
}
