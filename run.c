#include "system.h"
#include "pacer.h"
#include "ir_uart.h"
#include "navswitch.h"
#include "selection.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "run.h"

#define PACER_RATE 500
#define MESSAGE_RATE 15
#define ROCK 'R'
#define PAPER 'P'
#define SCISSORS 'S'

char player1_choice = 0;
char player2_choice = 0;
uint8_t is_game_over = 0;
uint8_t choose = 0;

void game_init (void)
{
	char* start_msg = "Press start";
	tinygl_init (PACER_RATE);      
    tinygl_font_set (&font5x7_1);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);
    tinygl_text_speed_set (MESSAGE_RATE);
    
    tinygl_text (start_msg);
}

void restart_game(void)
{
	player1_choice = 0;
	player2_choice = 0;			
	is_game_over = 0;
	choose = 0;
	tinygl_text ("Play again?");
}



void run_game(void)
{
	if (choose && player1_choice == '\0') 
        {
			get_choice();
			if (navswitch_push_event_p (NAVSWITCH_PUSH))
			{
				player1_choice = get_choice();	
				tinygl_text ("Waiting");
			}
		}
		
	if (navswitch_push_event_p (NAVSWITCH_PUSH) && !choose)
	{
		choose =!choose;
	}
	
	if (navswitch_push_event_p (NAVSWITCH_PUSH) && is_game_over) 
	{
		restart_game();
	}
}



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
				tinygl_text ("WIN"); 
				is_game_over = 1;				
			} 
			else if (player1_choice == SCISSORS && player2_choice == PAPER)
			{
				tinygl_text ("WIN");
				is_game_over = 1;				
			} 
			else if (player1_choice == PAPER && player2_choice == ROCK) 
			{
				tinygl_text ("WIN");
				is_game_over = 1;				
			} 
			else 
			{
				tinygl_text ("LOSE");
				is_game_over = 1;
			}
		}
}

void communicate_choices(void)
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
