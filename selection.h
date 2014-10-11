/**	 @file   selection.h
     @author Andrew Dallow - ID: 56999204, Dan Orr - ID: ??
     @date   11 Oct 2014
     @brief  Interface for Maping Navswitch buttons to Rock, Paper, or 
			 Scissors symbols and displays them on the led matrix. 
 */
 
#ifndef SELECTION_H
#define SELECTION_H

#include "system.h"

/** Display the given character on the LED matix */
void display_character (char character);

/** Change between Rock (R), Paper (P), and Scissors (S) on the LED 
 * 	matrix and return the choice */
char get_choice (void);

#endif
