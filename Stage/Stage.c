//
//  Stage.c
//  avr_gui_api
//
//  Created by MarcoEdoardoPalma on 26/04/2019.
//  Copyright © 2019 MarcoEdoardoPalma. All rights reserved.
//

#include "Stage.h"
#include "../lcd/lcd.h"
#include "../TextBox/TextBox.h"
#include <util/delay.h>

typedef struct StructWrapper {
	int id;
	void* item;
} Wrapper;

typedef struct StructStage 
{
    int cursor_x;
    int cursor_y;

    MEP_Keyb mep_keyb;

    int keyboardVisible;

    void (*refresh_fun_ptr)(MEP_Stage stage);

    LinkedList items;

    Wrapper* selected_item;

    int active_refresh;

    void (*on_keyb_about_to_open)(void* stage);
    void (*on_keyb_about_to_close)(void* stage);
} Stage;

MEP_Stage
MEP_Stage_init()
{
    Stage* stage = (Stage*) calloc(1, sizeof(Stage));

    stage->items = llinit();
    stage->cursor_x = display.width / 2;
    stage->cursor_y = display.height / 2;
    stage->mep_keyb = MEP_Keyb_init();
    stage->keyboardVisible = 0;
    stage->selected_item = (Wrapper*) calloc(1, sizeof(Wrapper));
    stage->active_refresh = 0;

    return stage;
}


MEP_Stage_Wrapper
MEP_Stage_new_wrapper (const int id, void* item)
{
	Wrapper* w = (Wrapper*) malloc(sizeof(Wrapper));
	w->id = id;
	w->item = item;
	
	printf("new wrapper at %p\n", w);
	return w;
}

void
MEP_Stage_set_on_keyb_about_to_open_event(MEP_Stage stage, void (*on_keyb_about_to_open)(void*))
{
	((Stage*) stage)->on_keyb_about_to_open = on_keyb_about_to_open;
}

void
MEP_Stage_invoke_on_keyb_about_to_open_event(MEP_Stage stage)
{
    if (((Stage*) stage)->on_keyb_about_to_open != NULL)
		(*((Stage*) stage)->on_keyb_about_to_open)(stage);
}


void
MEP_Stage_set_on_keyb_about_to_close_event(MEP_Stage stage, void (*on_keyb_about_to_close)(void*))
{
	((Stage*) stage)->on_keyb_about_to_close = on_keyb_about_to_close;
}

void
MEP_Stage_invoke_on_keyb_about_to_close_event(MEP_Stage stage)
{
    if (((Stage*) stage)->on_keyb_about_to_close != NULL)
		(*((Stage*) stage)->on_keyb_about_to_close)(stage);
}

void
MEP_Stage_set_items(MEP_Stage stage, MEP_Stage_Wrapper items[], const int size)
{
    Stage* stage_ptr = stage;

    for (int i = 0; i < size; ++i) {
        llappend(stage_ptr->items, items[i]);
    }
}

void
MEP_Stage_set_items_list(MEP_Stage stage, LinkedList items)
{
    Stage* s = stage;
    free(s->items);
    s->items = items;
}

LinkedList
MEP_Stage_get_items(MEP_Stage stage)
{
    return ((Stage*) stage)->items;
}

int
MEP_Stage_Wrapper_get_id(MEP_Stage_Wrapper w)
{
    return ((Wrapper*)w)->id;
}

void*
MEP_Stage_Wrapper_get_item(MEP_Stage_Wrapper w)
{
    return ((Wrapper*)w)->item;
}

void
MEP_Stage_set_cursor_location(MEP_Stage stage, const int x, const int y)
{
    Stage* stage_ptr = stage;
    stage_ptr->cursor_x = x;
    stage_ptr->cursor_y = y;

    display_MEP_Stage(stage);
}

int
MEP_Stage_get_cursor_x(MEP_Stage stage)
{
    return ((Stage*) stage)->cursor_x;
}

int
MEP_Stage_get_cursor_y(MEP_Stage stage)
{
    return ((Stage*) stage)->cursor_y;
}

void
MEP_Stage_refresh_screen(MEP_Stage stage)
{
    display_MEP_Stage(stage);
}

int
MEP_Stage_keyb_visible(MEP_Stage stage)
{
    return ((Stage*) stage)->keyboardVisible;
}

MEP_Keyb
MEP_Stage_get_keyb(MEP_Stage stage)
{
    return ((Stage*) stage)->mep_keyb;
}

void
MEP_Stage_set_keyb_visible(MEP_Stage stage)
{
    ((Stage*) stage)->keyboardVisible = 1;
}

void
MEP_Stage_set_keyb_hidden(MEP_Stage stage)
{
    ((Stage*) stage)->keyboardVisible = 0;
}

void
MEP_Stage_set_selected_item(MEP_Stage stage, MEP_Stage_Wrapper w)
{
    ((Stage*) stage)->selected_item = w;
}

MEP_Stage_Wrapper
MEP_Stage_get_selected_item(MEP_Stage stage)
{
    return ((Stage*) stage)->selected_item;
}

void
MEP_Stage_stop(MEP_Stage stage)
{
    ((Stage*) stage)->active_refresh = 0;
}

void
MEP_Stage_start(MEP_Stage stage)
{
    Stage* stage_ptr = stage;
    stage_ptr->active_refresh = 1;

    clear_screen();
    MEP_Stage_refresh_screen(stage);
    while (stage_ptr->active_refresh)
	{
        _delay_ms(20);
        if(!(PINC & _BV(PC2)))//North
        {
            MEP_Stage_set_cursor_location(stage, stage_ptr->cursor_x, stage_ptr->cursor_y - 7);
            MEP_Stage_refresh_screen(stage);
        }
        else if(!(PINC & _BV(PC3)))//East
        {
            MEP_Stage_set_cursor_location(stage, stage_ptr->cursor_x + 7, stage_ptr->cursor_y);
            MEP_Stage_refresh_screen(stage);
        }
        else if(!(PINC & _BV(PC4)))//South
        {
            MEP_Stage_set_cursor_location(stage, stage_ptr->cursor_x, stage_ptr->cursor_y + 7);
            MEP_Stage_refresh_screen(stage);
        }
        else if(!(PINC & _BV(PC5)))//West
        {
            MEP_Stage_set_cursor_location(stage, stage_ptr->cursor_x - 7, stage_ptr->cursor_y);
            MEP_Stage_refresh_screen(stage);
        }
        else if (!(PINE & _BV(PE7)))//Center
        {

            if (MEP_Stage_keyb_visible(stage) && MEP_Keyb_is_selected(MEP_Stage_get_keyb(stage), stage_ptr->cursor_x, stage_ptr->cursor_y) )
            {
                MEP_Keyb_click_on_keyboard_performed(MEP_Stage_get_keyb(stage), stage, MEP_Stage_get_selected_item(stage));
            }
            else
            {
                MEP_Stage_update_item_on_focus(stage);

                MEP_Stage_Wrapper w = MEP_Stage_get_selected_item(stage);
                if (w != NULL) 
                {
                    int8_t id = MEP_Stage_Wrapper_get_id(w);
                    if (id == MEP_LABEL_ID) 
                    {
                        MEPLabel l_selected = MEP_Stage_Wrapper_get_item(w);
                        if (l_selected != NULL)
                            MEPLabel_call_on_click_event(l_selected, stage);
                    } else if (id == MEP_TEXTBOX_ID)
                    {
                        MEP_Stage_invoke_on_keyb_about_to_open_event(stage);
                        MEP_Stage_set_keyb_visible(stage);
                        MEP_Stage_refresh_screen(stage);
                    }
                }
            }
        }
	}
}

void
MEP_Stage_set_selected_MEPLabel(MEP_Stage stage, MEPLabel label)
{
    MEPLabel_add_tag_on_focus(label);
    MEP_Stage_set_selected_item(stage, MEP_Stage_new_wrapper(MEP_LABEL_ID, label));

    display_string(MEPLabel_get_text(label));
}

int
MEP_Stage_update_item_on_focus_dive_tableview(MEP_Stage stage, MEP_TableView tv)
{
    if (MEP_TableView_contains_pointer(tv, MEP_Stage_get_cursor_x(stage), MEP_Stage_get_cursor_y(stage)))
    {
        LinkedListIterator it = ll_iterator_get_iterator(MEP_TableView_get_items(tv));
        while(ll_iterator_finished(it))
        {
            MEP_TableView_Wrapper w = ll_iterator_this_value(it);

            int8_t id = MEP_TableView_wrapper_id(w);
            if (id == MEP_LABEL_ID) 
            {
                MEPLabel l = MEP_TableView_wrapper_item(w);
                if (MEPLable_is_selected(l, MEP_Stage_get_cursor_x(stage), MEP_Stage_get_cursor_y(stage)))
                {
                    MEP_Stage_set_selected_item(stage, MEP_Stage_new_wrapper(MEP_LABEL_ID, l));
                    MEP_Stage_set_keyb_hidden(stage);
                    return 1;
                }
            }
            else if (id == MEP_TABLEVIEW_ID) 
            {
                if (MEP_Stage_update_item_on_focus_dive_tableview(stage, MEP_TableView_wrapper_item(w))) return 1;
            }
            else if (id == MEP_TEXTBOX_ID)
            {
                MEP_TextBox tb_ptr = MEP_Stage_Wrapper_get_item(w);
                if (MEP_TextBox_is_selected(tb_ptr, MEP_Stage_get_cursor_x(stage), MEP_Stage_get_cursor_y(stage)))
                {
                    MEP_Stage_set_selected_item(stage, MEP_Stage_new_wrapper(MEP_TEXTBOX_ID, tb_ptr));
                    return 1;
                }
            }

            ll_iterator_update_next(&it);
        }

    }
    return 0;
}

void
MEP_Stage_update_item_on_focus(MEP_Stage stage)
{
    Stage* stage_ptr = stage;

    LinkedListIterator it = ll_iterator_get_iterator(stage_ptr->items);

    int finished = 0;
    while(ll_iterator_finished(it) && !finished)
    {
        MEP_Stage_Wrapper w = ll_iterator_this_value(it);

        int id = MEP_Stage_Wrapper_get_id(w);

        if (id == MEP_LABEL_ID) 
        {
            MEPLabel l = MEP_Stage_Wrapper_get_item(w);
            if (MEPLable_is_selected(l, stage_ptr->cursor_x, stage_ptr->cursor_y))
            {
                MEP_Stage_set_keyb_hidden(stage);
                MEP_Stage_refresh_screen(stage);
                finished = 1;
            }
        }
        if (id == MEP_TABLEVIEW_ID)
        {
            MEP_TableView t = MEP_Stage_Wrapper_get_item(w);
            finished = MEP_Stage_update_item_on_focus_dive_tableview(stage, t);
        }
        else if (id == MEP_TEXTBOX_ID)
        {
            MEP_TextBox tb_ptr = MEP_Stage_Wrapper_get_item(w);
            if (MEP_TextBox_is_selected(tb_ptr, stage_ptr->cursor_x, stage_ptr->cursor_y))
            {
                MEP_Stage_set_selected_item(stage, MEP_Stage_new_wrapper(MEP_TEXTBOX_ID, tb_ptr));
                MEP_Stage_set_keyb_visible(stage);
                MEP_Stage_refresh_screen(stage);
                finished = 1;
            }
        }

        ll_iterator_update_next(&it);
    }

}

