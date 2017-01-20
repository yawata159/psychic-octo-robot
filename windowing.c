#include <ncurses/ncurses.h>

int main() {
    WINDOW *win1;
    WINDOW *win2;
    int height, width, starty, startx;
    

    initscr();
    cbreak();
    keypad(stdscr, TRUE);
//    printw("Hello World !!!");
    
    height = LINES;
    width = COLS / 2;
    starty = 0;
    startx = 0;

    win1 = newwin(height, width, starty, startx);
    box(win1, 0, 0);
    wrefresh(win1);

    startx = COLS / 2;

    win2 = newwin(height, width, starty, startx);
    box(win2, 0, 0);
    wrefresh(win2);

    mvwprintw(win1, 0, 0, "Hello World");
    mvwprintw(win2, 0, 0, "Hello World2");

    wrefresh(win1);
    wrefresh(win2);

    getch();
    endwin();
    return 0;
}
