//
//  Label.h
//  avr_gui_api
//
//  Created by MarcoEdoardoPalma on 26/04/2019.
//  Copyright © 2019 MarcoEdoardoPalma. All rights reserved.
//

#ifndef Label_h
#define Label_h

#include "../String/String.h"
#include "../Style/Style.h"
#include "../Geom/Geom.h"

#include <stdio.h>
#include <stdlib.h>

#define MEPLabel void*

MEPLabel
MEPLabel_init(char*, int x, int y, int pW, int pH);

char*
MEPLabel_get_text(MEPLabel lb);

//getters
Geom
MEPLabel_get_geom(MEPLabel lb);

Style
MEPLabel_get_style(MEPLabel lb);

MEPString
MEPLabel_get_mepstring(MEPLabel lb);
int
MEPLabel_is_on_focus(MEPLabel lb);

//setters
void
MEPLabel_add_tag_on_focus(MEPLabel lb);

void
MEPLabel_rm_tag_on_focus(MEPLabel lb);

void
MEPLabel_set_geom(MEPLabel lb, Geom g);

void
MEPLabel_set_geom_raw(MEPLabel lb, const int x, const int y, const int pw, const int ph);

void
MEPLabel_set_style(MEPLabel lb, Style s);

void
MEPLabel_set_text(MEPLabel lb, char* text);

void
MEPLabel_set_mepstring(MEPLabel lb, MEPString ms);

void
MEPLabel_get_text_location(MEPLabel lb, int* x, int* y);

void
MEPLabel_debug_printf(MEPLabel lb);

int
MEPLable_is_selected(MEPLabel lb, const int x, const int y);

void
MEPLabel_set_on_click_event(MEPLabel lb, void (*fun_ptr)(void*, void*));

void
MEPLabel_call_on_click_event(MEPLabel lb, void* stage);

#endif /* Label_h */
