#include "system.h"
#include "pacer.h"
#include "ir_uart.h"
#include "navswitch.h"
#include "selection.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "run.h"

#define PACER_RATE 500
#define LOOP_RATE 500
#define MESSAGE_RATE 15

#define ROCK 'R'
#define PAPER 'P'
#define SCISSORS 'S'

char player1_choice = 0;
char player2_choice = 0;
uint8_t is_game_over = 0;
uint8_t chosen = 0;


/** Initialises tingl module, sets font, mode=scroll,
 * and scroll speed and displays the start message */
void game_init (void)
{
	char messages[] = {"Press start", "Play again?", "Waiting", "Win"
				"Draw", "Lose"};
	char* start_msg = "Press start";
	tinygl_init (LOOP_RATE);      
    tinygl_font_set (&font5x7_1);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL); 
    tinygl_text_speed_set (MESSAGE_RATE);
    
    tinygl_text (start_msg);   
}

/** resets players choices for a new game */
void restart_game(void)
{
	player1_choice = 0;
	player2_choice = 0;			
	is_game_over = 0;
	chosen = 0;
	tinygl_text (restart_msg);
}

/** sets each players choice */
void run_game(void)
{
	if (chosen && player1_choice == '\0') 
    {
		get_choice();
		if (navswitch_push_event_p (NAVSWITCH_PUSH))
		{
			player1_choice = get_choice();	
			tinygl_text (waiting_msg);
		}
	}
		
	if (navswitch_push_event_p (NAVSWITCH_PUSH) && !chosen)
	{
		chosen = !chosen;
	}
	
	if (navswitch_push_event_p (NAVSWITCH_PUSH) && is_game_over) 
	{
		restart_game();
	}
}


/** decides who wins the game based on the selections made*/
void make_decision(void)
{
	// Make decision on who wins
	if (player1_choice != 0 && player2_choice != 0 && !is_game_over)
	{
		if (player1_choice == player2_choice)
		{
			tinygl_text ("Draw"); 
			is_game_over = 1;			
		} 
		else if (player1_choice == ROCK && player2_choice == SCISSORS)
		{
			tinygl_text ("Win"); 
			is_game_over = 1;				
		} 
		else if (player1_choice == SCISSORS && player2_choice == PAPER)
		{
			tinygl_text ("Win");
			is_game_over = 1;			
		} 
		else if (player1_choice == PAPER && player2_choice == ROCK) 
		{
			tinygl_text ("Win");
			is_game_over = 1;				
		} 
		else 
		{
			tinygl_text ("Lose");
			is_game_over = 1;
		}
	}
}

/** send each players choice to their partner's device */
void send_choices(void)
{
	//P1 chosen, send to P2
	if (player1_choice != 0 && !is_game_over) 
	{
		ir_uart_putc (player1_choice);
	}
	
	// Get P2's choice if sent
	if (player2_choice == 0 && ir_uart_read_ready_p () && !is_game_over)
	{
		player2_choice = ir_uart_getc ();			 
	}
}
