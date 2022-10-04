#include <stdlib.h>
#include "snake.h"

void freeSnake(struct Snake **snakeHead) {
    struct Snake *currentNode = NULL;

    while(*snakeHead != NULL){
        currentNode = *snakeHead;
        *snakeHead = currentNode->next;
        free(currentNode);
    }

    return;
}

void feedSnake(struct Snake **snakeHead) {
    struct Snake *newNode = malloc(sizeof(struct Snake));
    struct Snake *currentNode = NULL;

    if (*snakeHead == NULL) {
        newNode->x = 0;
        newNode->y = 0;
        newNode->next = *snakeHead;
        *snakeHead = newNode;
        return;
    }
    
    // Setting new node values
    currentNode = *snakeHead;
    newNode->x = currentNode->x;
    newNode->y = currentNode->y;
    
    // New node points to the rest of the snake
    newNode->next = *snakeHead;

    // The new node plus the given snake becomes the new snake
    *snakeHead = newNode;
    return;
}

#include <stdio.h>
void moveSnake(struct Snake **snake, struct XYVector vector) {
    struct Snake *newSnake = *snake;
    struct XYVector tmpPosition;
    struct XYVector tmpPosition2;

    // Change the head position given a XYVector
    tmpPosition.x = newSnake->x;
    tmpPosition.y = newSnake->y;
    newSnake->x = newSnake->x + vector.x;
    newSnake->y = newSnake->y + vector.y;
    newSnake = newSnake->next;


    while (newSnake != NULL) {
        tmpPosition2.x = newSnake->x;
        tmpPosition2.y = newSnake->y;
        newSnake->x = tmpPosition.x;
        newSnake->y = tmpPosition.y;
        tmpPosition.x = tmpPosition2.x;
        tmpPosition.y = tmpPosition2.y;
        newSnake = newSnake->next;
    }

    return;
}

int snakeLength(struct Snake *snakeHead) {
    int count = 0;

    while(snakeHead != NULL){
        count = count + 1;
        snakeHead = snakeHead->next;
    }

    return(count);
}