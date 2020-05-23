//
//  String.h
//  avr_gui_api
//
//  Created by MarcoEdoardoPalma on 26/04/2019.
//  Copyright © 2019 MarcoEdoardoPalma. All rights reserved.
//

#ifndef String_h
#define String_h

#include <stdlib.h>

#define MEPString void*

MEPString
MEPStr_init(char* lit);

int
MEPStr_length(MEPString mepstr);

char*
MEPStr_get_lit(MEPString mepstr);

void
MEPStr_set_text(MEPString mepstr, char* text);

void
MEPStr_append_text(MEPString mepstr, char* text);

int
MEPStr_equals(char* x, char* y);

void
MEPStr_chop_last_char(MEPString mepstring);

#endif /* String_h */
