/**	 @file   run.c
     @author Andrew Dallow - ID: 56999204, Dan Orr - ID: ??
     @date   11 Oct 2014
     @brief  Implements a simple game of Rock, Paper, Scissors. 
 */
 
#include "system.h"
#include "pacer.h"
#include "ir_uart.h"
#include "navswitch.h"
#include "tinygl.h"

#include "../fonts/font5x7_1.h"

#include "selection.h"
#include "run.h"

/* This module implements a 2-player version of a simple Rock, Paper, 
 * Scissors program. Players choose between rock, paper, and scissors 
 * and win based on the following rules:
 * 1) Rock beats Scissors.
 * 2) Paper beats Rock.
 * 3) Scissors beats Paper.
 * The game ends when a winner is decided. 
 * */

// Define Pacer rate in Hz
#define PACER_RATE 500
#define MESSAGE_RATE 15

// The 3 possible choices of Rock, Paper, and Scissors. 
#define ROCK 'R'
#define PAPER 'P'
#define SCISSORS 'S'

// Possible outcomes
#define WIN "WIN"
#define LOSE "LOSE"
#define DRAW "DRAW"

// Text Messaages
#define REPLAY_MESSAGE "Play again?"
#define START_MESSAGE "Press start"
#define WAIT_MESSAGE "Waiting"

#define TRUE 1
#define FALSE 0

// Player Choices
static char player1_choice = '\0';
static char player2_choice = '\0';

static uint8_t is_game_over = FALSE;
static uint8_t choose = FALSE;


void game_init (void)
{	
	// Initialise tingygl
	tinygl_init (PACER_RATE);      
    tinygl_font_set (&font5x7_1);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);
    tinygl_text_speed_set (MESSAGE_RATE);
    
    // Set start message
    tinygl_text (START_MESSAGE);
}

void restart_game(void)
{
	player1_choice = '\0';
	player2_choice = '\0';			
	is_game_over = FALSE;
	choose = FALSE;
	
	// Ask to play gane again
	tinygl_text (REPLAY_MESSAGE);
}


void run_game(void)
{	
	// Player1 may choose if they have not yet.
	if (choose && player1_choice == '\0') 
	{
		get_choice();
		if (navswitch_push_event_p (NAVSWITCH_PUSH))
		{
			player1_choice = get_choice();
			tinygl_font_set (&font5x7_1);	
			tinygl_text (WAIT_MESSAGE);
		}
	}
	
	// Allow choose when button is pushed.
	if (navswitch_push_event_p (NAVSWITCH_PUSH) && !choose)
	{
		choose =!choose;
	}
		
	// Restart game.	
	if (navswitch_push_event_p (NAVSWITCH_PUSH) && is_game_over) 
	{
		restart_game();
	}
}


void make_decision(void)
{
	// Make decision on who wins
		if (player1_choice != '\0' && player2_choice != '\0' && !is_game_over)
		{
			// P1 and P2 have the same choice
			if (player1_choice == player2_choice)
			{
				tinygl_text (DRAW); 
				is_game_over = TRUE;				
			} 
			// Rock Beats Scissors
			else if (player1_choice == ROCK && player2_choice == SCISSORS)
			{
				tinygl_text (WIN); 
				is_game_over = TRUE;				
			} 
			// Scissors beats Paper
			else if (player1_choice == SCISSORS && player2_choice == PAPER)
			{
				tinygl_text (WIN);
				is_game_over = TRUE;				
			} 
			
			// Paper beats Rock
			else if (player1_choice == PAPER && player2_choice == ROCK) 
			{
				tinygl_text (WIN);
				is_game_over = TRUE;				
			} 
			// Any other choice is a Lose.
			else 
			{
				tinygl_text (LOSE);
				is_game_over = TRUE;
			}
		}
}

void communicate_choices(void)
{
	//P1 chosen, send to P2
	if (player1_choice != '\0' && !is_game_over) 
	{
		ir_uart_putc (player1_choice);
	}
	
	// Get P2's choice if sent
	if (player2_choice == '\0' && ir_uart_read_ready_p () && !is_game_over)
	{
		player2_choice = ir_uart_getc ();			 
	}
}
