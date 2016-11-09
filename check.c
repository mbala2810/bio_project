/*****************************************************************************
 * Copyright (C) Balasubramanian M mbasubram@gmail.com
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/
#include<ncurses.h>
#include<string.h>
#include<stdio.h>
int main(int argc, char *argv[]){
	int i, x = 2, y = 2;
	initscr();
	clear();
	refresh();
	cbreak();
	curs_set(0);
	start_color();
	WINDOW *win;
	win = newwin(5, 15, 18, 60);
	char a[101], s[101];
	FILE *fp;
	fp = fopen(argv[1], "r");
	fscanf(fp, "%s", a);
	fclose(fp);
	fp = fopen(argv[2], "r");
	fscanf(fp, "%s", s);
	fclose(fp);
	int compare = strcmp(a, s);
	if(compare == 0){
		init_pair(1, COLOR_RED, COLOR_WHITE);	
		box(win, 0, 0);
		wbkgd(win, COLOR_PAIR(1));
		wrefresh(win);
		wattron(win, A_REVERSE | A_BOLD);
		mvwprintw(win, y, x, " FOUND!!!!!");
		wattroff(win, A_REVERSE | A_BOLD);
	}
	else {
		init_pair(1, COLOR_GREEN, COLOR_WHITE);	
		box(win, 0, 0);
		wbkgd(win, COLOR_PAIR(1));
		wrefresh(win);
		wattron(win, A_REVERSE | A_BOLD);
		mvwprintw(win, y, x, "NOT FOUND!!");
		wattroff(win, A_REVERSE | A_BOLD);
	}
	wrefresh(win);
	wgetch(win);
	endwin();
}
