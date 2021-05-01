#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define RATE 50
static unsigned int numOfRain;
static unsigned int maxSign = 126, minSign = 33;
int initColor();
int initCurse();
int initRains();
void freerain();
void *raining();
typedef struct rain {
    unsigned short col;
    unsigned short length;
    unsigned short row;
    unsigned short frames_per_row;
} Rain;
static Rain *rains;
static int setRainProps(Rain *rainprops);

void freerain() {
    free(rains);
    endwin();
    return;
}

void *raining() {
    Rain *i = rains;
    for (; i < rains + numOfRain; i++) {
        int length = 0;
        for (; length < i->length; length++) {
            attron(COLOR_PAIR(3));
            mvaddch(i->row - length, i->col, rand() % (maxSign - minSign) + minSign);
            attroff(COLOR_PAIR(3));
            attron(COLOR_PAIR(8));
            mvaddch(i->row, i->col, rand() % (maxSign - minSign) + minSign);
            attroff(COLOR_PAIR(8));
        }

        if (i->row == LINES) {
            mvaddch((i)->row - length, (i)->col, ' ');
            setRainProps(i);
        }
        i->row++;
    }

    return 0;
}
int initRains() {
    time_t t;
    srand((unsigned)time(&t));
    unsigned int screenArea = LINES * COLS;
    numOfRain = screenArea / RATE;
    rains = malloc(sizeof(struct rain) * numOfRain);

    if (!rains) {
        perror("Out of memory\n");
        exit(1);
    }
    unsigned int i = 0;
    for (; i < numOfRain; i++) {
        setRainProps(rains + i);
        (rains + i)->row = rand() % LINES;
    }
    return 0;
}

static int setRainProps(Rain *rainprops) {
    rainprops->col = rand() % COLS;
    rainprops->row = rand() % LINES;
    rainprops->length = rand() % 3 + 3;
    rainprops->frames_per_row = 0;
    return 0;
}

int initColor() {
    start_color();
    use_default_colors();
    init_pair(3, COLOR_GREEN, -1);
    init_pair(8, COLOR_WHITE, -1);
    return 0;
}
int initCurse() {
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    noecho();
    cbreak();
    atexit(freerain);
    nodelay(stdscr, TRUE);
    initColor();
    initRains();
    return 0;
}

int main() {
    initCurse();

    while (1) {
        raining();
        refresh();
        usleep(100000);
        clear();
    }

    return 0;
}