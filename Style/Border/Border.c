//
//  Border.c
//  avr_gui_api
//
//  Created by MarcoEdoardoPalma on 28/04/2019.
//  Copyright © 2019 MarcoEdoardoPalma. All rights reserved.
//

#include "Border.h"

Border
border_init()
{
	Border b;
	
	b.bw_top = 0;
	b.bw_right = 0;
	b.bw_bottom = 0;
	b.bw_left = 0;
	b.bc_top = 0;
	b.bc_right = 0;
	b.bc_bottom = 0;
	b.bc_left = 0;
	
	return b;
}


void
border_debug_printf(Border b)
{
	printf("Border: (b.bw_top: %d), (b.bw_right: %d), (b.bw_bottom: %d), (b.bw_left: %d), (b.bc_top: %d), (b.bc_right: %d), (b.bc_bottom: %d), (b.bc_left: %d)\n",
					 b.bw_top,       b.bw_right,       b.bw_bottom,       b.bw_left,       b.bc_top,       b.bc_right,       b.bc_bottom,       b.bc_left);
}
