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
#define CH_ENTER 10

void cursesSignalHandler(int sig);
void cursesSetup(void);
void cursesDestroy(void);
int cursesScreenManagement(void);
int cursesScreenMain(void);
int cursesScreenPlay(void);

void cursesSignalHandler(int sig) {
    if (sig == SIGINT) {
        cursesDestroy();
        exit(sig);
    }
}

void cursesSetup(void) {
    struct sigaction act;

    act.sa_handler = cursesSignalHandler;
    sigaction(SIGINT, &act, NULL);

    initscr();
    cbreak();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    erase();

    return;
}

void cursesDestroy(void) {
    endwin();
}

int cursesScreenManagement(void) {
    int returnCodeScreenMain = -1;
    int returnCodeScreenPlay = -1;

    returnCodeScreenMain = cursesScreenMain();
    if (returnCodeScreenMain == EXIT_FAILURE) return EXIT_SUCCESS;
    
    returnCodeScreenPlay = cursesScreenPlay();
    if(returnCodeScreenPlay == EXIT_SUCCESS) return EXIT_SUCCESS;
    if(returnCodeScreenPlay == EXIT_FAILURE) return EXIT_FAILURE;

    return EXIT_FAILURE;
}

int cursesScreenMain(void) {
    static const char msgStart[] = "Press ENTER to start";
    static const char msgQuit[] = "Press Q to quit";
    struct XYVector cursesScreenSize;
    int ch;

    cursesSetup();
    cursesScreenSize = generateXyVector(COLS, LINES);

    do {
        ch = getch();
        mvprintw(cursesScreenSize.y/2-1, (cursesScreenSize.x/2) - strlen(msgStart)/2, "%s", msgStart);
        mvprintw(cursesScreenSize.y/2+1, (cursesScreenSize.x/2) - strlen(msgQuit)/2, "%s", msgQuit);
    } while(ch == -1);

    cursesDestroy();

    if (ch == CH_ENTER) return EXIT_SUCCESS;
    if (toupper(ch) == CH_QUIT) return EXIT_FAILURE;
    
    return EXIT_FAILURE;
}

struct XYVector normalizePlanePoint(struct XYVector point, struct XYVector screenDims) {
    struct XYVector normalizedPoint;

    normalizedPoint.x = (screenDims.x / 2) + point.x;
    normalizedPoint.y = (screenDims.y / 2) + (point.y * -1);

    return normalizedPoint;
}

int cursesScreenPlay(void) {
    useconds_t gameSpeed;
    int ch;
    struct XYVector gameBoundaries;
    struct XYVector screenBoundaries;
    struct Snake *snakeHead = NULL;
    struct Snake *snakePtr = NULL;
    struct XYVector direction;
    struct XYVector directionTmp;
    struct XYVector currentPos;

    struct XYVector snakeHeadPosNorm;
    struct XYVector prevSnakeTailPos;
    int snakeLen;

    struct Snake *snakeTail = NULL;
    static const char quitMsg[] = "Press Q to Quit";

    cursesSetup();
    gameSpeed = 50000;

    /* Game initialization */
    // Adding snake's first node
    feedSnake(&snakeHead);
    // Default direction vector (0, 0)
    direction = calculateDirection(-1);
    snakeTail = snakeHead;
    
    screenBoundaries = generateXyVector(COLS, LINES);
    gameBoundaries = generateXyVector(COLS, LINES-1);
    mvaddstr(gameBoundaries.y, (gameBoundaries.x-strlen(quitMsg))/2, quitMsg);

    border(0,0,0,0,0,0,0,0);
    mvhline(1, 1, screenBoundaries.y, screenBoundaries.x);


    do {
        snakeLen = snakeLength(snakeHead);



        mvprintw(0, 0, "");
        mvprintw(0, 0, "length: %d", snakeLen);
        mvprintw(1, 0, "");
        mvprintw(1, 0, "current_snake_tail_pos: (%d, %d)               ", snakeTail->position.x, snakeTail->position.y);
        mvprintw(2, 0, "");
        mvprintw(2, 0, "previous_snake_tail_pos: (%d, %d)              ", prevSnakeTailPos.x, prevSnakeTailPos.y);
        mvprintw(3, 0, "");
        mvprintw(3, 0, "is_overlapping_snake: %d                       ", isOverlappingSnake(snakeHead));




        // If a key has been pressed, calculate a direction
        ch = getch();

        if (ch != -1) {
            directionTmp = calculateDirection(ch);
            if (!equalXyVectors(directionTmp, generateXyVector(0,0))) {
                if(!checkOppositeDirectionVectors(directionTmp, direction)) {
                    direction = directionTmp;
                }
            }
        }
    
        // print snake
        snakePtr = snakeHead;
        while(snakePtr != NULL) {
            currentPos = normalizePlanePoint(snakePtr->position, screenBoundaries);
            mvaddch(currentPos.y, currentPos.x, CH_SNAKE);
            mvaddch(currentPos.y, currentPos.x-1, CH_SNAKE);
            snakePtr = snakePtr->next;
        }

        if(snakeLength(snakeHead) != 1) {
            currentPos = normalizePlanePoint(prevSnakeTailPos, screenBoundaries);
            mvprintw(currentPos.y, currentPos.x-1, "  ");
        }
        usleep(gameSpeed);
        refresh();

        prevSnakeTailPos = snakeTail->position;

        if(isOverlappingSnake(snakeHead)) {
            cursesDestroy();
            freeSnake(&snakeHead);
            return EXIT_FAILURE;
        }  

        if (ch != -1) feedSnake(&snakeHead);
        moveSnake(&snakeHead, direction);

        snakeHeadPosNorm = normalizePlanePoint(snakeHead->position, screenBoundaries);
        if(!isSnakeWithingBoundaries(snakeHeadPosNorm, screenBoundaries)) {
            cursesDestroy();
            freeSnake(&snakeHead);
            return EXIT_SUCCESS;
        }
        
    } while (toupper(ch) != CH_QUIT);

    cursesDestroy();
    freeSnake(&snakeHead);
    return EXIT_SUCCESS;
}