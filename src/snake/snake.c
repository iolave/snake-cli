#include <stdlib.h>

struct Snake {
    int x;
    int y;
    struct Snake *next;
};

void feedSnake(struct Snake **snake) {
    // Creating a new snake node
    struct Snake *newNode = malloc(sizeof(struct Snake));
    
    // Setting new node values
    newNode->x = 0;
    newNode->y = 0;
    
    // New node points to the rest of the snake
    newNode->next = *snake;

    // The new node plus the given snake becomes the new snake
    *snake = newNode;
}

int snakeLength(struct Snake *snake) {
    int count = 0;

    while(snake != NULL){
        count = count + 1;
        snake = snake->next;
    }

    return(count);
}