#include <curses.h>
#include <signal.h>

#include "../lib/snake.h"
#include "validations.c"
#include "../controllers/keyboard.c"

#define CH_SNAKE 'U+1'
#define CH_QUIT 81

void cursesSignalHandler(int sig);
void cursesSetup(void);
void cursesDestroy(void);
void doGame(void);

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

    return;
}

void cursesDestroy(void) {
    endwin();
}

void doGame(void) {
    useconds_t gameSpeed;
    int ch;

    cursesSetup();

    gameSpeed = 100000;

    do {
        ch = getch();
        
        usleep(gameSpeed);
    } while (toupper(ch) != CH_QUIT);

    cursesDestroy();

    exit(EXIT_SUCCESS);
}