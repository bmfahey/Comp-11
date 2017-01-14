#include <iostream>
using namespace std;
#include "termfuncs.h"
#include "snake.h"

void place_snack(char, char[ROWS][COLS]);

//
// init -- set initial default values for a Snake 
//   args: none
//   rets: nothing
//   mods: modifies the snake by setting its member variables
//
void Snake::init()
{
	score    = 0;
	alive    = true;
}

// ----- put rest of the member functions down here ---------------------

//function:set_name
//assigns a name to a snake
//parameters: string name
//returns: nothing, void
void Snake::set_name(string n) {
	name = n;
}

//function:set_pos
//sets the x,y position of the snake and its head direction
//parameters:int r, int c,char dir
//returns: nothing, void
void Snake::set_pos(int r, int c, char dir) {
	ypos = r;
	xpos = c;
	head = dir;
}

//function:set_controls
//sets the keys to move the snake
//parameters: three chars, left, right, and forward
//returns: nothing, void
void Snake::set_controls(char l, char r, char f) {
	leftkey = l;
	rightkey = r;
	forkey = f;
}

//function: set_body
//sets the body character of a snake
//parameters: a char, the body character
//returns: nothing, void
void Snake::set_body(char b) {
	bodychar = b;
}

//function: set_EU
//sets the energy units for a snake
//parameters: int energy
//returns:nothing, void
void Snake::set_EU(int energy) {
	eu = energy;
}

//function:get_name
//gets the name of a snake
//paramters: none
//returns: a string, the name
string Snake::get_name() {
	return name;
}

//function:get_score
//gets the score of a snake
//parameters:none
//returns: an int, the score of the snake
int Snake::get_score() {
	return score;
}

//function:is_alive
//returns if the snake is alive
//parameters: none
//returns: boolean, true if the snake is alive
bool Snake::is_alive() {
	return alive;
}

//function: draw_head_on_board
//puts the head in the correct place on the gameboard
//parameters: the two-dimensional board array
//returns: nothing, void (updates board)
void Snake::draw_head_on_board(char board[ROWS][COLS]) {
	board[ypos][xpos] = head;
}

//function: print_status
//displays the name, eu, score, and keys of snake
//parameters: none
//returns: nothing, void
void Snake::print_status() {
	cout << name  << " EU: " << eu << " Score: " << score 
	     << " Keys: " << leftkey << rightkey << forkey << endl;
}

//function: process_key
//decides what to do based on inputted key
//parameters: board array of chars, char input
//returns: a boolean, whether or not the operation was completed
bool Snake::process_key (char input, char b[ROWS][COLS]) {
	bool result = true;;
	if (input == forkey) {
		result = move_forward(b);
	}
	else if (input == rightkey ) {
		result = turn_right();
		draw_head_on_board(b);
	}
	else if (input == leftkey) {
		 result = turn_left();
		 draw_head_on_board(b);
	}
        return result;
}

//function: move_forward
//moves the snake in the correct direction, 
//updates eu and score, checks for X and o
//parameters: array of chars
//returns: boolean (true if moved correctly)
bool Snake::move_forward(char b[ROWS][COLS]) {
	char origy = ypos, origx = xpos;
	b[ypos][xpos] = bodychar;
	score++;
	eu--;
	if (head == '^') {
		ypos--;
		if (ypos < 0)
			ypos = ROWS-1;	
	}
	else if (head == '>') {
		xpos++;
		if (xpos >= COLS)
			xpos = 0;
	}
	else if (head == 'v') {
	       	ypos ++;
		if (ypos >= ROWS)
			ypos = 0; 
	}
	else if (head == '<') {
	       	xpos --;
		if (xpos < 0)
			xpos = COLS-1;
	}
	evaluate_position(b);
	draw_head_on_board(b);
	return !(origy == ypos && origx == xpos);
}

//function:turn_right
//turns the snake head right
//parameters: none
//returns: true if snake head turned
bool Snake::turn_right() {
	char orighead = head;
	if (head == '^') {
		head = '>';
	}
	else if (head == '>') {
		head = 'v';
	}
	else if (head == 'v') {
		head = '<';
	}
	else if (head == '<') {
		head = '^';
	}
	return !(orighead == head);
}

//function: turn_left
//turns the snake head left
//parameters: none
//returns: true if snake head turned
bool Snake::turn_left() {
	char orighead = head;
	if (head == '^') {
		head = '<';
	}
	else if (head == '<') {
		head = 'v';
	}
	else if (head == 'v') {
		head = '>';
	}
	else if (head == '>') {
		head = '^';
	}
	return !(orighead == head);
}

//function:evaluate_position
//figures out if anything special should happen to 
//the snake based on its new position (such as X or o,
//dying)
//parameters: array of chars
//returns: nothing, void
void Snake::evaluate_position(char board[ROWS][COLS]) { 
	if (board[ypos][xpos] == bodychar) {
		alive = false;
	}
	if (board[ypos][xpos] == EGG_SYM){
		eu += EGG_VAL;
		place_snack (EGG_SYM, board);
	}
	if (board[ypos][xpos] == BUG_SYM) {
		eu += BUG_VAL;
		place_snack( BUG_SYM, board);
	}
	if (eu == 0) {
		alive = false;
	}
 }

//NOTE: Moved down here b/c it is now part of Snake
//
// setup_snake -- initialize a snake for the game
//  args: the snake number, the snake, its row, col, dir, and initial EU
//returns: modified snake
void Snake::setup_snake(int num, int r, int c, char d, int eu )
{
	string	n;
	char	lkey,rkey,fkey, body;

	init();			// set any initial default values
	set_EU(eu);			// set initial energy
	set_pos(r, c, d);		// set pos and direction

	// now customize for the player
	cout << "Welcome, player " << num << endl;
	cout << "Name? ";
	cin  >> n;
	set_name(n);

	cout << "Body character? ";
	cin  >> body;
	set_body(body);

	cout << "Keys for left, right, fwd? ";
	cin  >> lkey >> rkey >> fkey ;
	set_controls(lkey, rkey, fkey);
}

					     
