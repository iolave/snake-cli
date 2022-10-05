#include <stdlib.h>
#include "snake.h"

struct XYVector generateXyVector(int x, int y) {
    struct XYVector point;
    point.x = x;
    point.y = y;

    return(point);
}

struct XYVector addXyVectors(struct XYVector vector1, struct XYVector vector2) {
    struct XYVector newXyVector;

    newXyVector.x = vector1.x + vector2.x;
    newXyVector.y = vector1.y + vector2.y;

    return newXyVector;
}

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

    newSnake = newSnake->next;
    // Single node snake
    if (newSnake == NULL) return;
    // Check if is a fed snake and then return because 
    // there's no need to shift the entire snake
    if (tmpPosition.x == newSnake->next->position.x && tmpPosition.y == newSnake->next->position.y) return;

    // As the snake has not been fed, shift the rest 
    // of the snake
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