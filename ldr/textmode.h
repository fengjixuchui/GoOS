/********************************************************
 *	GoOS Loader - textmode.h
 ********************************************************
 * Copyright (c) 2016, Gert Nutterts
 * All rights reserved
 *
 * Released under the BSD 3-clause license.
 * https://github.com/nutterts/GoOS/blob/master/LICENSE
 ********************************************************/
#ifndef __TEXTMODE_H__
#define __TEXTMODE_H__ 1

// Get pointer to base vga ioport
#define bda_vga_ioport (*(volatile uint16_t *)(0x463 & 0xFFFF))

/* Textmode colors */
typedef enum {
  BLACK         = 0,
  BLUE		      = 1,
  GREEN 		    = 2,
  CYAN  		    = 3,
  RED   		    = 4,
  MAGENTA 	    = 5,
  BROWN 		    = 6,
  LIGHT_GREY	  = 7,
  GREY 		      = 8,
  LIGHT_BLUE 	  = 9,
  LIGHT_GREEN   = 10,
  LIGHT_CYAN 	  = 11,
  LIGHT_RED	    = 12,
  LIGHT_MAGENTA = 13,
  LIGHT_BROWN   = 14,
  WHITE 		    = 15
} tmColors;

static const size_t TEXTMODE_HEIGHT = 25;
static const size_t TEXTMODE_WIDTH = 80;

extern size_t 	tmRow;
extern size_t 	tmColumn;
extern uint8_t	tmColor;
extern uint16_t	*tmBuffer;

/* Cursor struct */
typedef struct {
	size_t column;
	size_t row;
} tmCursor_t;


/* Function prototypes */

void 	tmInit		();
void 	tmWriteAt	(char, uint8_t, size_t, size_t);
void	tmWriteChr	(char c);
void 	tmWrite 	(const char *);
void	tmScroll	(void);
void	tmWriteInt	(int64_t);
void	tmWriteUInt	(uint64_t);
void	tmWriteHex	(uint64_t);
void	tmWriteBin	(uint64_t);
void	tmWriteOct	(uint64_t);
void	tmCRLF		(void);
void  tmSetCursor	(size_t, size_t);
bool	tmBoolStr	(bool, char *, char *);

tmCursor_t 			tmGetCursor (void);

// Make color
inline
uint8_t
tmMakeColor(tmColors fg, tmColors bg)
{
	return fg | bg << 4;
}

// Make entry
inline
uint16_t
tmMakeEntry(char c, uint8_t color)
{
	uint16_t c16 = c;
 	uint16_t cl16 = color;
 	return c16 | cl16 << 8;
}

#endif
