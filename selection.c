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

static char character[3] = {ROCK, PAPER, SCISSORS};
static uint8_t option = 0;
static uint8_t num_choices = 3;

/** read character into buffer and display
 * text to screen */  
void display_character (char character)
{
    char buffer[2];
    buffer[0] = character;
    buffer[1] = '\0';
    tinygl_text (buffer);
}


/** Cycles through the options Paper, Rock and Sissors
 * with up/down navswitch option */
char get_choice(void) 
{			
	tinygl_font_set (&RPS_shapes);
	
	if (navswitch_push_event_p (NAVSWITCH_NORTH))
	{		
		option = (option + 1) % num_choices;
	}
	
	if (navswitch_push_event_p (NAVSWITCH_SOUTH))
	{
		if (option != 0)
		{
			option = (option - 1) % num_choices;
			
		} else {
			
			option = 2;
		}
	}
			
	display_character (character[option]);

	return character[option];
}
