#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "tinygl.h"
#include "run.h"
#include "ir_uart.h"

#define PACER_RATE 500

int main (void)
{
	
	system_init ();     
    navswitch_init ();    
    pacer_init (PACER_RATE);	
    ir_uart_init ();
	game_init ();	

    while (1)
    {		
		pacer_wait ();
		
        tinygl_update ();
		navswitch_update ();
        run_game();		
		
		communicate_choices();
		
		make_decision();
    }
    

    return 0;
}
