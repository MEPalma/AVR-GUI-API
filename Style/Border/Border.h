//
//  Border.h
//  avr_gui_api
//
//  Created by MarcoEdoardoPalma on 28/04/2019.
//  Copyright © 2019 MarcoEdoardoPalma. All rights reserved.
//

#ifndef Border_h
#define Border_h

#include <stdio.h>

typedef struct StructBorder {
	int bw_top;
	int bw_right;
	int bw_bottom;
	int bw_left;
	
	int bc_top;
	int bc_right;
	int bc_bottom;
	int bc_left;
} Border;

Border
border_init(void);

void
border_debug_printf(Border b);

#endif /* Border_h */
