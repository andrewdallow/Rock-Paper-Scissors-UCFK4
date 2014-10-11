#include "navswitch.h"
#include "tinygl.h"

uint8_t option = 0;

void display_character (char character)
{
    char buffer[2];
    buffer[0] = character;
    buffer[1] = '\0';
    tinygl_text (buffer);
}


char get_choice(void) 
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
