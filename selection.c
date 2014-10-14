/**  @file   selection.c
     @author Andrew Dallow - ID: 56999204, Dan Orr - ID: 53440575
     @date   11 Oct 2014
     @brief  Maps Navswitch buttons to Rock, Paper, or Scissors symbols 
			 and displays them on the led matrix. 
 */

#include "navswitch.h"
#include "tinygl.h"
#include "RPS_shapes.h"

#define ROCK 'R'
#define PAPER 'P'
#define SCISSORS 'S'


static char character = 'R';
/** read character into buffer and display
 * text to screen */
void display_character (char character)
{
    char buffer[2];
    buffer[0] = character;
    buffer[1] = '\0';
    tinygl_text (buffer);
}

char get_choice(void) 
{	
	//tinygl_font_set (&RPS_shapes);
	//tinygl_font_set (&font5x7_1);
		
		
	if (navswitch_push_event_p (NAVSWITCH_NORTH))
	{
		character = ROCK;
	}

	if (navswitch_push_event_p (NAVSWITCH_WEST))
	{
		character = PAPER;
	}

	if (navswitch_push_event_p (NAVSWITCH_SOUTH))
	{
		character = SCISSORS;
	}
	
	display_character (character);

	return character;
	

}
