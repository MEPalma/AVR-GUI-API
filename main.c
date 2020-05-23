//
//  main.c
//  avr_gui_api
//
//  Created by MarcoEdoardoPalma on 26/04/2019.
//  Copyright © 2019 MarcoEdoardoPalma. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "os.h"
#include "Stage/Stage.h"
#include "TextBox/TextBox.h"

void
onClick (void* stage, void* label)
{
	MEPString str = MEPLabel_get_mepstring(label);
	MEPStr_append_text(str, "evvai");
	MEP_Stage_refresh_screen(stage);
}

MEP_TableView
getTable()
{
	MEP_TableView new_table = MEP_TableView_init(2, geom_init(0, 0, 0, 0));

	MEPLabel l = MEPLabel_init("LabelA", 0, 0, 0, 0);
	Style style = style_init();
	style.background = YELLOW;
	MEPLabel_set_style(l, style);

	MEPLabel l2 = MEPLabel_init("LabelB", 0, 0, 0, 0);
	Style style2 = style_init();
	style2.background = BLUE;
	MEPLabel_set_style(l2, style2);

	MEPLabel l3 = MEPLabel_init("LabelC", 0, 0, 0, 0);
	Style style3 = style_init();
	style3.background = MAGENTA;
	MEPLabel_set_style(l3, style3);

	MEP_TableView_Wrapper t_items[5];
	t_items[0] = MEP_TableView_new_wrapper(MEP_LABEL_ID, l);
	t_items[1] = MEP_TableView_new_wrapper(MEP_LABEL_ID, l2);
	t_items[2] = MEP_TableView_new_wrapper(MEP_LABEL_ID, l2);
	t_items[3] = MEP_TableView_new_wrapper(MEP_LABEL_ID, l3);
	t_items[4] = MEP_TableView_new_wrapper(MEP_LABEL_ID, l);

	MEP_TableView_add_all_arr(new_table, t_items, 5);

	return new_table;
}

void
table_in_a_table_demo()
{
	MEP_TableView new_table = MEP_TableView_init(3, geom_init(0, 0, display.width, display.height));

	MEP_TextBox t =  MEP_TextBox_init("textbo", 0, 0, 100, 100);
	Style stylet = style_init();
	stylet.background = YELLOW;
	MEP_TextBox_set_style(t, stylet);

	MEPLabel l = MEPLabel_init("Label1", 0, 0, 100, 100);
	Style style = style_init();
	style.background = CYAN;
	MEPLabel_set_style(l, style);
	MEPLabel_set_on_click_event(l, &onClick);

	MEPLabel l2 = MEPLabel_init("Label2", 0, 0, 100, 100);
	Style style2 = style_init();
	style2.background = RED;
	MEPLabel_set_style(l2, style2);

	MEPLabel l3 = MEPLabel_init("Label3", 0, 0, 100, 100);
	Style style3 = style_init();
	style3.background = GREEN;
	MEPLabel_set_style(l3, style3);

	MEP_TableView_Wrapper t_items[6];
	t_items[0] = MEP_TableView_new_wrapper(MEP_TEXTBOX_ID, t);
	t_items[1] = MEP_TableView_new_wrapper(MEP_LABEL_ID, l);
	t_items[2] = MEP_TableView_new_wrapper(MEP_LABEL_ID, l2);
	t_items[3] = MEP_TableView_new_wrapper(MEP_LABEL_ID, l3);
	t_items[4] = MEP_TableView_new_wrapper(MEP_LABEL_ID, l3);
	t_items[5] = MEP_TableView_new_wrapper(MEP_TABLEVIEW_ID, getTable());

	MEP_TableView_add_all_arr(new_table, t_items, 6);


	MEP_Stage_Wrapper items[1];
	items[0] = MEP_Stage_new_wrapper(MEP_TABLEVIEW_ID, new_table);

	MEP_Stage s = MEP_Stage_init();
	MEP_Stage_set_items(s, items, 1);

	MEP_Stage_start(s);
}


void
on_click_append_exclamation (void* stage, void* label)
{
	MEPString str = MEPLabel_get_mepstring(label);
	MEPStr_append_text(str, "!!!");
	MEP_Stage_refresh_screen(stage);
}

int main(void) {
	os_init();

	sei();
	
	/*
	 	THIS IS A DEMO
	 */

	LinkedList stage_items = llinit();

	MEPLabel title_label = MEPLabel_init("F1 2018 Standings", 0, 0, display.width, 20);
	Style tl_style = style_init();
	tl_style.background = RED;
	tl_style.foreground = WHITE;
	MEPLabel_set_style(title_label, tl_style);

	llappend(stage_items, MEP_Stage_new_wrapper(MEP_LABEL_ID, title_label));


	MEP_TableView center_table = MEP_TableView_init(2, geom_init(0, 20, display.width, display.height - 20));
	
	//constructors
	MEPLabel lc1 = MEPLabel_init("Mercedes Petronas AMG", 0, 0, 0, 0);
	MEPLabel_set_on_click_event(lc1, &on_click_append_exclamation);

	MEPLabel lc2 = MEPLabel_init("Scuderia Ferrari", 0, 0, 0, 0);
	MEPLabel_set_on_click_event(lc2, &on_click_append_exclamation);

	MEPLabel lc3 = MEPLabel_init("Red Bull", 0, 0, 0, 0);
	MEPLabel_set_on_click_event(lc3, &on_click_append_exclamation);

	MEPLabel lc4 = MEPLabel_init("Renault", 0, 0, 0, 0);
	MEPLabel_set_on_click_event(lc4, &on_click_append_exclamation);
	
	//add elements
	MEP_Stage_Wrapper center_table_items[14];
	center_table_items[0] = MEP_Stage_new_wrapper(MEP_TEXTBOX_ID, MEP_TextBox_init("Lewis Hamilton", 0, 0, 0, 0));
	center_table_items[1] = MEP_Stage_new_wrapper(MEP_LABEL_ID, lc1);
	center_table_items[2] = MEP_Stage_new_wrapper(MEP_TEXTBOX_ID, MEP_TextBox_init("Sebastian Vettel", 0, 0, 0, 0));
	center_table_items[3] = MEP_Stage_new_wrapper(MEP_LABEL_ID, lc2);
	center_table_items[4] = MEP_Stage_new_wrapper(MEP_TEXTBOX_ID, MEP_TextBox_init("Kimi Raikkonen", 0, 0, 0, 0));
	center_table_items[5] = MEP_Stage_new_wrapper(MEP_LABEL_ID, lc2);
	center_table_items[6] = MEP_Stage_new_wrapper(MEP_TEXTBOX_ID, MEP_TextBox_init("Max Verstappen", 0, 0, 0, 0));
	center_table_items[7] = MEP_Stage_new_wrapper(MEP_LABEL_ID, lc3);
	center_table_items[8] = MEP_Stage_new_wrapper(MEP_TEXTBOX_ID, MEP_TextBox_init("Valtteri Bottas", 0, 0, 0, 0));
	center_table_items[9] = MEP_Stage_new_wrapper(MEP_LABEL_ID, lc1);
	center_table_items[10] = MEP_Stage_new_wrapper(MEP_TEXTBOX_ID, MEP_TextBox_init("Daniel Ricciardo", 0, 0, 0, 0));
	center_table_items[11] = MEP_Stage_new_wrapper(MEP_LABEL_ID, lc1);
	center_table_items[12] = MEP_Stage_new_wrapper(MEP_TEXTBOX_ID, MEP_TextBox_init("Nico Hulkenberg", 0, 0, 0, 0));
	center_table_items[13] = MEP_Stage_new_wrapper(MEP_LABEL_ID, lc4);

	//set style to all items
	Style cell_style = style_init();
	cell_style.b.bc_bottom = RED;
	cell_style.b.bc_left = RED;
	cell_style.b.bc_top = RED;
	cell_style.b.bc_right = RED;
	cell_style.b.bw_bottom = 1;
	cell_style.b.bw_left = 1;
	cell_style.b.bw_top = 1;
	cell_style.b.bw_right = 1;
	for (int i = 0; i < 14; i += 2)
	{
		MEPLabel_set_style(MEP_Stage_Wrapper_get_item(center_table_items[i]), cell_style);
		MEP_TextBox_set_style(MEP_Stage_Wrapper_get_item(center_table_items[i + 1]), cell_style);
	}

	MEP_TableView_add_all_arr(center_table, center_table_items, 14);


	llappend(stage_items, MEP_Stage_new_wrapper(MEP_TABLEVIEW_ID, center_table));
	llappend(stage_items, MEP_Stage_new_wrapper(MEP_TABLEVIEW_ID, center_table));

	MEP_Stage s = MEP_Stage_init();

	MEP_Stage_set_items_list(s, stage_items);

	MEP_Stage_start(s);

	return 0;
}
