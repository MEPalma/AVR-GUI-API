//
//  Geom.h
//  avr_gui_api
//
//  Created by MarcoEdoardoPalma on 28/04/2019.
//  Copyright © 2019 MarcoEdoardoPalma. All rights reserved.
//

#ifndef Geom_h
#define Geom_h

#include <stdio.h>

typedef struct StructGeom
{
	int x;
	int y;
	int preferred_width;
	int preferred_height;
} Geom;

Geom
geom_init(const int x, const int y, const int preferred_width, const int preferred_height);

void
geom_debug_printf(Geom g);
#endif /* Geom_h */
