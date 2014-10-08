#include "navswitch.h"
#include "tinygl.h"
#include "RPS_shapes.h"

void display_character (char character)
{
    char buffer[2];
    buffer[0] = character;
    buffer[1] = '\0';
    tinygl_text (buffer);
}

char character = 'R';

void show_choice(void) 
{	
	tinygl_font_set (&RPS_shapes);
	
	if (navswitch_push_event_p (NAVSWITCH_NORTH))
		character = 'R';

	if (navswitch_push_event_p (NAVSWITCH_WEST))
		character = 'P';
		
	if (navswitch_push_event_p (NAVSWITCH_SOUTH))
		character = 'S';

	display_character (character);

}

// perhaps break out the calls for each player to select here??
void get_selection(void)
{
	
}
