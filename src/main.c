#include "game/engine.c"

// TODO remove or move to another file
int main() {

    doGame();

    return 0;
    // int ch;

    // static const char quitMsg[] = "Press Q to Quit";
    // /* Game initialization */
    // // Adding snake's first node
    // feedSnake(&snakeHead);
    // // Default direction vector (0, 0)
    // direction = calculateDirection(-1);

    // /* Game UI initizaliation */
    // initscr();
    // nodelay(stdscr, TRUE);
    // cbreak();
    // noecho();
    // curs_set(0);
    // keypad(stdscr, TRUE);

    // /* Game loop */
    // do {
    //     erase();

    //     gameBoundaries = generateXyVector(COLS, LINES);

    //     mvaddstr(LINES-1, (COLS-strlen(quitMsg))/2, quitMsg);
        
    //     // If a key has been pressed, calculate a direction
    //     ch = getch();
    //     if (ch != -1) {
    //         directionTmp = calculateDirection(ch);
    //         if (!equalXyVectors(directionTmp, generateXyVector(0,0))) {
    //             direction = directionTmp;
    //             feedSnake(&snakeHead);
    //         }
    //     }
    
    //     snakePtr = snakeHead;
    //     while(snakePtr != NULL) {
            
    //         currentPos = normalizePlanePoint(snakePtr->position, gameBoundaries);
    //         // printw("(%d, %d)", currentPos.x, currentPos.y);
    //         mvaddch(currentPos.y, currentPos.x, BOX_CHAR);
    //         mvaddch(currentPos.y, currentPos.x-1, BOX_CHAR);

    //         // mvprintw(currentPos.y, currentPos.x, "*");
    //         snakePtr = snakePtr->next;
    //         refresh();
    //     }
    //     usleep(20000);
    //     printw("\n");
    //     refresh();

    //     moveSnake(&snakeHead, direction);
    //     snakeHeadPosNorm = normalizePlanePoint(snakeHead->position, gameBoundaries);
    //     if(!validateNodePosition(snakeHeadPosNorm, gameBoundaries)) {
    //         endwin();
    //         freeSnake(&snakeHead);
    //         return 0;
    //     }
    // } while(true);
    // return 0;
}


// static const char quitMsg[] = "Press Q to Quit";
// static const char startMsg[] = "Press any key to start";

// mvaddstr(maxPos.y-1, (maxPos.x-strlen(startMsg))/2, startMsg);
// mvaddstr(maxPos.y-1, (maxPos.x-strlen(quitMsg))/2, quitMsg);

// //     /* and msg centered at the bottom. */
// //     mvaddstr(maxPos.y-1, (maxPos.x-strlen(msg))/2, msg);

// // } while (c != 'Q' && c != 'q');