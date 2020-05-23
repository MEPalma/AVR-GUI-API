//
//  Keyboard.h
//  avr_gui_api
//
//  Created by MarcoEdoardoPalma on 04/05/2019.
//  Copyright © 2019 MarcoEdoardoPalma. All rights reserved.
//


#include "Keyboard.h"
#include "../TextBox/TextBox.h"
#include "../Stage/Stage.h"

typedef struct {
    MEP_TableView table_view;
} Keyb;

MEP_Keyb
MEP_Keyb_init()
{
    Keyb* keyb_ptr = (Keyb*) malloc(sizeof(Keyb));
    keyb_ptr->table_view = MEP_TableView_init(10, geom_init(0, 170, display.width, display.height - 170));

	Style key_style = style_init();
	key_style.background = 0x0810;
	key_style.foreground = WHITE;
	key_style.b.bc_top = WHITE;
	key_style.b.bc_right = WHITE;
	key_style.b.bc_bottom = WHITE;
	key_style.b.bc_left = WHITE;
	key_style.b.bw_top = 1;
	key_style.b.bw_right = 1;
	key_style.b.bw_bottom = 1;
	key_style.b.bw_left = 1;

	MEPLabel ln1 = MEPLabel_init("1", 0, 0, 0, 0);
	MEPLabel ln2 = MEPLabel_init("2", 0, 0, 0, 0);
	MEPLabel ln3 = MEPLabel_init("3", 0, 0, 0, 0);
	MEPLabel ln4 = MEPLabel_init("4", 0, 0, 0, 0);
	MEPLabel ln5 = MEPLabel_init("5", 0, 0, 0, 0);
	MEPLabel ln6 = MEPLabel_init("6", 0, 0, 0, 0);
	MEPLabel ln7 = MEPLabel_init("7", 0, 0, 0, 0);
	MEPLabel ln8 = MEPLabel_init("8", 0, 0, 0, 0);
	MEPLabel ln9 = MEPLabel_init("9", 0, 0, 0, 0);
	MEPLabel lclose = MEPLabel_init("x", 0, 0, 0, 0);

	MEPLabel lq = MEPLabel_init("Q", 0, 0, 0, 0);
	MEPLabel lw = MEPLabel_init("W", 0, 0, 0, 0);
	MEPLabel le = MEPLabel_init("E", 0, 0, 0, 0);
	MEPLabel lr = MEPLabel_init("R", 0, 0, 0, 0);
	MEPLabel lt = MEPLabel_init("T", 0, 0, 0, 0);
	MEPLabel ly = MEPLabel_init("Y", 0, 0, 0, 0);
	MEPLabel lu = MEPLabel_init("U", 0, 0, 0, 0);
	MEPLabel li = MEPLabel_init("I", 0, 0, 0, 0);
	MEPLabel lo = MEPLabel_init("O", 0, 0, 0, 0);
	MEPLabel lp = MEPLabel_init("P", 0, 0, 0, 0);

	MEPLabel la = MEPLabel_init("A", 0, 0, 0, 0);
	MEPLabel ls = MEPLabel_init("S", 0, 0, 0, 0);
	MEPLabel ld = MEPLabel_init("D", 0, 0, 0, 0);
	MEPLabel lf = MEPLabel_init("F", 0, 0, 0, 0);
	MEPLabel lg = MEPLabel_init("G", 0, 0, 0, 0);
	MEPLabel lh = MEPLabel_init("H", 0, 0, 0, 0);
	MEPLabel lj = MEPLabel_init("J", 0, 0, 0, 0);
	MEPLabel lk = MEPLabel_init("K", 0, 0, 0, 0);
	MEPLabel ll = MEPLabel_init("L", 0, 0, 0, 0);
	MEPLabel lz = MEPLabel_init("Z", 0, 0, 0, 0);

	MEPLabel lx = MEPLabel_init("X", 0, 0, 0, 0);
	MEPLabel lc = MEPLabel_init("C", 0, 0, 0, 0);
	MEPLabel lv = MEPLabel_init("V", 0, 0, 0, 0);
	MEPLabel lb = MEPLabel_init("B", 0, 0, 0, 0);
	MEPLabel ln = MEPLabel_init("N", 0, 0, 0, 0);
	MEPLabel lm = MEPLabel_init("M", 0, 0, 0, 0);

	MEPLabel lspace = MEPLabel_init("_", 0, 0, 0, 0);
	MEPLabel ldot = MEPLabel_init(".", 0, 0, 0, 0);
	MEPLabel lcomma = MEPLabel_init(",", 0, 0, 0, 0);
	MEPLabel ldelete = MEPLabel_init("<", 0, 0, 0, 0);

	MEP_TableView_Wrapper raw_0[10];
	raw_0[0] = MEP_TableView_new_wrapper(MEP_LABEL_ID, ln1); 
	raw_0[1] = MEP_TableView_new_wrapper(MEP_LABEL_ID, ln2); 
	raw_0[2] = MEP_TableView_new_wrapper(MEP_LABEL_ID, ln3); 
	raw_0[3] = MEP_TableView_new_wrapper(MEP_LABEL_ID, ln4); 
	raw_0[4] = MEP_TableView_new_wrapper(MEP_LABEL_ID, ln5); 
	raw_0[5] = MEP_TableView_new_wrapper(MEP_LABEL_ID, ln6); 
	raw_0[6] = MEP_TableView_new_wrapper(MEP_LABEL_ID, ln7); 
	raw_0[7] = MEP_TableView_new_wrapper(MEP_LABEL_ID, ln8); 
	raw_0[8] = MEP_TableView_new_wrapper(MEP_LABEL_ID, ln9); 
	raw_0[9] = MEP_TableView_new_wrapper(MEP_LABEL_ID, lclose);
	for(int i = 0; i < 10; ++i)
		MEPLabel_set_style(MEP_TableView_wrapper_item(raw_0[i]), key_style);

	MEP_TableView_Wrapper raw_1[10];
	raw_1[0] = MEP_TableView_new_wrapper(MEP_LABEL_ID, lq); 
	raw_1[1] = MEP_TableView_new_wrapper(MEP_LABEL_ID, lw); 
	raw_1[2] = MEP_TableView_new_wrapper(MEP_LABEL_ID, le); 
	raw_1[3] = MEP_TableView_new_wrapper(MEP_LABEL_ID, lr); 
	raw_1[4] = MEP_TableView_new_wrapper(MEP_LABEL_ID, lt); 
	raw_1[5] = MEP_TableView_new_wrapper(MEP_LABEL_ID, ly); 
	raw_1[6] = MEP_TableView_new_wrapper(MEP_LABEL_ID, lu); 
	raw_1[7] = MEP_TableView_new_wrapper(MEP_LABEL_ID, li); 
	raw_1[8] = MEP_TableView_new_wrapper(MEP_LABEL_ID, lo); 
	raw_1[9] = MEP_TableView_new_wrapper(MEP_LABEL_ID, lp);
	for(int i = 0; i < 10; ++i)
		MEPLabel_set_style(MEP_TableView_wrapper_item(raw_1[i]), key_style);

	MEP_TableView_Wrapper raw_2[10];
	raw_2[0] = MEP_TableView_new_wrapper(MEP_LABEL_ID, la); 
	raw_2[1] = MEP_TableView_new_wrapper(MEP_LABEL_ID, ls); 
	raw_2[2] = MEP_TableView_new_wrapper(MEP_LABEL_ID, ld); 
	raw_2[3] = MEP_TableView_new_wrapper(MEP_LABEL_ID, lf); 
	raw_2[4] = MEP_TableView_new_wrapper(MEP_LABEL_ID, lg); 
	raw_2[5] = MEP_TableView_new_wrapper(MEP_LABEL_ID, lh); 
	raw_2[6] = MEP_TableView_new_wrapper(MEP_LABEL_ID, lj); 
	raw_2[7] = MEP_TableView_new_wrapper(MEP_LABEL_ID, lk); 
	raw_2[8] = MEP_TableView_new_wrapper(MEP_LABEL_ID, ll);
	raw_2[9] = MEP_TableView_new_wrapper(MEP_LABEL_ID, lz);
	for(int i = 0; i < 10; ++i)
		MEPLabel_set_style(MEP_TableView_wrapper_item(raw_2[i]), key_style);

	MEP_TableView_Wrapper raw_3[10];
	raw_3[0] = MEP_TableView_new_wrapper(MEP_LABEL_ID, lx); 
	raw_3[1] = MEP_TableView_new_wrapper(MEP_LABEL_ID, lc); 
	raw_3[2] = MEP_TableView_new_wrapper(MEP_LABEL_ID, lv); 
	raw_3[3] = MEP_TableView_new_wrapper(MEP_LABEL_ID, lb); 
	raw_3[4] = MEP_TableView_new_wrapper(MEP_LABEL_ID, ln); 
	raw_3[5] = MEP_TableView_new_wrapper(MEP_LABEL_ID, lm);
	raw_3[6] = MEP_TableView_new_wrapper(MEP_LABEL_ID, lspace);
	raw_3[7] = MEP_TableView_new_wrapper(MEP_LABEL_ID, ldot);
	raw_3[8] = MEP_TableView_new_wrapper(MEP_LABEL_ID, lcomma);
	raw_3[9] = MEP_TableView_new_wrapper(MEP_LABEL_ID, ldelete);
	for(int i = 0; i < 10; ++i)
		MEPLabel_set_style(MEP_TableView_wrapper_item(raw_3[i]), key_style);

	Style specia_key_sty = style_init();
	specia_key_sty.background = BLUE;
	specia_key_sty.foreground = WHITE;
	specia_key_sty.b = key_style.b;
	MEPLabel_set_style(lspace, specia_key_sty);
	MEPLabel_set_style(ldot, specia_key_sty);
	MEPLabel_set_style(lcomma, specia_key_sty);
	MEPLabel_set_style(ldelete, specia_key_sty);

	Style close_key_style = style_init();
	close_key_style.background = RED;
	close_key_style.foreground = WHITE;
	close_key_style.b = key_style.b;
	MEPLabel_set_style(lclose, close_key_style);

	MEP_TableView_add_all_arr(keyb_ptr->table_view, raw_0, 10);
	MEP_TableView_add_all_arr(keyb_ptr->table_view, raw_1, 10);
	MEP_TableView_add_all_arr(keyb_ptr->table_view, raw_2, 10);
	MEP_TableView_add_all_arr(keyb_ptr->table_view, raw_3, 10);

    return keyb_ptr;
}

MEP_TableView
MEP_Keyb_get_container(MEP_Keyb key)
{
    return ((Keyb*)key) ->table_view;
}

void
MEP_Keyb_click_on_keyboard_performed(MEP_Keyb keyb, MEP_Stage stage, MEP_Stage_Wrapper target_append_text_stage_wrapper)
{
	Keyb* k = keyb;

	LinkedListIterator it = ll_iterator_get_iterator(MEP_TableView_get_items(k->table_view));

	while (ll_iterator_finished(it))
	{
		MEP_TableView_Wrapper w = ll_iterator_this_value(it);

		int8_t id = MEP_TableView_wrapper_id(w);
		if (id == MEP_LABEL_ID)
		{
			MEPLabel l = MEP_TableView_wrapper_item(w);
			if(MEPLable_is_selected(l, MEP_Stage_get_cursor_x(stage), MEP_Stage_get_cursor_y(stage)))
			{
				int8_t target_w_id = MEP_Stage_Wrapper_get_id(target_append_text_stage_wrapper);
				if (target_w_id == MEP_TEXTBOX_ID)
				{
					if (MEPStr_equals(MEPLabel_get_text(l), "x"))
					{
						MEP_Stage_invoke_on_keyb_about_to_close_event(stage);
						MEP_Stage_set_keyb_hidden(stage);
						MEP_Stage_refresh_screen(stage);
						return;
					}
					else if (MEPStr_equals(MEPLabel_get_text(l), "_"))
					{
						MEP_TextBox target_l = MEP_Stage_Wrapper_get_item(target_append_text_stage_wrapper);
						MEPString target_l_text = MEP_TextBox_get_mepstring(target_l);

						MEPStr_append_text(target_l_text, " ");

						MEP_TextBox_invoke_after_keyb_input(stage, target_l);
						MEP_Stage_refresh_screen(stage);
						return;
					}
					else if (MEPStr_equals(MEPLabel_get_text(l), "<"))
					{
						MEP_TextBox target_l = MEP_Stage_Wrapper_get_item(target_append_text_stage_wrapper);

						MEPStr_chop_last_char(MEPLabel_get_mepstring(target_l));
						MEP_TextBox_invoke_after_keyb_input(stage, target_l);
						MEP_Stage_refresh_screen(stage);
						return;
					}
					else 
					{
						MEP_TextBox target_l = MEP_Stage_Wrapper_get_item(target_append_text_stage_wrapper);
						MEPString target_l_text = MEP_TextBox_get_mepstring(target_l);

						MEPStr_append_text(target_l_text, MEPLabel_get_text(l));
						MEP_TextBox_invoke_after_keyb_input(stage, target_l);
						MEP_Stage_refresh_screen(stage);
						return;
					}
				}
			}
		}

		ll_iterator_update_next(&it);
	}
}

int
MEP_Keyb_is_selected(MEP_Keyb keyb, const int x, const int y)
{
	Keyb* kb_ptr = keyb;
	Geom geom = MEP_TableView_geom(kb_ptr->table_view);
	return ((x >= geom.x) && (x <= (geom.x + geom.preferred_width)) &&
			(y >= geom.y) && (y <= geom.y + geom.preferred_height));
}