#ifndef SNAKE_H_
#define SNAKE_H_

struct XYVector {
    int x;
    int y;
};

struct Snake {
    struct XYVector position;
    struct Snake *next;
};

struct XYVector generateXyVector(int x, int y);
struct XYVector addXyVectors(struct XYVector vector1, struct XYVector vector2);
void freeSnake(struct Snake **snake);
void feedSnake(struct Snake **snake);
void moveSnake(struct Snake **snake, struct XYVector vector);
int snakeLength(struct Snake *snake);

#endif
