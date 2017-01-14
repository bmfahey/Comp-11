#include "termfuncs.h"

const int 	ROWS    = 22;	       
const int 	COLS    = 61;		
const int	EU_INIT = 60;

const char	BUG_SYM = 'X';
const int	BUG_VAL = 25;
const char	EGG_SYM = 'O';
const int	EGG_VAL = 15;

class Snake
{
    public:
	void	init();
	void	set_name(std::string);
	void	set_pos(int r, int c, char dir);
	void	set_controls(char l, char r, char f);
	void	set_body(char);
	void	set_EU(int);
	void	set_color(std::string fg, std::string bg);	// not required

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
	std::string name;

	bool	move_forward(char[ROWS][COLS]);
	bool 	turn_right();
	bool 	turn_left();
	void    evaluate_position(char [ROWS][COLS]);  
};
