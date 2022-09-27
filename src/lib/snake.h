#ifndef SNAKE_H_
#define SNAKE_H_

struct Snake {
    int x;
    int y;
    struct Snake *next;
};

void feedSnake(struct Snake **snake);
int snakeLength(struct Snake *snake);

#endif
