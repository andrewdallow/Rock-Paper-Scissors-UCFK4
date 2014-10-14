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

static uint8_t option = 0;

/** read character into buffer and display
 * text to screen */
void display_character (char character)
{
    char buffer[2];
    buffer[0] = character;
    buffer[1] = '\0';
    tinygl_text (buffer);
}

/** Cycles through the options Paper, Rock Sizzors
 * and any navswitch option */
char get_choice(void) 
{			
	tinygl_font_set (&RPS_shapes);
	char disp_char = 0;
	if (navswitch_push_event_p (NAVSWITCH_NORTH)){
		option++;
		if(option == 3)
		{
			option = 0;
		}
	}
	if (navswitch_push_event_p (NAVSWITCH_SOUTH))
		option++;
		if(option == 3)
		{
			option = 0;
		}
	
	if (navswitch_push_event_p (NAVSWITCH_EAST))
		option++;
		if(option == 3)
		{
			option = 0 ;
		}

	if (navswitch_push_event_p (NAVSWITCH_WEST))
		option++;
		if(option == 3)
		{
			option = 0;
		}		
		
		if(option == 0)
		{
			disp_char = PAPER;
		}
		else if (option == 1)
		{
			disp_char = ROCK;
		}
		else if (option == 2)
		{
			disp_char = SCISSORS;
		}		
	display_character (disp_char);

	return disp_char;
}
