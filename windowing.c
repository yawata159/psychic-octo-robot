#include <ncurses.h>

int main() {
    WINDOW *win1;
    WINDOW *win2;
    int height, width;
    

    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    
    height = LINES;
    width = COLS / 2;


    win1 = newwin(height, width, 0, 0);
    box(win1, 0, 0);

    win2 = newwin(height, width, 0, COLS / 2);
    box(win2, 0, 0);

    refresh();
    wrefresh(win1);
    wrefresh(win2);
    
    getch();

    mvwprintw(win1, 1, 1,  "hello");
    wrefresh(win1);
    
    getch();

    endwin();
    return 0;
}
