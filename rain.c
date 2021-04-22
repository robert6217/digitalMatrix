#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define DELAY 30000
int main() {
    time_t t;
    int x = 1, x_direction = 1;
    int y = 0, y_direction = -1;
    char buffer[2];
    initscr();
    noecho();
    curs_set(FALSE);
    srand((unsigned)time(&t));
    while (1) {
        clear();
        sprintf(buffer, "%d", rand() % 10);
        mvprintw(LINES / 2, COLS / 2, buffer);
        refresh();
        usleep(DELAY);
    }
    return 0;
}