//
//  Style.h
//  avr_gui_api
//
//  Created by MarcoEdoardoPalma on 28/04/2019.
//  Copyright © 2019 MarcoEdoardoPalma. All rights reserved.
//

#ifndef Style_h
#define Style_h

#include <stdio.h>
#include "Border/Border.h"

/* Colour definitions RGB565 */
#define WHITE       0xFFFF
#define BLACK       0x0000
#define BLUE        0x001F      
#define GREEN       0x07E0      
#define CYAN        0x07FF      
#define RED         0xF800      
#define MAGENTA     0xF81F      
#define YELLOW      0xFFE0     

#define H_LEFT_TEXT 0
#define H_CENTER_TEXT 1
#define H_RIGHT_TEXT 2

#define V_TOP_TEXT 0
#define V_CENTER_TEXT 1
#define V_BOTTOM_TEXT 2

typedef struct StructStyle {
	Border b;
	
	int foreground;
	int background;

	int v_text_location;
	int h_text_location;

} Style;

Style
style_init(void);

void
style_debug_printf(Style s);

#endif /* Style_h */
