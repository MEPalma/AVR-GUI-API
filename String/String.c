//
//  String.c
//  avr_gui_api
//
//  Created by MarcoEdoardoPalma on 26/04/2019.
//  Copyright © 2019 MarcoEdoardoPalma. All rights reserved.
//

#include "String.h"

typedef struct StringStruct {
	int size;
	char* arr;
} String;

int
get_lit_length(char* lit)
{
	int i = -1;
	while (*(lit + (++i)) != '\0')
		;

	return i;
}

void
cpymem(char* dest, char* src, int size) //unsafe!
{
	for (int i = 0; i < size; ++i)
		*(dest + i) = *(src + i);

	*(dest + size) = '\0';
}

MEPString
MEPStr_init(char* lit)
{
	String* tmp = (String*) calloc(1, sizeof(String));
	
	tmp->size = get_lit_length(lit);
	
	tmp->arr = (char*) calloc((tmp->size + 1), sizeof(char));
	cpymem(tmp->arr, lit, tmp->size);
	
	return tmp;
}

int
MEPStr_length(MEPString mepstr)
{
	return ((String*) mepstr)->size;
}


char*
MEPStr_get_lit(MEPString mepstr)
{
	return ((String*) mepstr)->arr;
}

void
MEPStr_set_text(MEPString mepstr, char* text)
{
	String* tmp = mepstr;
	tmp->size = get_lit_length(text);
	free(tmp->arr);
	tmp->arr = (char*) malloc(sizeof(char) * tmp->size);
	cpymem(tmp->arr, text, tmp->size);
}

void
MEPStr_append_text(MEPString mepstr, char* text)
{
	String* str = mepstr;

	int new_text_size = get_lit_length(text);
	int new_size = str->size + new_text_size;

	str->arr = (char*) realloc(str->arr, (sizeof(char) * (new_size + 1)));

	cpymem((str->arr + str->size), text, new_text_size);

	str->size = new_size;
}

int
MEPStr_equals(char* x, char* y)
{
	if (get_lit_length(x) != get_lit_length(y)) return 0;

	int i = 0;
	while ((*(x + i) != '\0') && *(y + i) != '\0') {
		if (*(x + i) != *(y + i)) return 0;
		++i;
	}
	return 1;
}

void
MEPStr_chop_last_char(MEPString mepstring)
{
	String* str = mepstring;
	str->arr = (char*) realloc(str->arr, (sizeof(char) * (str->size - 1)));
	str->arr[str->size - 1] = '\0';
	str->size -= 1;
}
