#include <stdlib.h>
#include <stdio.h>
#include "snake.h"

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

int snakeLength(struct Snake *snake) {
    int count = 0;

    while(snake != NULL){
        count = count + 1;
        snake = snake->next;
    }

    return(count);
}