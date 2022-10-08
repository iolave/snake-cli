#include <stdio.h>
#include "../../src/lib/snake.h"

struct Snake * generateSingleNodeSnake(void) {
    struct Snake *snakeHead = NULL;

    feedSnake(&snakeHead);

    // Making sure the node position is (0, 0)
    snakeHead->position.x = 0;
    snakeHead->position.y = 0;
    
    return snakeHead;
}

struct Snake * generateMultipleNodesSnake(int qty) {
    struct Snake *snakeHead = NULL;
    int i;

    if (qty <= 0) return NULL;
    if (qty == 1) return generateSingleNodeSnake();

    // Simple for loop to grow the snake qty times
    for (i = 0;i < qty;i = i + 1) {
        // Growing the snake
        feedSnake(&snakeHead);
        snakeHead->position.x = i;
        snakeHead->position.y = 0;
    }

    return snakeHead;
}