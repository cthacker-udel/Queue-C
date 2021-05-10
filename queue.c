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



int main(void){



    return 0;

}