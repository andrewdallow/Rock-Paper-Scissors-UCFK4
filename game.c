#include "system.h"
#include "pacer.h"
#include "ir_uart.h"
#include "navswitch.h"
#include "selection.h"
#include "start.h"

#define PACER_RATE 500
#define ROCK "R"
#define PAPER "P"
#define SCISSORS "S"

char player1_choice;
char player2_choice;

int main (void)
{
    system_init ();     
    navswitch_init ();    
    pacer_init (PACER_RATE);		
	
	game_begin ();
	
	int is_game_over = 0;
	

    while (1)
    {		
		pacer_wait ();
		
        tinygl_update ();
		navswitch_update ();        
        
		//Lock in choice and block screen
		if (navswitch_push_event_p (NAVSWITCH_PUSH) && player1_choice == NULL)
		{
			player1_choice = character;	
			character = "A";
		} else { // otherwise show selection
			show_choice (); 
		}
		
		//P1 chosen, send to P2
		if (player1_choice != NULL) 
		{
			ir_uart_putc (player1_choice);
		}
		
		// Get P2's choice if sent
		if (ir_uart_read_ready_p ())
		{
			player2_choice = ir_uart_getc ();			 
		}
		
		// Make decision on who wins
		if (player1_choice != NULL && player2_choice != NULL)
		{
			if (player1_choice == player2_choice)
			{
				tinygl_text ("Draw");
				is_game_over = 1;
				
			} else if (player1_choice == ROCK && player2_choice == SCISSORS)
			{
				tinygl_text ("WIN");
				is_game_over = 1;
				
			} else if (player1_choice == SCISSORS && player2_choice == PAPER)
			{
				tinygl_text ("WIN");
				is_game_over = 1;
				
			} else if (player1_choice == PAPER && player2_choice == ROCK) 
			{
				tinygl_text ("WIN");
				is_game_over = 1;
				
			} else {
				tinygl_text ("LOSE");
				is_game_over = 1;
			}
		}
		
		// Start the game over
		if (is_game_over) 
		{
			player1_choice = NULL;
			player2_choice = NULL;
			tinygl_text ("");
			
			is_game_over = 0;
		}
		
    }
    
    return 0;
}
