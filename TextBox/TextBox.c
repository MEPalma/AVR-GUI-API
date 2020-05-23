#include "TextBox.h"

typedef struct {
    Geom g;
    Style s;
    MEPString text;
    int is_on_focus;
	void (*after_keyb_input)(void* stage, void* tb);
} TextBox;

MEP_TextBox
MEP_TextBox_init(char* text, int x, int y, int pW, int pH)
{
    TextBox* tb = (TextBox*) calloc(1, sizeof(TextBox));
    tb->g = geom_init(x, y, pW, pH);
    tb->s = style_init();
    tb->text = MEPStr_init(text);
    tb->is_on_focus = 0;

    return tb;
}

void
MEP_TextBox_set_on_keyb_about_to_open_event(MEP_TextBox tb, void (*after_keyb_input)(void*, void*))
{
	((TextBox*) tb)->after_keyb_input = after_keyb_input;
}

void
MEP_TextBox_invoke_after_keyb_input(void* stage, MEP_TextBox tb)
{
    if (((TextBox*) tb)->after_keyb_input != NULL)
		(*((TextBox*) tb)->after_keyb_input)(stage, tb);
}

char*
MEP_TextBox_get_text(MEP_TextBox tb)
{
	TextBox* t = tb;
	return MEPStr_get_lit(t->text);
}

Geom
MEP_TextBox_get_geom(MEP_TextBox tb)
{
	return ((TextBox *) tb)->g;
}

Style
MEP_TextBox_get_style(MEP_TextBox tb)
{
	return ((TextBox*) tb)->s;
}

MEPString
MEP_TextBox_get_mepstring(MEP_TextBox tb)
{
	return ((TextBox*) tb)->text;
}

int
MEP_TextBox_get_text_width(MEP_TextBox tb)
{
	int n_chars = MEPStr_length(MEP_TextBox_get_mepstring(tb));
	return (n_chars + (n_chars * 5));
}

void
MEP_TextBox_get_text_location(MEP_TextBox tb, int* x, int* y)
{
	TextBox* t = tb;
	*x = t->g.x;
	*y = t->g.y;

	{
		if (t->s.h_text_location == H_LEFT_TEXT) *x += t->s.b.bw_left;
		else if (t->s.h_text_location == H_RIGHT_TEXT) *x = t->g.x + t->g.preferred_width - t->s.b.bw_right - MEP_TextBox_get_text_width(tb);
		else if (t->s.h_text_location == H_CENTER_TEXT) *x += ((t->g.preferred_width) / 2) - (MEP_TextBox_get_text_width(tb) / 2);
	}

	{
		if (t->s.v_text_location == V_TOP_TEXT) *y += t->s.b.bw_top;
		else if (t->s.v_text_location == V_BOTTOM_TEXT) *y += (t->g.preferred_height - 7 - t->s.b.bw_bottom);
		else if (t->s.v_text_location == V_CENTER_TEXT) *y += ((t->g.preferred_height - 7) / 2);
	}
}

int
MEP_TextBox_is_selected(MEP_TextBox tb, const int x, const int y)
{
	TextBox* tb_ptr = tb;
	return ((x >= tb_ptr->g.x) && (x <= (tb_ptr->g.x + tb_ptr->g.preferred_width)) &&
			(y >= tb_ptr->g.y) && (y <= tb_ptr->g.y + tb_ptr->g.preferred_height));
}

int
MEP_TextBox_is_on_focus(MEP_TextBox tb)
{
	return ((TextBox*) tb)->is_on_focus;
}


void
MEP_TextBox_add_tag_on_focus(MEP_TextBox tb)
{
	((TextBox *)tb)->is_on_focus = 1;
}

void
MEP_TextBox_rm_tag_on_focus(MEP_TextBox tb)
{
	((TextBox *)tb)->is_on_focus = 0;
}

void
MEP_TextBox_set_geom(MEP_TextBox tb, Geom g)
{
	((TextBox *) tb)->g = g;
}

void
MEP_TextBox_set_geom_raw(MEP_TextBox tb, const int x, const int y, const int pw, const int ph)
{
	((TextBox *) tb)->g = geom_init(x, y, pw, ph);
}

void
MEP_TextBox_set_style(MEP_TextBox tb, Style s)
{
	((TextBox *) tb)->s = s;
}

void
MEP_TextBox_set_text(MEP_TextBox tb, char* text)
{
	MEPString tmp = ((TextBox*) tb)->text;
	MEPStr_set_text(tmp, text);
}

void
MEP_TextBox_append_text(MEP_TextBox tb, char* text)
{
    TextBox* tb_ptr = tb;
    MEPStr_append_text(tb_ptr->text, text);
}
