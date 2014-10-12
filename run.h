/**	 @file   run.h
     @author Andrew Dallow - ID: 56999204, Dan Orr - ID: ??
     @date   11 Oct 2014
     @brief  interface for a simple game of Rock, Paper, Scissors.
 */
 
#ifndef RUN_H
#define RUN_H

#include "system.h"

/** Initialise the game. */
void game_init (void);

/** Reset the game variables. */
void restart_game (void);

/** Start the game. */
void run_game (void);

/** Make a dicission on who wins the current game. */
void make_decision (void);

/** Send choice to player 2 and receive player 2 chocie. */
void communicate_choices (void);

#endif
