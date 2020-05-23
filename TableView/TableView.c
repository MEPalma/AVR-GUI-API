//
//  TableView.c
//  avr_gui_api
//
//  Created by MarcoEdoardoPalma on 29/04/2019.
//  Copyright © 2019 MarcoEdoardoPalma. All rights reserved.
//

#include "TableView.h"

typedef struct StructWrapper {
	int id;
	void* item;
} TVWrapper;

typedef struct StructTable {
	Geom geom;
	Style style;
	
	int columns;
	
	LinkedList items;
} TableView;

MEP_TableView
MEP_TableView_init(const int columns, const Geom geom)
{
	TableView* table = (TableView*) malloc(sizeof(TableView));
	
	table->style = style_init();
	table->geom = geom;
	
	table->columns = columns;
	
	table->items = llinit();
	
	return table;
}


int
MEP_TableView_get_columns(MEP_TableView table)
{
	return ((TableView*) table)->columns;
}

int
MEP_TableView_get_row_height(MEP_TableView table)
{
	TableView* t = table;
    return t->geom.preferred_height / (1 + ((llsize(t->items) - 1) / t->columns));
}

int
MEP_TableView_get_column_width(MEP_TableView table)
{
	TableView* t = table;
	return (t->geom.preferred_width / t->columns);
}

Geom
MEP_TableView_geom(MEP_TableView table)
{
	return ((TableView*) table)->geom;
}

Style
MEP_TableView_style(MEP_TableView table)
{
	return ((TableView*) table)->style;
}

LinkedList
MEP_TableView_get_items(MEP_TableView table)
{
	return ((TableView*)table)->items;
}

MEP_TableView_Wrapper
MEP_TableView_new_wrapper (const int id, void* item)
{
	TVWrapper* w = (TVWrapper*) malloc(sizeof(TVWrapper));
	w->id = id;
	w->item = item;
	
	printf("new wrapper at %p\n", w);
	return w;
}

int
MEP_TableView_wrapper_id(MEP_TableView_Wrapper w)
{
	return ((TVWrapper*)w)->id;
}

void*
MEP_TableView_wrapper_item(MEP_TableView_Wrapper w)
{
	return ((TVWrapper*)w)->item;
}

void
MEP_TableView_add_all_arr(MEP_TableView table, MEP_TableView_Wrapper items[], int arr_length)
{
	TableView* tableptr = table;

	for (int i = 0; i < arr_length; ++i)
		llappend(tableptr->items, items[i]);
}


void
MEP_TableView_set_items(MEP_TableView table, LinkedList items)
{
	TableView* tableptr = table;
	free(tableptr->items);
	tableptr->items = items;
}

void
MEP_TableView_set_geom_raw(MEP_TableView table, const int x, const int y, const int pw, const int ph)
{
	((TableView*) table)->geom = geom_init(x, y, pw, ph);
}

void
MEP_TableView_purge_all_items(MEP_TableView table)
{
	llpurge(((TableView*) table)->items);
}

int
MEP_TableView_contains_pointer(MEP_TableView tv, const int x, const int y)
{
	TableView* tv_ptr = tv;
	return ((x >= tv_ptr->geom.x) && (x <= (tv_ptr->geom.x + tv_ptr->geom.preferred_width)) &&
			(y >= tv_ptr->geom.y) && (y <= tv_ptr->geom.y + tv_ptr->geom.preferred_height));
}

void
MEP_TableView_debug_printf(MEP_TableView table)
{
	printf("//TABLE VIEW DEBUGGING---\n");
	
	TableView* tableptr = table;
	
	LinkedListIterator it = ll_iterator_get_iterator(tableptr->items);
	while(ll_iterator_finished(it)) {
		TVWrapper* w = ll_iterator_this_value(it);
		
		if (w->id == MEP_LABEL_ID) {
			MEPLabel_debug_printf(((MEPLabel*) w->item));
		}
		//TODO add other cases
		
		ll_iterator_update_next(&it);
	}
	
	printf("\nTABLE VIEW DEBUGGING DONE");
}
