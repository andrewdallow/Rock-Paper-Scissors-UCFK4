/**  @file   selection.c
     @author Andrew Dallow - ID: 56999204, Dan Orr - ID: ??
     @date   11 Oct 2014
     @brief  Maps Navswitch buttons to Rock, Paper, or Scissors symbols 
			 and displays them on the led matrix. 
 */

#include "navswitch.h"
#include "tinygl.h"

#include "selection.h"
#include "RPS_shapes.h"

// The 3 possible choices of Rock, Paper, and Scissors. 
#define ROCK 'R'
#define PAPER 'P'
#define SCISSORS 'S'

static char character = ROCK;

void display_character (char character)
{
    char buffer[2];
    buffer[0] = character;
    buffer[1] = '\0';
    tinygl_text (buffer);
}


char get_choice(void) 
{	
	tinygl_font_set (&RPS_shapes);
	
	//Display symbol depending on button press. 		
		
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
