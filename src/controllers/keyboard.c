#include <snake.h>

#define CONTROLLER_UP 259
#define CONTROLLER_DOWN 258
#define CONTROLLER_LEFT 260
#define CONTROLLER_RIGHT 261

struct XYVector calculateDirection(int keystroke) {
    struct XYVector vector;
    vector = generateXyVector(0, 0);

    if (keystroke == CONTROLLER_UP) vector.y = 1;
    else if (keystroke == CONTROLLER_DOWN) vector.y = -1;
    else if (keystroke == CONTROLLER_LEFT) vector.x = -2;
    else if (keystroke == CONTROLLER_RIGHT) vector.x = 2;

    return vector;
} 