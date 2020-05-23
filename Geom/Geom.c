//
//  Geom.c
//  avr_gui_api
//
//  Created by MarcoEdoardoPalma on 28/04/2019.
//  Copyright © 2019 MarcoEdoardoPalma. All rights reserved.
//

#include "Geom.h"

Geom
geom_init(const int x, const int y, const int preferred_width, const int preferred_height)
{
	Geom g;
	
	g.x = x;
	g.y = y;
	g.preferred_width = preferred_width;
	g.preferred_height = preferred_height;
	
	return g;
}

void
geom_debug_printf(Geom g)
{
	printf("Geom: (x: %d), (y: %d), (pw: %d), (ph: %d)\n", g.x, g.y, g.preferred_width, g.preferred_height);
}
