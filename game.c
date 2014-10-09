#include "system.h"
#include "pacer.h"
#include "ir_uart.h"
#include "navswitch.h"
//#include "selection.h"
#include "start.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"

#define PACER_RATE 500
#define MESSAGE_RATE 15
#define ROCK 'R'
#define PAPER 'P'
#define SCISSORS 'S'

char player1_choice;
char player2_choice = 'R';


char choice = 'R';

void display_character (char character)
{
    char buffer[2];
    buffer[0] = character;
    buffer[1] = '\0';
    tinygl_text (buffer);
}

void show_choice(void) 
{	
	//tinygl_font_set (&RPS_shapes);
	//tinygl_font_set (&font5x7_1);
	
	if (navswitch_push_event_p (NAVSWITCH_NORTH))
		choice = 'R';

	if (navswitch_push_event_p (NAVSWITCH_WEST))
		choice = 'P';
		
	if (navswitch_push_event_p (NAVSWITCH_SOUTH))
		choice = 'S';

	display_character (choice);

}

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
		if (navswitch_push_event_p (NAVSWITCH_PUSH) && player1_choice == '\0')
		{
			player1_choice = choice;	
			//tinygl_text ("Waiting");
			display_character (player1_choice);
			
		} else if (player1_choice == 0)
		{ // otherwise show selection
			show_choice ();
		}
		
		
		//P1 chosen, send to P2
		//if (player1_choice != '\0') 
		//{
			//ir_uart_putc (player1_choice);
		//}
		
		// Get P2's choice if sent
		if (ir_uart_read_ready_p ())
		{
			//player2_choice = ir_uart_getc ();			 
		}
		
		// Make decision on who wins
		if (player1_choice != '\0' && player2_choice != '\0')
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
		//if (is_game_over) 
		//{
			//player1_choice = '\0';
			//player2_choice = '\0';
			//tinygl_text ("Over");
			
		//	is_game_over = 0;
		//}
		
    }
    
    return 0;
}
