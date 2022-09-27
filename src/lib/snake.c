#include <stdlib.h>
#include <stdio.h>
#include "snake.h"

void freeSnake(struct Snake *snakeHead) {
    printf("%p\n", snakeHead);
    struct Snake *currentNode;

    while(snakeHead != NULL){
        currentNode = snakeHead;
        snakeHead = snakeHead->next;
        free(currentNode);
    }
}

void feedSnake(struct Snake **snakeHead) {
    // Creating a new snake node
    struct Snake *newNode = malloc(sizeof(struct Snake));
    
    // Setting new node values
    newNode->x = 0;
    newNode->y = 0;
    
    // New node points to the rest of the snake
    newNode->next = *snakeHead;

    // The new node plus the given snake becomes the new snake
    *snakeHead = newNode;
}

int snakeLength(struct Snake *snakeHead) {
    int count = 0;

    while(snakeHead != NULL){
        count = count + 1;
        snakeHead = snakeHead->next;
    }

    return(count);
}