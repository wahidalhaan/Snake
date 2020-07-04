#include<iostream>
#include<ncurses.h>
#include<bits/stdc++.h>
#include "snake.h"

int main()
{
   initscr();
   noecho();
   curs_set(0);
   
int yMax,xMax;
getmaxyx(stdscr,yMax,xMax);
attron(A_REVERSE);
mvprintw(1,xMax/4-2,"SNAKE");
attroff(A_REVERSE);

WINDOW *win = newwin(yMax/2,xMax/2,5,10);
WINDOW *rules = newwin(5 +5,20,5,xMax-40);
box(win,0,0);
box(rules,0,0);

wattron(rules,A_REVERSE);
mvwprintw(rules,1,1,"INFO:");
mvwprintw(rules,3,1,"Arrow Keys to Move");
mvwprintw(rules,5,1,"q to Quit");
wattroff(rules,A_REVERSE);
attron(A_REVERSE);
mvwprintw(stdscr,yMax/2+5+5,xMax/4-10,"Created By Sonunigga");
attroff(A_REVERSE);
refresh();
wrefresh(win);
wrefresh(rules);

Snake *s = new Snake(win,1,1);
do
{
s->display();
if(s->getLoc()==s->getFruitLoc())
{
	s->growSnake();
	s->spawnFruit();
	s->display();
}
if(!s->checkCollision())
wrefresh(win);
else
{
                 break;
}
if(!s->checkStatus())
	break;

}while(s->getInput()!='q');
init_pair(2,COLOR_GREEN,COLOR_RED);
attron(COLOR_PAIR(2));
mvwprintw(stdscr,0,40,"GAME OVER");
mvwprintw(stdscr,1,40,"PRESS ANY KEY TO EXIT");
attroff(COLOR_PAIR(2));
getch();
endwin();
	return 0;
}
