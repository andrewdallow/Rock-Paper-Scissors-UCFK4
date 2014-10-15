/**  @file   run.h
     @author Andrew Dallow - ID: 56999204, Dan Orr - ID: 53440575
     @date   11 Oct 2014
     @brief  interface for a simple game of Rock, Paper, Scissors.
 */
 
#ifndef RUN_H
#define RUN_H

/** Define Pacer rate in Hz */
#ifndef PACER_RATE
#define PACER_RATE 200
#endif
#ifndef MESSAGE_RATE
#define MESSAGE_RATE 15
#endif

/** The 3 possible choices of Rock, Paper, and Scissors.  */
#ifndef ROCK
#define ROCK 'R'
#endif
#ifndef PAPER
#define PAPER 'P'
#endif
#ifndef SCISSORS
#define SCISSORS 'S'
#endif

// Possible outcomes
#ifndef WIN
#define WIN "WIN"
#endif
#ifndef LOSE
#define LOSE "LOSE"
#endif
#ifndef DRAW
#define DRAW "DRAW"
#endif

// Text Messaages
#ifndef REPLAY_MESSAGE
#define REPLAY_MESSAGE "Play again?"
#endif
#ifndef START_MESSAGE
#define START_MESSAGE "Press start"
#endif
#ifndef WAIT_MESSAGE
#define WAIT_MESSAGE "Waiting"
#endif

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif


// Players
#ifndef NO_PLAYER
#define NO_PLAYER 0
#endif
#ifndef PLAYER_1
#define PLAYER_1 1
#endif
#ifndef PLAYER_2
#define PLAYER_2 2
#endif

// Player encoding/decoding values
#define PLAYER1_CODE 5;
#define PLAYER2_CODE 10;


#include "system.h"

/** Initialise the game. */
void game_init (void);

/** Reset the game variables. */
void restart_game (void);

/** Set player depending on who started the game. */
void set_players (void);

/** Start the game. */
void run_game (void);

/** Make a dicission on who wins the current game. */
void make_decision (void);

/** Encode the message to be sent. */
char encode_message (char message);

/** Decode the received message from other player. */
char decode_message (char message);

/** Send choice to player 2 and receive player 2 chocie. */
void communicate_choices (void);

#endif
