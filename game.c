/**  @file   game.c
     @author Andrew Dallow - ID: 56999204, Dan Orr - ID: 53440575
     @date   11 Oct 2014
     @brief  A simple 2 player game of Rock, Paper, Sissors. 
 */

#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "tinygl.h"
#include "ir_uart.h"

#include "run.h"

/* Define Pacer rate in Hz */
#define PACER_RATE 200

/* Run the main loop of the game */
int main (void)
{
	//Initialise system and game.
	system_init ();     
    navswitch_init ();    
    pacer_init (PACER_RATE);	
    ir_uart_init ();
    
	game_init ();	
	
	// Main loop of game
    while (1)
    {		
		pacer_wait ();
		
        tinygl_update ();
		navswitch_update ();
		
        run_game();			
    }
    

    return 0;
}
