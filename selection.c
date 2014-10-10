#include "navswitch.h"
#include "tinygl.h"

char character = 'R';

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
		character = 'R';

	if (navswitch_push_event_p (NAVSWITCH_WEST))
		character = 'P';

	if (navswitch_push_event_p (NAVSWITCH_SOUTH))
		character = 'S';
	display_character (character);

	return character;
	

}
