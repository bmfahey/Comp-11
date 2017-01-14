#include <iostream>
using namespace std;
#include "termfuncs.h"

/*
 * 2snake version 1.0
 *   Modified by: Brendan Fahey
 *   Date: 10/29/15
 *   Program: msnake.cpp
 *   Project 1
 *   
 *   This program plays the game "Snake." There are two players in this game
 *   and they each get to choose their names, body characters, and movement
 *   keys. They can run each other over but not themselves, and they have to
 *   eat "snacks" and gain EU to stay alive. After the game is over this 
 *   program will display a "game over" message with final scores.
 */

const int 	ROWS    = 22;		// change if you like
const int 	COLS    = 61;		// change if you like
const int	EU_INIT = 60;

const char	BUG_SYM = 'X';
const int	BUG_VAL = 25;
const char	EGG_SYM = 'O';
const int	EGG_VAL = 15;

// -------------------------------------------------------------
// ----- SNAKE DEFINITION --------------------------------------
//              CODE appears at end of this file
// -------------------------------------------------------------

class Snake
{
    public:
	void	init();
	void	set_name(string);
	void	set_pos(int r, int c, char dir);
	void	set_controls(char l, char r, char f);
	void	set_body(char);
	void	set_EU(int);
	void	set_color(string fg, string bg);	// not required

	string	get_name();
	int	get_score();

	bool	process_key(char, char [ROWS][COLS]);
	bool	is_alive();
	void	print_status();
	void	draw_head_on_board(char [ROWS][COLS]);

        void	setup_snake(int num, int row, int col, char dir, int EU);

    private:
	int eu;
	char head;
	char body;
	int score;
	char bodychar;
	char leftkey;
	char rightkey;
	char forkey;
	bool alive;
	int ypos;
	int xpos;
	string name; 

	bool	move_forward(char[ROWS][COLS]);
	bool 	turn_right();
	bool 	turn_left();
	void    evaluate_position(char [ROWS][COLS]); 
};

// -------------------------------------------------------------
// ----- Main Game that uses a Snake ---------------------------
// -------------------------------------------------------------
/*
 * multi-snake game
 */

void	place_snack(char, char[ROWS][COLS]);
string	play_game(char[ROWS][COLS]);
void	display(char [ROWS][COLS], Snake, Snake);
string	compute_outcome(Snake, Snake);
void setup_board(char[ROWS][COLS]);
void draw_board(char[ROWS][COLS]);
void report(string result);

//    ---- note: DO NOT MODIFY main() AT ALL ----
int main()
{
	char	board[ROWS][COLS];
	string	result;

	setup_board(board);
	result = play_game(board);
	report(result);
}

//function: setup_board
//takes away dead squirrels and initializes board
//parameters: char[][] board
//returns: none, void (updates board)
void setup_board(char board[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			board[i][j] = ' ';
		}
	}
}

//function: report
//reports the final result of the game
//parameters: string result
//returns: none, void
void report(string result) {
	cout << "Game over. " << result << endl;
}

//
// play_game -- run a game of multi-snake
//    args: a board ready to use
//    rets: "X wins" or "X died" where X is name of snake
//    note: USE THIS MAIN UNCHANGED FOR PHASE 0
//    note: FOR PHASE 1, move setup_snake into class 
//
string play_game(char b[ROWS][COLS])
{
	Snake	s0, s1;		// the players
	char	input;
	string	outcome = "";

	// set up the snakes and put food on board
	screen_clear();
	s0.setup_snake(0, ROWS/2-1, COLS/2, '^', EU_INIT);
	s1.setup_snake(1, ROWS/2  , COLS/2, 'v', EU_INIT);
	s0.draw_head_on_board(b);
	s1.draw_head_on_board(b);
	place_snack(BUG_SYM, b);
	place_snack(EGG_SYM, b);

	// play the game
	while( s0.is_alive() && s1.is_alive() )
	{
		display(b, s0, s1);
		input = getachar();
		s0.process_key(input, b);
		s1.process_key(input, b);
	}
	display(b, s0,s1);

	outcome = compute_outcome(s0, s1);
	return outcome;
}

// compute_outcome -- determine if someone one
//  args: two snakes
//  rets: "X wins" OR  "X died"
//  note: to win, a snake must be alive AND have a higher score
//
string compute_outcome(Snake a, Snake b)
{
	string result = "";
	if (~ a.is_alive()) {
		result = a.get_name() + " died.";
	}
	else if (~ b.is_alive()) {
		result = b.get_name() + " died.";
	}
	else if (a.get_score() > b.get_score()) {
		result = a.get_name() + " wins.";
	}
	else if (b.get_score() > a.get_score()) {
		result = b.get_name() + " wins.";
	}
	else {
		result = "It's a tie.";
	}
	return result;
}

// display - show current state of game including board and snake status
//  args: the board, the snakes
//  rets: nothing
//  does: sends info to cout
//
void display(char brd[ROWS][COLS], Snake a, Snake b)
{
	draw_board(brd);
	a.print_status();
	b.print_status();
}

//function:draw_board
//displays the board 
//parameters: char array (board)
//returns: nothing, void
void draw_board(char brd[ROWS][COLS]) {
	screen_clear();
	cout << '+';
	for (int i = 0; i < COLS; i++) {
		cout << '-';
	}
	cout << '+' << endl;
	for (int i = 0; i < ROWS; i++) {
		cout << '|';
		for (int j = 0; j < COLS; j++) {
			cout << brd[i][j];
		}
		cout << '|' << endl;
	}
	cout << '+';
	for (int i = 0; i < COLS; i++) {
		cout << '-';
	}
	cout << '+' << endl;
}

//function place_snack
//places the given snack character on the board
//parameters: char snack, char[ROWS][COLS] b
//returns: none, void (b is updated)
void place_snack(char snack, char b[ROWS][COLS]) {
	int x = random_int(0,COLS-1);
	int y = random_int(0,ROWS-1);
	while (b[y][x] != ' ') {
		x = random_int(0,COLS-1);
		y = random_int(0,ROWS-1);
	}
	b[y][x] = snack;
}

// -------------------------------------------------------------------------
//  SNAKE IMPLEMENTATION
//    The following section contains the member functions for a Snake
//---------------------------------------------------------------------------

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
		evaluate_position(b);
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

					     
