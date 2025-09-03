//
// Created by florent on 31/07/25.
//

#include <ncurses.h>

void nCursePrint() {
    initscr();
    printw("Hello World");
    refresh();
    endwin();
}