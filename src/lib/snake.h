#ifndef SNAKE_H_
#define SNAKE_H_

struct Snake {
    int x;
    int y;
    struct Snake *next;
};

void freeSnake(struct Snake *snake);
void feedSnake(struct Snake **snake);
int snakeLength(struct Snake *snake);

#endif
