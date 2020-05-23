//
//  Keyboard.h
//  avr_gui_api
//
//  Created by MarcoEdoardoPalma on 04/05/2019.
//  Copyright © 2019 MarcoEdoardoPalma. All rights reserved.
//

#include "../Stage/Stage.h"
// #include "../TableView/TableView.h"
// #include "../Label/Label.h"

#ifndef Keyboard_h
#define Keyboard_h

#define MEP_Keyb void*

MEP_Keyb
MEP_Keyb_init(void);

MEP_TableView
MEP_Keyb_get_container(MEP_Keyb key);

void
MEP_Keyb_click_on_keyboard_performed(MEP_Keyb keyb, void* stage, void* target_append_text_stage_wrapper);

int
MEP_Keyb_is_selected(MEP_Keyb keyb, const int x, const int y);

#endif /* Keyboard_h */