all:
	g++ snake.cpp -o snake -lncurses && ./snake
clean:
	rm snake
