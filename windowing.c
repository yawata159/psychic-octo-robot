#include <ncurses.h>
#include <menu.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

char *choices[] = {
    "Num 1",
    "Num 2",
    "Num 3",
    "Num 4",
    "Num 5"
};

int main() {

    ITEM **left_items;
    MENU *left_menu;
    int n_choices, i;
    int c;

    WINDOW *win1;

    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    
    n_choices = ARRAY_SIZE(choices);
    left_items = (ITEM **)calloc(n_choices, sizeof(ITEM *));
    for (i = 0; i < n_choices; ++i);
        left_items[i] = new_item(choices[i], choices[i]);
    left_menu = new_menu((ITEM **)left_items);


    win1 = newwin(LINES, COLS / 2, 0, 0);
    keypad(win1, TRUE);

    // set window + sub window
    set_menu_win(left_menu, win1);
    set_menu_sub(left_menu, derwin(win1, 6, COLS / 2 - 2, 3, 1));
    set_menu_mark(left_menu, " > ");

    box(win1, 0,0);
    refresh();

    post_menu(left_menu);
    wrefresh(win1);

    //win2 = newwin(height, width, 0, COLS / 2);
    //box(win2, 0, 0);
/*

    while((c = wgetch(win1)) != KEY_F(1)){
        switch(c) {
            case KEY_DOWN:
                menu_driver(left_menu, REQ_DOWN_ITEM);
                break;
            case KEY_UP:
                menu_driver(left_menu, REQ_UP_ITEM);
                break;
            case KEY_NPAGE:
                menu_driver(left_menu, REQ_SCR_DPAGE);
                break;
            case KEY_PPAGE:
                menu_driver(left_menu, REQ_SCR_UPAGE);
                break;
        }
        wrefresh(win1);
    }
*/
    

    //wrefresh(win1);
    //wrefresh(win2);
    

    //mvwprintw(win1, 1, 1,  "hello");
    //wrefresh(win1);
    
    getch();

    endwin();
    return 0;
}
