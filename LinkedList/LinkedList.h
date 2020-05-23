#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>

#define LinkedList void*
#define LinkedListIterator void*

#define NO_DATA NULL

void* llinit(void);

void llappend(void* list_ptr, void* new_data);

void llpop(void* list_ptr);
void llpurge(void* list_ptr);

void* llget_data(void* list_ptr, int index);
void llset_data(void* list_ptr, int index, void* new_data);
int llsize(void* list_ptr);

LinkedListIterator ll_iterator_get_iterator(LinkedList list_ptr);
void* ll_iterator_this_value(LinkedListIterator lli_ptr);
int ll_iterator_finished(LinkedListIterator lli_ptr);
void ll_iterator_update_next(LinkedListIterator* lli_ptr);

#endif /*LINKEDLIST_H*/
