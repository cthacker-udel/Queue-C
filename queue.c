#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>

struct node{

    int value;
    struct node *next;
    struct node *previous;

};


struct node *HEAD = NULL;
struct node *TAIL = NULL;


void dequeue(){

    struct node *newNode = HEAD;
    if(HEAD->next == NULL){
        printf("\nLast node being removed\n");
        HEAD = NULL;
    }
    else{
        struct node *prevNode = HEAD->next;
        HEAD = NULL;
        HEAD = prevNode;
        prevNode->previous = NULL;
    }
}

void enqueue(int value){

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->value = value;
    TAIL->next = newNode;
    newNode->previous = TAIL;
    newNode->next = NULL;
    TAIL = newNode;

}

void printQueue(){

    struct node *currNode = HEAD;
    int nodeNum = 0;
    if(HEAD == NULL){
        printf("\nNo nodes available to print in queue\n");
    }
    else{
        while(currNode != NULL){
            printf("\nNODE %d : %d\n",nodeNum++,currNode->value);
            currNode = currNode->next;
        }
    }

}

void printMenu(){

    printf("\n\n~=~=~=MENU~=~=~=\n1)Print queue\n2)Enqueue\n3)Dequeue\n4)Exit program");

}

int main(void){

    int choice;
    int nodeval;
    while(1){
        printMenu();
        scanf("%d",&choice);
        switch(choice){

            case 1:
                printQueue();
                break;
            case 2:
                printf("\nEnter a node value to enqueue\n");
                scanf("%d",&nodeval);
                enqueue(nodeval);
                break;
            case 3:
                dequeue();
                break;
            default:
                return 0;
        }
    }

    return 0;

}