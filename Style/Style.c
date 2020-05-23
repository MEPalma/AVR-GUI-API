//
//  Style.c
//  avr_gui_api
//
//  Created by MarcoEdoardoPalma on 28/04/2019.
//  Copyright © 2019 MarcoEdoardoPalma. All rights reserved.
//

#include "Style.h"

Style
style_init(void)
{
	Style s;
	
	s.b = border_init();

	s.background = WHITE;
	s.foreground = BLACK;

	s.h_text_location = H_CENTER_TEXT;
	s.v_text_location = V_CENTER_TEXT;
	
	return s;
}

void
style_debug_printf(Style s)
{
	border_debug_printf(s.b);
}
