//
//  TableView.h
//  avr_gui_api
//
//  Created by MarcoEdoardoPalma on 29/04/2019.
//  Copyright © 2019 MarcoEdoardoPalma. All rights reserved.
//

#ifndef TableView_h
#define TableView_h

#include <stdio.h>
#include <stdlib.h>
#include "../Geom/Geom.h"
#include "../Style/Style.h"
#include "../Label/Label.h"
#include "../LinkedList/LinkedList.h"

#define MEP_TableView void*

#define MEP_TableView_Wrapper void*

#define MEP_LABEL_ID 0
#define MEP_TABLEVIEW_ID 1
#define MEP_TEXTBOX_ID 2


MEP_TableView
MEP_TableView_init(const int columns, const Geom geom);

int
MEP_TableView_get_columns(MEP_TableView table);

int
MEP_TableView_get_row_height(MEP_TableView table);

int
MEP_TableView_get_column_width(MEP_TableView table);

Geom
MEP_TableView_geom(MEP_TableView table);

Style
MEP_TableView_style(MEP_TableView table);

LinkedList
MEP_TableView_get_items(MEP_TableView table);


MEP_TableView_Wrapper
MEP_TableView_new_wrapper (const int id, void* item);

int
MEP_TableView_wrapper_id(MEP_TableView_Wrapper w);

void*
MEP_TableView_wrapper_item(MEP_TableView_Wrapper w);

void
MEP_TableView_add_all_arr(MEP_TableView table, MEP_TableView_Wrapper items[], int arr_length);

void
MEP_TableView_set_items(MEP_TableView table, LinkedList items);

void
MEP_TableView_set_geom_raw(MEP_TableView table, const int x, const int y, const int pw, const int ph);

void
MEP_TableView_purge_all_items(MEP_TableView table);


void
MEP_TableView_debug_printf(MEP_TableView table);

int
MEP_TableView_contains_pointer(MEP_TableView tv, const int x, const int y);

#endif /* TableView_h */
