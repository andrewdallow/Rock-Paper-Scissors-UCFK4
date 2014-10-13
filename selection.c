/**  @file   selection.c
     @author Andrew Dallow - ID: 56999204, Dan Orr - ID: ??
     @date   11 Oct 2014
     @brief  Maps Navswitch buttons to Rock, Paper, or Scissors symbols 
			 and displays them on the led matrix. 
 */

#include "navswitch.h"
#include "tinygl.h"

<<<<<<< HEAD
uint8_t option = 0;
=======
#include "selection.h"
#include "RPS_shapes.h"

// The 3 possible choices of Rock, Paper, and Scissors. 
#define ROCK 'R'
#define PAPER 'P'
#define SCISSORS 'S'

static char character = ROCK;
>>>>>>> 362867cab8b7937b626575b0dba3f52b13706b86

void display_character (char character)
{
    char buffer[2];
    buffer[0] = character;
    buffer[1] = '\0';
    tinygl_text (buffer);
}


char get_choice(void) 
<<<<<<< HEAD
{			
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
=======
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
>>>>>>> 362867cab8b7937b626575b0dba3f52b13706b86
	
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
			disp_char = 'P';
		}
		else if (option == 1)
		{
			disp_char = 'R';
		}
		else if (option == 2)
		{
			disp_char = 'S';
		}		
	display_character (disp_char);

	return disp_char;
}
