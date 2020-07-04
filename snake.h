#pragma once

class Snake
{
	private:
		int xLoc,yLoc,input,xFruit,yFruit,xMax,yMax;
      		std::vector<std::pair<int,int>> snake;
		bool quit=false;
        public:
		Snake(WINDOW *win,int x,int y);
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();
                void spawnFruit();
		int getInput();
		std::pair<int,int> getFruitLoc();
		std::pair<int,int> getLoc();
		void display();
		void growSnake();
		bool checkCollision();
		bool checkStatus();
		WINDOW *curwin;
		
};

Snake::Snake(WINDOW * win,int x,int y)
{
 curwin = win;
 xLoc=x;
 yLoc=y;
 getmaxyx(curwin,yMax,xMax);
 spawnFruit();
 keypad(curwin,true);
 snake.push_back(std::make_pair(xLoc,yLoc));
 start_color();
}

void Snake::moveUp()
{	
	
mvwaddch(curwin,yLoc,xLoc,' ');
yLoc--;
if(yLoc <1)
{
	yLoc=1;
           quit=true;
}
for(int i=snake.size()-1;i>0;i--)
{
	mvwaddch(curwin,snake[i].first,snake[i].second,' ');
	snake[i]=snake[i-1];
 
}
 	

}

void Snake::moveDown()
{
 mvwaddch(curwin,yLoc,xLoc,' ');
 yLoc++;
 if(yLoc>yMax-2)
 {
	 yLoc=yMax-2;
         quit=true;
 }
 for(int i=snake.size()-1;i>0;i--)
 {
	 mvwaddch(curwin,snake[i].first,snake[i].second,' ');  
 	 snake[i]=snake[i-1];
 }                                                                         


}

void Snake::moveRight()
{
 mvwaddch(curwin,yLoc,xLoc,' ');
 xLoc++;
 if(xLoc>xMax-2)
 {
	 xLoc=xMax-2;
	 quit=true;
 }
 for(int i=snake.size()-1;i>0;i--)
 {
 	 mvwaddch(curwin,snake[i].first,snake[i].second,' ');  
 	 snake[i]=snake[i-1];
	 
 }
}

void Snake::moveLeft()
{
  mvwaddch(curwin,yLoc,xLoc,' ');
  xLoc--;
  if(xLoc<1)
  {
	  xLoc=1;
	  quit=true;
  }
 for(int i=snake.size()-1;i>0;i--)
 {       mvwaddch(curwin,snake[i].first,snake[i].second,' ');
	 snake[i]=snake[i-1];

 }
}

void Snake::spawnFruit()
{
 xFruit=rand() % (xMax-3) + 1;
 yFruit= rand() % (yMax-3) +1;
 mvwaddch(curwin,yFruit,xFruit,'*');
}

int Snake::getInput()
{
 int choice = wgetch(curwin);
 input = choice;
 switch(choice)
 {
   case KEY_UP:
	   moveUp();
	   break;
   case KEY_DOWN:
	   moveDown();
	   break;
   case KEY_LEFT:
           moveLeft();
	   break;
   case KEY_RIGHT:
           moveRight();
 	   break;
   default:
        break;	   


 }
 return choice;

}

void Snake::display()
{	
 mvwaddch(curwin,yLoc,xLoc,'O');
 snake[0].first=yLoc;
 snake[0].second=xLoc;
 for(int i=1;i<snake.size();i++)
 {       init_color(COLOR_CYAN,rand()%1000,rand()%1000,rand()%1000);
	 init_color(COLOR_MAGENTA,rand()%1000,rand()%1000,rand()%1000);
	 init_pair(1,COLOR_CYAN,COLOR_MAGENTA);
	 wattron(curwin,COLOR_PAIR(1));
	 mvwaddch(curwin,snake[i].first,snake[i].second,'o');
	 wattroff(curwin,COLOR_PAIR(1));
 }
}

std::pair<int,int> Snake::getFruitLoc()
{

return std::make_pair(yFruit,xFruit);

}

std::pair<int,int> Snake::getLoc()
{

return std::make_pair(yLoc,xLoc);

}

void Snake::growSnake()
{  
	
   if(input == KEY_UP)
   {
	
	   snake.push_back(std::make_pair(yLoc+1,xLoc));
   }
   if(input ==  KEY_DOWN)
   {
	
	   snake.push_back(std::make_pair(yLoc-1,xLoc));
   }
   if(input ==KEY_LEFT)
   {
  	
	   snake.push_back(std::make_pair(yLoc,xLoc+1));
   }
   if(input==KEY_RIGHT)
   {
	  
         snake.push_back(std::make_pair(yLoc,xLoc-1));
   }
}

bool Snake::checkCollision()
{

for(int i=1;i<snake.size();i++)
if(getLoc() == snake[i] )
	return true;

return false;


}
bool Snake::checkStatus()
{
	if(quit==true)
		return false;
	else
		return true;
}
