/**  @file   run.c
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
#define LOOP_RATE 500
#define MESSAGE_RATE 15

<<<<<<< HEAD
=======
// The 3 possible choices of Rock, Paper, and Scissors. 
>>>>>>> 362867cab8b7937b626575b0dba3f52b13706b86
#define ROCK 'R'
#define PAPER 'P'
#define SCISSORS 'S'

<<<<<<< HEAD
char player1_choice = 0;
char player2_choice = 0;
uint8_t is_game_over = 0;
uint8_t chosen = 0;
=======
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
>>>>>>> 362867cab8b7937b626575b0dba3f52b13706b86


/** Initialises tingl module, sets font, mode=scroll,
 * and scroll speed and displays the start message */
void game_init (void)
<<<<<<< HEAD
{
	char messages[] = {"Press start", "Play again?", "Waiting", "Win"
				"Draw", "Lose"};
	char* start_msg = "Press start";
	tinygl_init (LOOP_RATE);      
=======
{	
	// Initialise tingygl
	tinygl_init (PACER_RATE);      
>>>>>>> 362867cab8b7937b626575b0dba3f52b13706b86
    tinygl_font_set (&font5x7_1);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL); 
    tinygl_text_speed_set (MESSAGE_RATE);
    
<<<<<<< HEAD
    tinygl_text (start_msg);   
=======
    // Set start message
    tinygl_text (START_MESSAGE);
>>>>>>> 362867cab8b7937b626575b0dba3f52b13706b86
}

/** resets players choices for a new game */
void restart_game(void)
{
<<<<<<< HEAD
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
=======
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
>>>>>>> 362867cab8b7937b626575b0dba3f52b13706b86
	{
		chosen = !chosen;
	}
		
	// Restart game.	
	if (navswitch_push_event_p (NAVSWITCH_PUSH) && is_game_over) 
	{
		restart_game();
	}
}


<<<<<<< HEAD
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
=======
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
>>>>>>> 362867cab8b7937b626575b0dba3f52b13706b86
		}
	}
}

/** send each players choice to their partner's device */
void send_choices(void)
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
