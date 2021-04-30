#include <ncurses.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define RATE 50
static unsigned int numOfRain;
static unsigned int maxSign = 126, minSign = 33;

void *raining(void *arg) {
    int *input = (int *)arg;
    int i = input[0];
    int x = input[1];
    int n = 0;
    for (n = 0; n < 10; n++) {
        attron(COLOR_PAIR(3));
        mvaddch(i + n - 1, x, rand() % (maxSign - minSign) + minSign);
        attroff(COLOR_PAIR(3));
        // mvprintw(i + n, x, rand() % (maxSign - minSign) + minSign);
        attron(COLOR_PAIR(8));
        mvaddch(i + n, x, rand() % (maxSign - minSign) + minSign);
        attroff(COLOR_PAIR(8));
    }
    return 0;
}

int initRain() {
    time_t t;
    srand((unsigned)time(&t));
    unsigned int screenArea = LINES * COLS;
    numOfRain = screenArea / RATE;
    // pthread;

    return 0;
}

int main() {
    pthread_t t[numOfRain];
    initRain();
    initscr();
    noecho();
    curs_set(FALSE);
    int x = rand() % 10, i = 0;

    /*  set color  */
    start_color();
    use_default_colors();
    init_pair(3, COLOR_GREEN, -1);
    init_pair(8, COLOR_WHITE, -1);

    // /*  set sleep time  */
    // struct timespec ts;
    // ts.tv_sec = 200 / 1000;
    // ts.tv_nsec = (20 % 1000) * 1000000;

    while (1) {
        // nanosleep(&ts, &ts1);
        refresh();
        usleep(100000);
        clear();
        if (i == LINES) {
            x = rand() % COLS;
            i = 0;
        }
        int input[2] = {i, x};
        int threadn = 0;
        // raining(input);
        // pthread_create(&t[threadn], NULL, raining, (void *)input);
        // pthread_join(t[threadn], NULL);
        for (; threadn < numOfRain; threadn++) {
            pthread_create(&t[threadn], NULL, raining, (void *)input);
        }
        for(; threadn < numOfRain; threadn++){
            pthread_join(t[threadn], NULL);

        }

        i++;
    }
    endwin();
    return 0;
}