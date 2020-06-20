#include <ncurses.h>

void main(){

	int row, col;
	char msg[] = "test";


	initscr();
	echo();
	getmaxyx(stdscr, row, col);
	printw("\n row = %d, col = %d", row, col);
	printw("\n Chat Application");


	for (int i = 0; i < 5; i ++) {
			printw("\n row = %d, col = %d", row, col);
			refresh();
			getch();

	}
	refresh();
	getch();
	endwin();

	return 0;
}