/**	 @file   selection.c
     @author Andrew Dallow - ID: 56999204, Dan Orr - ID: ??
     @date   11 Oct 2014
     @brief  Maps Navswitch buttons to Rock, Paper, or Scissors symbols 
			 and displays them on the led matrix. 
 */


#include "navswitch.h"
#include "tinygl.h"

#include "selection.h"

static char character = 'R';

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
		character = 'R';
	}

	if (navswitch_push_event_p (NAVSWITCH_WEST))
	{
		character = 'P';
	}

	if (navswitch_push_event_p (NAVSWITCH_SOUTH))
	{
		character = 'S';
	}
	
	display_character (character);

	return character;
	

}
