//
//  Label.c
//  avr_gui_api
//
//  Created by MarcoEdoardoPalma on 26/04/2019.
//  Copyright © 2019 MarcoEdoardoPalma. All rights reserved.
//

#include "Label.h"

typedef struct StructLabel
{
	Geom geom;
	Style sty;
	MEPString str;

	int isOnFocus;
	void (*fun_ptr)(void* stage, void* this_label);
} Label;


MEPLabel
MEPLabel_init(char* text, int x, int y, int pW, int pH)
{
	Label* label = (Label*) calloc(1, sizeof(Label));
	
	label->geom = geom_init(x, y, pW, pH);
	label->sty = style_init();
	label->str = MEPStr_init(text);
	label->isOnFocus = 0;

	return label;
}

char*
MEPLabel_get_text(MEPLabel lb)
{
	Label* l = lb;
	return MEPStr_get_lit(l->str);
}

//getters
Geom
MEPLabel_get_geom(MEPLabel lb)
{
	return ((Label *) lb)->geom;
}

Style
MEPLabel_get_style(MEPLabel lb)
{
	return ((Label*)lb)->sty;
}

MEPString
MEPLabel_get_mepstring(MEPLabel lb)
{
	return ((Label*) lb)->str;
}

int
MEPLabel_is_on_focus(MEPLabel lb)
{
	return ((Label*) lb)->isOnFocus;
}

//setters

void
MEPLabel_add_tag_on_focus(MEPLabel lb)
{
	((Label*)lb)->isOnFocus = 1;
}

void
MEPLabel_rm_tag_on_focus(MEPLabel lb)
{
	((Label*)lb)->isOnFocus = 0;
}

void
MEPLabel_set_geom(MEPLabel lb, Geom g)
{
	((Label*) lb)->geom = g;
}

void
MEPLabel_set_geom_raw(MEPLabel lb, const int x, const int y, const int pw, const int ph)
{
	((Label*) lb)->geom = geom_init(x, y, pw, ph);
}

void
MEPLabel_set_style(MEPLabel lb, Style s)
{
	((Label*) lb)->sty = s;
}

void
MEPLabel_set_text(MEPLabel lb, char* text)
{
	MEPString tmp = ((Label*)lb)->str;
	MEPStr_set_text(tmp, text);
}

void
MEPLabel_set_mepstring(MEPLabel lb, MEPString ms)
{
	Label* tmp = lb;
	free(tmp->str);
	tmp->str = ms;
}

int
MEPLabel_get_text_width(MEPLabel lb)
{
	int n_chars = MEPStr_length(MEPLabel_get_mepstring(lb));
	return (n_chars + (n_chars * 5));
}

void
MEPLabel_get_text_location(MEPLabel lb, int* x, int* y)
{
	Label* l = lb;
	*x = l->geom.x;
	*y = l->geom.y;

	{
		if (l->sty.h_text_location == H_LEFT_TEXT) *x += l->sty.b.bw_left;
		else if (l->sty.h_text_location == H_RIGHT_TEXT) *x = l->geom.x + l->geom.preferred_width - l->sty.b.bw_right - MEPLabel_get_text_width(lb);
		else if (l->sty.h_text_location == H_CENTER_TEXT) *x += ((l->geom.preferred_width) / 2) - (MEPLabel_get_text_width(lb) / 2);
	}

	{
		if (l->sty.v_text_location == V_TOP_TEXT) *y += l->sty.b.bw_top;
		else if (l->sty.v_text_location == V_BOTTOM_TEXT) *y += (l->geom.preferred_height - 7 - l->sty.b.bw_bottom);
		else if (l->sty.v_text_location == V_CENTER_TEXT) *y += ((l->geom.preferred_height - 7) / 2);
	}
}

void
MEPLabel_debug_printf(MEPLabel lb)
{
	printf("\n|------ LABEL DEBUG ------\n");
	Label* tmp = lb;
	printf("Text: %s\n", MEPStr_get_lit(tmp->str));
	geom_debug_printf(tmp->geom);
	style_debug_printf(tmp->sty);
	
	printf("\n\n");
}

int
MEPLable_is_selected(MEPLabel lb, const int x, const int y)
{
	Label* lb_ptr = lb;
	return ((x >= lb_ptr->geom.x) && (x <= (lb_ptr->geom.x + lb_ptr->geom.preferred_width)) &&
			(y >= lb_ptr->geom.y) && (y <= lb_ptr->geom.y + lb_ptr->geom.preferred_height));
}

void
MEPLabel_set_on_click_event(MEPLabel lb, void (*fun_ptr)(void*, void*))
{
	((Label*) lb)->fun_ptr = fun_ptr;
}

void
MEPLabel_call_on_click_event(MEPLabel lb, void* stage)
{
	if (((Label*) lb)->fun_ptr != NULL)
		(*((Label*) lb)->fun_ptr)(stage, lb);
}