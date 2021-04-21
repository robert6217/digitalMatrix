#include <ncurses.h>
#include <unistd.h>

#define DELAY 5000

int main(int argc, char *argv[]) {
    int x = 1, x_direction = 1;
    int y = 0, y_direction = -1;

    initscr();
    noecho();
    curs_set(FALSE);

    while (1) {
        clear();
        mvprintw(y, x, "o");
        refresh();

        usleep(DELAY);
        if (x == COLS || x == 0) {
            if ((y == LINES-1 && x == COLS) || (y == 0 && x == COLS)) {
                y_direction *= -1;
            }
            y += y_direction;
            x_direction *= -1;
        }

        x += x_direction;
    }
    endwin();
}