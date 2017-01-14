//Brendan Fahey
//10/13/15
//Snake
//Project 0
//This program plays the game "Snake."
//Users must move left (l), right (r), or forward(f)
//Snake wraps around border
//'o' worth 15 EU and 'X' worth
//Game is lost when snake runs out of EU or runs 
		//over its own tail
#include <iostream>
using namespace std;
#include "termfuncs.h"

const int ROWS = 21;
const int COLS = 61;

struct Snake {
	int eu;
	int ypos;
	int xpos;
	bool isAlive;
	char dirsymbol;
};

void setup_board(char board[ROWS][COLS]);
void place_big_snack(char board[ROWS][COLS]);
void place_little_snack(char board[ROWS][COLS]);
bool isEmpty(int y, int x, char board[ROWS][COLS]);
int play_game(char board[ROWS][COLS]);
Snake moveSnake(Snake snake, char input, char board[ROWS][COLS]);
Snake moveForward(Snake snake, char board[ROWS][COLS]);
Snake turn(Snake snake, char input);
void display_board(char board[ROWS][COLS], Snake snake, int score);
void report(int score);

int main() {
	char board[ROWS][COLS];
	int score;

	score = play_game(board);
	report(score);
	return 0;
}

//function: setup_board
//initializes all board chars & adds first snacks
//parameters: board (array of chars)
//returns: none, void (modifies "board")
void setup_board(char board[ROWS][COLS]) {
	screen_clear();
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			board[i][j] = ' ';
		}
	}
	place_big_snack(board);
	place_little_snack(board);
}

//function: place_big_snack
//puts big snack randomly on valid board space
//parameters: board (array of chars)
//returns: none, void (modifies board)
void place_big_snack(char board[ROWS][COLS]) {
	int x = random_int(0,COLS-1);
	int y = random_int(0,ROWS-1);
	while (!isEmpty(y,x,board)) {
		x = random_int(0,COLS-1);
		y = random_int(0,ROWS-1);
	}
	board[y][x] = 'X';
}

//function: place_little_snack
//puts little snack randomly on valid board space
//parameters: board (array of chars)
//returns: none, void (modifies board)
void place_little_snack(char board[ROWS][COLS]) {
	int x = random_int(0,COLS-1);
	int y = random_int(0,ROWS-1);
	while (!isEmpty(y,x,board)) {
		x = random_int(0,COLS-1);
		y = random_int(0,ROWS-1);
	}
	board[y][x] = 'o';
}

//function: isEmpty
//tells whether a space is empty
//parameters: int y (row), int x (column), board (array of chars)
//returns: boolean 
bool isEmpty(int y, int x, char board[ROWS][COLS]) {
	if (board[y][x] == ' ') 
		return true;
	else
		return false;
}

//function: play_game
//loops through, playing the game until the snake dies
//parameters: board (array of chars)
//returns: int (the score from the game)
int play_game(char board[ROWS][COLS]) {
	Snake snake;
	snake.dirsymbol = '^';
	snake.isAlive = true;
	int score = 0;
	char input;
	snake.ypos = ROWS/2;
	snake.xpos = COLS/2;
	setup_board(board);
	snake.eu = 60;
	while (snake.isAlive) { //loop till snake dies
		board[snake.ypos][snake.xpos] = snake.dirsymbol;
		display_board(board, snake, score);
		input = getachar();
		snake = moveSnake(snake,input, board);
		if (input == 'f')
			score++;
		if (board[snake.ypos][snake.xpos] == '#' || snake.eu < 0)
		{
			snake.isAlive = false;
		}
		board[snake.ypos][snake.xpos] = snake.dirsymbol;
		display_board(board, snake, score);
	}
	return score;
}

//function: moveSnake
//moves the snake
//parameters: snake, char input, board (array of chars)
//returns: modified snake
Snake moveSnake(Snake snake, char input, char board[ROWS][COLS]) {
	if (input == 'f') {
		snake = moveForward(snake, board);
	}
	else {
		snake = turn(snake, input);
	}
	return snake;
}

//function: moveForward
//moves the snake one space forward in proper direction
//loops snake to other side of screen if necessary
//parameters: snake, board (array of chars)
//returns: modified snake
Snake moveForward(Snake snake, char board[ROWS][COLS]) {
	board[snake.ypos][snake.xpos] = '#';
	if (snake.dirsymbol == '^') {
		snake.ypos --;
		if (snake.ypos < 0) 
			snake.ypos = ROWS-1;
       	}
	else if (snake.dirsymbol == 'v') {
		snake.ypos ++;
		if (snake.ypos >= ROWS) 
			snake.ypos = 0; }
	else if (snake.dirsymbol == '<') {
		snake.xpos --;
		if (snake.xpos < 0) 
			snake.xpos = COLS-1; 
	}
	else {
		snake.xpos ++;
		if (snake.xpos >= COLS) 
			snake.xpos = 0; }
	if (board[snake.ypos][snake.xpos] == 'X') {
		snake.eu += 25;
		place_big_snack(board); 
	}
	if (board[snake.ypos][snake.xpos] == 'o') {
		snake.eu += 15;
		place_little_snack(board); 
	}
	snake.eu --;
       	return snake;
}
 
//function: turn
//turns snake head in correct direction
//parameters: snake, char input
//returns: modified snake
Snake turn(Snake snake, char input) {
	if (input == 'r') {
		if (snake.dirsymbol == '^')
			snake.dirsymbol = '>';
		else if (snake.dirsymbol == '>')
			snake.dirsymbol = 'v';
		else if (snake.dirsymbol == 'v')
			snake.dirsymbol = '<';
		else 
			snake.dirsymbol = '^';
	}
	else {
		if (snake.dirsymbol == '^')
			snake.dirsymbol = '<';
		else if (snake.dirsymbol == '<')
			snake.dirsymbol = 'v';
		else if (snake.dirsymbol == 'v')
			snake.dirsymbol = '>';
		else
			snake.dirsymbol = '^';
	}
	return snake;
}

//function: display_board
//displays border and gameboard with snake and snacks
//parameters: board (array of chars), snake, int score
//returns: none, void (prints to screen)
void display_board(char board[ROWS][COLS], Snake snake, int score) {
	screen_clear();
	cout << '+';
	for (int i = 0; i < COLS; i++) {
		cout << '-';
	}
	cout << '+' << endl;
	for (int i = 0; i < ROWS; i++) {
		cout << '|';
		for (int j = 0; j < COLS; j++) {
			cout << board[i][j];
		}
		cout << '|' << endl;
	}
	cout << '+';
	for (int i = 0; i < COLS; i++) {
		cout << '-';
	}
	cout <<'+' << endl;
	cout << "EU: " << snake.eu << " Score: " << score << endl;
}

//function: report
//reports the score after death of snake
//parameters: int score
//returns: none, void (prints to screen)
void report(int score) {
	cout << "Game Over. Final Score: " << score << endl;
}
