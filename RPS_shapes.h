/** @file    RPS_shapes.h
    @author  fontgen
    @date    07 Oct 2014

    @defgroup RPS_shapes  This is a 5x7 set of Rock, Paper, Scissors shapes

*/

#ifndef RPS_SHAPES_H_
#define RPS_SHAPES_H_

#define RPS_SHAPES_WIDTH 5
#define RPS_SHAPES_HEIGHT 7
#define RPS_SHAPES_OFFSET 32
#define RPS_SHAPES_SIZE 52

#ifndef FONT_WIDTH
#define FONT_WIDTH 5
#endif
#ifndef FONT_HEIGHT
#define FONT_HEIGHT 7
#endif
#ifndef FONT_OFFSET
#define FONT_OFFSET 32
#endif
#ifndef FONT_SIZE_MAX
#define FONT_SIZE_MAX 52
#endif
#include "font.h"

static font_t RPS_shapes =
{
    .flags = 1, /* (packed)  */
    .width = 5,
    .height = 7,
    .offset = 32,
    .size = 52,
    .bytes = 5,
    .data =
    {
        /*    */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* !  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* "  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* #  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* $  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* %  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* &  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* '  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* (  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* )  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* *  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* +  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* ,  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* -  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* .  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* /  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* 0  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* 1  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* 2  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* 3  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* 4  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* 5  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* 6  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* 7  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* 8  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* 9  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* :  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* ;  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* <  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* =  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* >  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* ?  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* @  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* A  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* B  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* C  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* D  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* E  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* F  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* G  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* H  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* I  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* J  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* K  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* L  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* M  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* N  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* O  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* P  */
        0x3f, 0xc6, 0x18, 0xe3, 0x07, 
        /* Q  */
        0x00, 0x00, 0x00, 0x00, 0x00, 
        /* R  */
        0x80, 0x38, 0xff, 0x1d, 0x00, 
        /* S  */
        0x20, 0x2a, 0x42, 0xd4, 0x06, 
    }
};
#endif  /* RPS_SHAPES_H_  */