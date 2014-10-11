#include "pacer.h"
#include "ir_uart.h"
#include "navswitch.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "start.h"

#define PACER_RATE 500
#define MESSAGE_RATE 15
#define LOOP_RATE 500

void game_init (void)
{
	char* start_msg = "Press start";
	tinygl_init (LOOP_RATE);      
    tinygl_font_set (&font5x7_1);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);
    tinygl_text_speed_set (MESSAGE_RATE);
    
    tinygl_text (start_msg);
    ir_uart_init ();
}

int is_player_ready (void) 
{
	char ready_msg;
	if (ir_uart_read_ready_p ())
	{
		ready_msg = ir_uart_getc ();			 
	}
	
	if (ready_msg == 'R') {
		return 0;
	}
	return 1;
}

void game_begin (void) 
{
	game_init ();
	
	uint8_t  not_ready = 1;
	
	while (not_ready) 
	{
		pacer_wait ();	
		navswitch_update ();

		if (navswitch_push_event_p (NAVSWITCH_PUSH))
		{
			ir_uart_putc ('R');
			not_ready = !not_ready;
		}
		 else
		 {
			not_ready = is_player_ready ();
		}
        tinygl_update ();
	}
}

