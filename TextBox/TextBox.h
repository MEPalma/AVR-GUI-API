//
//  TextBox.h
//  avr_gui_api
//
//  Created by MarcoEdoardoPalma on 07/05/2019.
//  Copyright © 2019 MarcoEdoardoPalma. All rights reserved.
//

#include <stdlib.h>
#include "../String/String.h"
#include "../Style/Style.h"
#include "../Geom/Geom.h"

#ifndef TextBox_h
#define TextBox_h

#define MEP_TextBox void*

MEP_TextBox
MEP_TextBox_init(char* text, int x, int y, int pW, int pH);

void
MEP_TextBox_set_on_keyb_about_to_open_event(MEP_TextBox tb, void (*after_keyb_input)(void*, void*));

void
MEP_TextBox_invoke_after_keyb_input(void* stage, MEP_TextBox tb);

char*
MEP_TextBox_get_text(MEP_TextBox tb);

Geom
MEP_TextBox_get_geom(MEP_TextBox tb);

Style
MEP_TextBox_get_style(MEP_TextBox tb);

MEPString
MEP_TextBox_get_mepstring(MEP_TextBox tb);

int
MEP_TextBox_get_text_width(MEP_TextBox tb);

void
MEP_TextBox_get_text_location(MEP_TextBox tb, int* x, int* y);

int
MEP_TextBox_is_selected(MEP_TextBox tb, const int x, const int y);

int
MEP_TextBox_is_on_focus(MEP_TextBox tb);

int
MEP_TextBox_is_on_focus(MEP_TextBox tb);


void
MEP_TextBox_add_tag_on_focus(MEP_TextBox tb);

void
MEP_TextBox_rm_tag_on_focus(MEP_TextBox tb);

void
MEP_TextBox_set_geom(MEP_TextBox tb, Geom g);

void
MEP_TextBox_set_geom_raw(MEP_TextBox tb, const int x, const int y, const int pw, const int ph);

void
MEP_TextBox_set_style(MEP_TextBox tb, Style s);

void
MEP_TextBox_set_text(MEP_TextBox tb, char* text);

void
MEP_TextBox_append_text(MEP_TextBox tb, char* text);

#endif /* TextBox_h */
