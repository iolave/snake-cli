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
        newNode->position.x = 0;
        newNode->position.y = 0;
        newNode->next = *snakeHead;
        *snakeHead = newNode;
        return;
    }
    
    // Setting new node values
    currentNode = *snakeHead;
    newNode->position.x = currentNode->position.x;
    newNode->position.y = currentNode->position.y;
    
    // New node points to the rest of the snake
    newNode->next = *snakeHead;

    // The new node plus the given snake becomes the new snake
    *snakeHead = newNode;
    return;
}

void moveSnake(struct Snake **snake, struct XYVector vector) {
    struct Snake *newSnake = *snake;
    struct XYVector tmpPosition;
    struct XYVector tmpPosition2;

    // Change the head position given a XYVector
    tmpPosition.x = newSnake->position.x;
    tmpPosition.y = newSnake->position.y;
    newSnake->position.x = newSnake->position.x + vector.x;
    newSnake->position.y = newSnake->position.y + vector.y;

    newSnake = newSnake->next;
    // Single node snake
    if (newSnake == NULL) return;
    // Check if is a fed snake and then return because 
    // there's no need to shift the entire snake
    if (tmpPosition.x == newSnake->next->position.x && tmpPosition.y == newSnake->next->position.y) return;

    // As the snake has not been fed, shift the rest 
    // of the snake
    while (newSnake != NULL) {
        tmpPosition2.x = newSnake->position.x;
        tmpPosition2.y = newSnake->position.y;
        newSnake->position.x = tmpPosition.x;
        newSnake->position.y = tmpPosition.y;
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