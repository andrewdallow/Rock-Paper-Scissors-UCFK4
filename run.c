/**  @file   run.c
     @author Andrew Dallow - ID: 56999204, Dan Orr - ID: 53440575
     @date   11 Oct 2014
     @brief  Implements a simple game of Rock, Paper, Scissors.
 */

#include "system.h"
#include "pacer.h"
#include "ir_uart.h"
#include "navswitch.h"
#include "tinygl.h"

#include "../fonts/font5x7_1.h"

#include "selection.h"
#include "run.h"

/** This module implements a 2-player version of a simple Rock, Paper,
 * Scissors program. Players choose between rock, paper, and scissors
 * and win based on the following rules:
 * 1) Rock beats Scissors.
 * 2) Paper beats Rock.
 * 3) Scissors beats Paper.
 * The game ends when a winner is decided.
 * */

// Player Choices
static char player1_choice = '\0';
static char player2_choice = '\0';

static uint8_t isGameOver = FALSE;
static uint8_t player_num = NO_PLAYER;


/** Initialise the game */
void game_init (void)
{
    // Initialise tingygl
    tinygl_init (PACER_RATE);
    tinygl_font_set (&font5x7_1);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);
    tinygl_text_speed_set (MESSAGE_RATE);

    // Set start message
    tinygl_text (START_MESSAGE);
}

/** reset game varibles */
void restart_game (void)
{
    player1_choice = '\0';
    player2_choice = '\0';
    isGameOver = FALSE;
    // Ask to play gane again
    tinygl_text (REPLAY_MESSAGE);
}

/** Set player depending on who started the game. */
void set_players (void)
{
    uint8_t isNoPlayer = player_num == NO_PLAYER;

    if (isNoPlayer && ir_uart_read_ready_p ())
    {
        uint8_t player;

        player = ir_uart_getc ();

        if (player == PLAYER_2)
        {
            player_num = player;
        }
    } else if (navswitch_push_event_p (NAVSWITCH_PUSH) && isNoPlayer)
    {
        player_num = PLAYER_1;
        ir_uart_putc (PLAYER_2);
    }
}

/** Make decision on who wins. */
void make_decision (void)
{
    // Make decision on who wins
    if (player1_choice != '\0' && player2_choice != '\0' && !isGameOver)
    {
        // P1 and P2 have the same choice
        if (player1_choice == player2_choice)
        {
            tinygl_text (DRAW);
            isGameOver = TRUE;
        }
        // Rock Beats Scissors
        else if (player1_choice == ROCK && player2_choice == SCISSORS)
        {
            tinygl_text (WIN);
            isGameOver = TRUE;
        }
        // Scissors beats Paper
        else if (player1_choice == SCISSORS && player2_choice == PAPER)
        {
            tinygl_text (WIN);
            isGameOver = TRUE;
        }

        // Paper beats Rock
        else if (player1_choice == PAPER && player2_choice == ROCK)
        {
            tinygl_text (WIN);
            isGameOver = TRUE;
        }
        // Any other choice is a Lose.
        else
        {
            tinygl_text (LOSE);
            isGameOver = TRUE;
        }
    }
}

/** Encode a message to be sent. */
char encode_message (char message)
{
    char encoded = '\0';
    if (player_num == PLAYER_1)
    {
        encoded = message + PLAYER1_CODE;

    } else if (player_num == PLAYER_2)
    {
        encoded = message + PLAYER2_CODE;
    }

    return encoded;
}

/** Decode a message that was received. */
char decode_message (char message)
{
    char decoded = '\0';

    if (player_num == PLAYER_1)
    {
        decoded = message - PLAYER2_CODE;

    } else if (player_num == PLAYER_2)
    {
        decoded = message - PLAYER1_CODE;
    }

    return decoded;
}

/** Send and receive player choices. */
void communicate_choices (void)
{
    //P1 chosen, send to P2
    if (player1_choice != '\0' && !isGameOver)
    {
        ir_uart_putc (encode_message (player1_choice));
    }

    // Get P2's choice if sent
    if (player2_choice == '\0' && !isGameOver && ir_uart_read_ready_p())
    {
        char choice;

        choice = decode_message (ir_uart_getc ());

        if (choice == ROCK || choice == PAPER || choice == SCISSORS)
        {
            player2_choice = choice;
        }
    }

}

/** Run the game */
void run_game(void)
{
    // Players make choice when players have been chosen.
    if (player_num != NO_PLAYER && player1_choice == '\0')
    {
        get_choice();
        if (navswitch_push_event_p (NAVSWITCH_PUSH))
        {
            player1_choice = get_choice();
            tinygl_font_set (&font5x7_1);
            tinygl_text (WAIT_MESSAGE);
        }
    }

    // Restart game if over.
    if (navswitch_push_event_p (NAVSWITCH_PUSH) && isGameOver)
    {
        restart_game ();
    }

    set_players ();

    communicate_choices ();

    make_decision ();
}
