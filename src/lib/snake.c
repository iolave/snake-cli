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
        newNode->position = generateXyVector(0, 0);
        newNode->next = *snakeHead;
        *snakeHead = newNode;
        return;
    }
    
    // Setting new node values
    currentNode = *snakeHead;
    newNode->position = currentNode->position;
    
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
    tmpPosition = newSnake->position;
    newSnake->position = addXyVectors(newSnake->position, vector);

    // Single node snake
    if (newSnake->next == NULL) return;
    // Check if is a fed snake and then return because 
    // there's no need to shift the entire snake
    if (equalXyVectors(newSnake->position, newSnake->next->position)) return;

    // As the snake has not been fed, shift the rest 
    // of the snake
    newSnake = newSnake->next;
    while (newSnake != NULL) {
        tmpPosition2 = newSnake->position;
        newSnake->position = tmpPosition;
        tmpPosition = tmpPosition2;
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