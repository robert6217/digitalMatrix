#include <ncurses.h>
#include <unistd.h>

#define DELAY 10000

int main(int argc, char *argv[]) {
    int x = 1, x_direction = 1;
    int y = 0, y_direction = 1;
    int r = 0;
    initscr();
    noecho();
    curs_set(FALSE);

    while (1) {
        clear();
        mvprintw(y, x, "o");
        refresh();

        usleep(DELAY);
        if (x == 0 && y == 0) {
            r = 1;
        } else if (x == COLS && y == LINES) {
            r = 1;
        } else {
            r == 0;
        }
        if (x == COLS || x < 0) {
            if (r == 1) {
                y_direction *= -1;
            }
            y += y_direction;
            x_direction *= -1;
        }

        x += x_direction;
    }
    endwin();
}