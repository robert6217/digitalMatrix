#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    time_t t;
    int x = rand() % 10;
    int i = 0;
    char buffer[2];
    initscr();
    noecho();
    curs_set(FALSE);
    srand((unsigned)time(&t));

    while (1) {
        usleep(100000);

        clear();
        if (i == LINES) {
            x = rand() % COLS;
            i = 0;
        }
        int n = 0;
        for (n = 0; n < 10; n++) {
            sprintf(buffer, "%d", rand() % 2);
            mvprintw(i + n, x, buffer);
        }
        refresh();
        i++;
    }
    return 0;
}