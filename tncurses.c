#include <ncurses.h>
#include <stdio.h>
#include <string.h>

int main(int argc, const char* argv[]) {
    // printf("hello workd\n");
    initscr();
    raw();
    noecho();
    curs_set(0);

    char* c = "Hello, World!";

    mvprintw(LINES / 2, (COLS - strlen(c)) / 2, c);
    refresh();

    getch();
    endwin();
    return 0;
}