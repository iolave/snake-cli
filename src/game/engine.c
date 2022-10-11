#include <curses.h>
#include <signal.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>


#include "../lib/snake.h"
#include "validations.c"
#include "../controllers/keyboard.c"

#define CH_SNAKE 'U+1'
#define CH_QUIT 81

void gameSignalHandler(int sig);
void gameSetup(void);
void gameDestroy(void);
void doGame(void);

void gameSignalHandler(int sig) {
    if (sig == SIGINT) {
        gameDestroy();
        exit(sig);
    }
}

void gameSetup(void) {
    struct sigaction act;

    act.sa_handler = gameSignalHandler;
    sigaction(SIGINT, &act, NULL);

    initscr();
    cbreak();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    return;
}

void gameDestroy(void) {
    endwin();
}

struct XYVector normalizePlanePoint(struct XYVector point, struct XYVector screenDims) {
    struct XYVector normalizedPoint;

    normalizedPoint.x = (screenDims.x / 2) + point.x;
    normalizedPoint.y = (screenDims.y / 2) + (point.y * -1);

    return normalizedPoint;
}

void doGame(void) {
    useconds_t gameSpeed;
    int ch;
    struct Snake *snakeHead = NULL;
    struct Snake *snakePtr = NULL;
    struct XYVector direction;
    struct XYVector directionTmp;
    struct XYVector currentPos;
    struct XYVector gameBoundaries;
    struct XYVector snakeHeadPosNorm;
    struct XYVector snakeTailPosNorm;
    struct Snake *snakeTail = NULL;
    static const char quitMsg[] = "Press Q to Quit";

    gameSetup();
    gameSpeed = 20000;

    /* Game initialization */
    // Adding snake's first node
    feedSnake(&snakeHead);
    // Default direction vector (0, 0)
    direction = calculateDirection(-1);
    snakeTail = snakeHead;


    do {
        gameBoundaries = generateXyVector(COLS, LINES);
        mvaddstr(gameBoundaries.y-1, (gameBoundaries.x-strlen(quitMsg))/2, quitMsg);
        // If a key has been pressed, calculate a direction
        ch = getch();

        if (ch != -1) {
            directionTmp = calculateDirection(ch);
            if (!equalXyVectors(directionTmp, generateXyVector(0,0))) {
                direction = directionTmp;
                feedSnake(&snakeHead);
            }
        }
    
        // print snake
        snakePtr = snakeHead;
        while(snakePtr != NULL) {
            currentPos = normalizePlanePoint(snakePtr->position, gameBoundaries);
            mvaddch(currentPos.y, currentPos.x, CH_SNAKE);
            mvaddch(currentPos.y, currentPos.x-1, CH_SNAKE);
            if(snakePtr->next == NULL) {
                mvaddch(currentPos.y, currentPos.x, ' ');
                mvaddch(currentPos.y, currentPos.x-1, ' ');
            }
            snakePtr = snakePtr->next;
        }
        usleep(gameSpeed);
        refresh();

        

        moveSnake(&snakeHead, direction);
        snakeHeadPosNorm = normalizePlanePoint(snakeHead->position, gameBoundaries);
        if(!validateNodePosition(snakeHeadPosNorm, gameBoundaries)) {
            gameDestroy();
            freeSnake(&snakeHead);
            exit(EXIT_SUCCESS);
        }
        
    } while (toupper(ch) != CH_QUIT);

    gameDestroy();

    exit(EXIT_SUCCESS);
}