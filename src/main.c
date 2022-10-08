#include <stdio.h>
#include <unistd.h>
#include <curses.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "lib/snake.h"
#include "game/validations.c"
#include "controllers/keyboard.c"

#define BOX_CHAR 'U+1'

struct XYVector normalizePlanePoint(struct XYVector point, struct XYVector screenDims) {
    struct XYVector normalizedPoint;

    normalizedPoint.x = (screenDims.x / 2) + point.x;
    normalizedPoint.y = (screenDims.y / 2) + (point.y * -1);

    return normalizedPoint;
}

// TODO remove or move to another file
#define GAME_SPEED 100000
int main() {
    struct Snake *snakeHead = NULL;
    struct Snake *snakePtr = NULL;
    struct XYVector direction;
    struct XYVector directionTmp;
    struct XYVector currentPos;
    struct XYVector gameBoundaries;
    struct XYVector snakeHeadPosNorm;
    int ch;

    static const char quitMsg[] = "Press Q to Quit";
    /* Game initialization */
    // Adding snake's first node
    feedSnake(&snakeHead);
    // Default direction vector (0, 0)
    direction = calculateDirection(-1);

    /* Game UI initizaliation */
    initscr();
    nodelay(stdscr, TRUE);
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);

    /* Game loop */
    do {
        erase();

        gameBoundaries = generateXyVector(COLS, LINES);

        mvaddstr(LINES-1, (COLS-strlen(quitMsg))/2, quitMsg);
        
        // If a key has been pressed, calculate a direction
        ch = getch();
        if (ch != -1) {
            directionTmp = calculateDirection(ch);
            if (!equalXyVectors(directionTmp, generateXyVector(0,0))) {
                direction = directionTmp;
                feedSnake(&snakeHead);
            }
        }
    
        snakePtr = snakeHead;
        while(snakePtr != NULL) {
            
            currentPos = normalizePlanePoint(snakePtr->position, gameBoundaries);
            // printw("(%d, %d)", currentPos.x, currentPos.y);
            mvaddch(currentPos.y, currentPos.x, BOX_CHAR);
            mvaddch(currentPos.y, currentPos.x-1, BOX_CHAR);

            // mvprintw(currentPos.y, currentPos.x, "*");
            snakePtr = snakePtr->next;
            refresh();
        }
        usleep(20000);
        printw("\n");
        refresh();

        moveSnake(&snakeHead, direction);
        snakeHeadPosNorm = normalizePlanePoint(snakeHead->position, gameBoundaries);
        if(!validateNodePosition(snakeHeadPosNorm, gameBoundaries)) {
            endwin();
            freeSnake(&snakeHead);
            return 0;
        }
    } while(true);
    return 0;
}


// static const char quitMsg[] = "Press Q to Quit";
// static const char startMsg[] = "Press any key to start";

// mvaddstr(maxPos.y-1, (maxPos.x-strlen(startMsg))/2, startMsg);
// mvaddstr(maxPos.y-1, (maxPos.x-strlen(quitMsg))/2, quitMsg);

// //     /* and msg centered at the bottom. */
// //     mvaddstr(maxPos.y-1, (maxPos.x-strlen(msg))/2, msg);

// // } while (c != 'Q' && c != 'q');