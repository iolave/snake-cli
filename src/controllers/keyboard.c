#include "../include/vector.h"

#define CONTROLLER_UP 259
#define CONTROLLER_DOWN 258
#define CONTROLLER_LEFT 260
#define CONTROLLER_RIGHT 261

struct XYVector calculateVector(int keystroke) {
    struct XYVector vector;
    vector.x = 0;
    vector.y = 0;

    if (keystroke == CONTROLLER_UP) vector.y = 1;
    else if (keystroke == CONTROLLER_DOWN) vector.y = -1;
    else if (keystroke == CONTROLLER_LEFT) vector.x = -1;
    else if (keystroke == CONTROLLER_RIGHT) vector.x = 1;

    return vector;
}