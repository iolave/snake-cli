#include <stdio.h>
#include <unistd.h>
#include <curses.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "../include/vector.h"
#include "../include/snake.h"

// #define GAME_SPEED 100000
// #define GAME_UP 'w'
// #define GAME_DOWN 's'
// #define GAME_LEFT 'd'
// #define GAME_RIGHT 'a'

// struct Snake {
//     int x;
//     int y;
//     struct Snake *next;
// };

// void feedSnake(struct Snake **snake) {
//     // Creating a new snake node
//     struct Snake *node = malloc(sizeof(struct Snake));
    
//     // Setting new node values
//     node->x = 0;
//     node->y = 0;
    
//     // New node points to the rest of the snake
//     node->next = *snake;

//     // The new node plus the given snake becomes the new snake
//     *snake = node;
// }

int main() {
    struct Snake *snake = NULL;
    // feedSnake(&snake);
    printf("%d\n", snakeLength(snake));

    free(snake);

    // static const char quitMsg[] = "Press Q to Quit";
    // static const char startMsg[] = "Press any key to start";
    // int c;
 
    // /* Start curses. Also sets LINES and COLS. */
    // initscr();
 
    // /* Pass every character immediately, not buffered. */
    // // cbreak();
    // // noecho();
    // // curs_set(0);
    
    // struct XYVector[] snake;


    // struct XYVector maxPos;
    // maxPos.x = COLS;
    // maxPos.y = LINES;

    // struct XYVector currentPos;
    // currentPos.x = maxPos.x/2;
    // currentPos.y = maxPos.y/2;

    // struct XYVector direction;
    // direction.x = 0;
    // direction.y = 0;

    // struct XYVector lastPos;

    // mvaddstr(maxPos.y-1, (maxPos.x-strlen(startMsg))/2, startMsg);
    // getch();
    // nodelay(stdscr, TRUE);
    
    // erase();
    // mvaddstr(maxPos.y-1, (maxPos.x-strlen(quitMsg))/2, quitMsg);

    // // move(currentPos.y, currentPos.x);
    
    // // draw the snake head
    // mvaddch(currentPos.y, currentPos.x, '*');

    // // do the loop
    // do {
    //     lastPos = currentPos;
        
    //     c = tolower(getch());
    //     if (c == GAME_UP) {
    //         direction.x = 0;
    //         direction.y = -1;
    //     } else if(c == GAME_DOWN) {
    //         direction.x = 0;
    //         direction.y = 1;
    //     } else if(c == GAME_LEFT) {
    //         direction.x = 2;
    //         direction.y = 0;
    //     } else if(c == GAME_RIGHT) {
    //         direction.x = -2;
    //         direction.y = 0;
    //     }




    //     // screen dimentions validation
    //     if (currentPos.x > maxPos.x - 1 || currentPos.y > maxPos.y-2 || currentPos.x < 0 || currentPos.y < 0) {
    //         return(1);
    //     }

        
        
    //     // Sleep speed between every screen refresh
    //     usleep(GAME_SPEED);

    //     currentPos.x = currentPos.x + direction.x;
    //     currentPos.y = currentPos.y + direction.y;
        
    //     mvaddch(lastPos.y, lastPos.x, ' ');
    //     mvaddch(currentPos.y, currentPos.x, '*');

    //     refresh();
    // } while(true);
    
    
    // // erase();

    // //     if (kbhit()) {

    // //         // getstr();
    // //         refresh();
    // //         printw("%d",getch());
    // //         printw("%d",getch());
    // //         erase();
    // //     }
    // // }

    // // do {
    // //     /* Clear the screen. */
    // //     erase();

    // //     /* Print "X" at the center of the screen, */
    // //     mvaddch(currentPos.y, currentPos.x, '*');
    // //     /* Move the cursor to the center of the screen too. */
    // //     move(currentPos.y, currentPos.x);

    // //     /* and msg centered at the bottom. */
    // //     mvaddstr(maxPos.y-1, (maxPos.x-strlen(msg))/2, msg);

    // //     /* Refresh the screen. */  
    // //     refresh();

    // //     /* Wait for a keypress. */
    // //     c = getch();
    // //     if (c == 'A') {
    // //         currentPos.y = currentPos.y - 1;
    // //     } else if (c == 'B') {
    // //         currentPos.y = currentPos.y + 1;
    // //     } else if (c == 'C') {
    // //         currentPos.x = currentPos.x + 1;
    // //     } else if (c == 'D') {
    // //         currentPos.x = currentPos.x - 1;
    // //     }

    // //     if (currentPos.x > maxPos.x - 1 || currentPos.y > maxPos.y-2 || currentPos.x < 0 || currentPos.y < 0) {
    // //         return(1);
    // //     }
    // // } while (c != 'Q' && c != 'q');

    // /* Done. Return the terminal back to its normal state. */
    // endwin();

    // // struct XYDimention minXy;
    // // minXy.x = 0;
    // // minXy.y = 0;




    // // printf("%d %d", maxXy.x, maxXy.y);
    // // return(0);
}

// if (kbhit()) {
//             if (c == 'A') {
//                 currentPos.y = currentPos.y - 1;
//             } else if (c == 'B') {
//                 currentPos.y = currentPos.y + 1;
//             } else if (c == 'C') {
//                 currentPos.x = currentPos.x + 1;
//             } else if (c == 'D') {
//                 currentPos.x = currentPos.x - 1;
//             } else {
//                 currentPos.x = currentPos.x + 1;
//             }

//         }
       
