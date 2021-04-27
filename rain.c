#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define RATE 50
static unsigned int numOfRain;
static unsigned int maxSign = 126, minSign = 33;

int initRain() {
    time_t t;
    srand((unsigned)time(&t));
    unsigned int screenArea = LINES * COLS;
    numOfRain = screenArea / RATE;
    // pthread;
    return 0;
}

int main() {
    initRain();
    initscr();
    noecho();
    curs_set(FALSE);
    int x = rand() % 10, i = 0;

    /*  set color  */
    start_color();
    use_default_colors();
    init_pair(3, COLOR_GREEN, -1);

    while (1) {
        usleep(100000);

        clear();
        if (i == LINES) {
            x = rand() % COLS;
            i = 0;
        }
        int n = 0;
        for (n = 0; n < 10; n++) {
            attron(COLOR_PAIR(3));
            mvaddch(i + n, x, rand() % (maxSign - minSign) + minSign);
            attroff(COLOR_PAIR(3));
            // mvprintw(i + n, x, rand() % (maxSign - minSign) + minSign);
        }
        refresh();
        i++;
    }
    return 0;
}