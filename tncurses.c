#include <ncurses.h>
#include <unistd.h>

#define DELAY 30000

int main(int argc, char *argv[]) {
    int x = 0, direction = 1;

    initscr();
    noecho();
    curs_set(FALSE);

    while (1) {
        clear();
        mvprintw(LINES / 2, x, "o");
        refresh();

        sleep(1);

        if (x >= COLS || x < 0) {
            direction *= -1;
        }
        x += direction;
    }
    endwin();
}