#ifndef SNAKE_H_
#define SNAKE_H_

#include <stdlib.h>
#include "vector.h"

struct Snake {
    struct XYVector position;
    struct Snake *next;
};

void freeSnake(struct Snake **snake);
void feedSnake(struct Snake **snake);
void moveSnake(struct Snake **snake, struct XYVector vector);
int snakeLength(struct Snake *snake);

#endif
