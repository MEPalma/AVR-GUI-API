//
//  Stage.h
//  avr_gui_api
//
//  Created by MarcoEdoardoPalma on 26/04/2019.
//  Copyright © 2019 MarcoEdoardoPalma. All rights reserved.
//

#ifndef Stage_h
#define Stage_h

#include <stdio.h>

#include "../lcd/lcd.h"
#include "../ruota/ruota.h"
#include "../TableView/TableView.h"
#include "../LinkedList/LinkedList.h"
#include "../Keyboard/Keyboard.h"
#include "../String/String.h"
#include "../Keyboard/Keyboard.h"

#define MEP_Stage void* 
#define MEP_Stage_Wrapper void*

#define MEP_LABEL_ID 0
#define MEP_TABLEVIEW_ID 1
#define MEP_TEXTBOX_ID 2


MEP_Stage
MEP_Stage_init(void);

void
MEP_Stage_set_items(MEP_Stage stage, MEP_Stage_Wrapper items[], const int size);

void
MEP_Stage_set_items_list(MEP_Stage stage, LinkedList items);

MEP_Stage_Wrapper
MEP_Stage_new_wrapper (const int id, void* item);

LinkedList
MEP_Stage_get_items(MEP_Stage stage);

int
MEP_Stage_Wrapper_get_id(MEP_Stage_Wrapper w);

void*
MEP_Stage_Wrapper_get_item(MEP_Stage_Wrapper w);

void
MEP_Stage_set_cursor_location(MEP_Stage stage, const int x, const int y);


int
MEP_Stage_get_cursor_x(MEP_Stage stage);

int
MEP_Stage_get_cursor_y(MEP_Stage stage);

void
MEP_Stage_refresh_screen(MEP_Stage stage);

int
MEP_Stage_keyb_visible(MEP_Stage stage);

MEP_Keyb
MEP_Stage_get_keyb(MEP_Stage stage);

void
MEP_Stage_set_on_keyb_about_to_open_event(MEP_Stage stage, void (*on_keyb_about_to_open)(void*));

void
MEP_Stage_invoke_on_keyb_about_to_open_event(MEP_Stage stage);

void
MEP_Stage_set_on_keyb_about_to_close_event(MEP_Stage stage, void (*on_keyb_about_to_close)(void*));

void
MEP_Stage_invoke_on_keyb_about_to_close_event(MEP_Stage stage);

void
MEP_Stage_set_keyb_visible(MEP_Stage stage);

void
MEP_Stage_set_keyb_hidden(MEP_Stage stage);

void
MEP_Stage_set_selected_item(MEP_Stage stage, MEP_Stage_Wrapper w);

MEP_Stage_Wrapper
MEP_Stage_get_selected_item(MEP_Stage stage);

void
MEP_Stage_stop(MEP_Stage stage);

void
MEP_Stage_start(MEP_Stage stage);

void
MEP_Stage_update_item_on_focus(MEP_Stage stage);

#endif /* Stage_h */
