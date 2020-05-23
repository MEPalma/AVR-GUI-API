#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

typedef struct node
{
	void* data;
	struct node* next;
} Node;

typedef struct llist
{
	Node* root;
	Node* tail;
} LList;

void* init_node(void)
{
	Node* node = (Node*) calloc(1, sizeof(Node));
	if (node == NULL) return init_node();
	
	return node;
}

void* llinit(void)
{
	LList* list = (LList*) calloc(1, sizeof(LList));
	if (list == NULL) return llinit();
	list->tail = init_node();
	list->root = list->tail;
	return list;
}

void* get_snd_last(void* node_ptr)
{
	Node* node = node_ptr;
	if(node->next != NULL)
		if(node->next->next != NULL)
			return get_snd_last(node->next);
		else return node;
	else return NULL;
}

void* get_last(void* node_ptr)
{
	Node* node = node_ptr;
	if (!node->next) return node;
	return get_last(node->next);
}

void llappend_from_root(void* list_ptr, void* new_data)
{
	Node* last = get_last(((LList*)list_ptr)->root);
	Node* new_node = init_node();

	last->next = new_node;
	new_node->data = new_data;
}

void llappend(void* list_ptr, void* new_data)
{
	LList* list = list_ptr;
	
	Node* last = list->tail;
	Node* new_node = init_node();
	last->next = new_node;
	list->tail = new_node;
	
	new_node->data = new_data;
}

void llpop(void* list_ptr)
{
	LList* list = list_ptr;
	Node* snd_last_ptr = get_snd_last(list->root);
	if (snd_last_ptr == NULL) return;
	Node* last_ptr = snd_last_ptr->next;

	snd_last_ptr->next = NULL;
	free(last_ptr);
}

void llpurge(void* list_ptr)
{
	LList* list = list_ptr;

	if (list->root->next == NULL) return;

	Node* f_ptr = list->root->next;
	Node* s_ptr = f_ptr->next;
	
	while (s_ptr != NULL)
	{
		free(f_ptr);
		f_ptr = s_ptr;
		s_ptr = s_ptr->next;
	}
	free(f_ptr);

	list->tail = init_node();
	list->root = list->tail;
}

int llsize(void* list_ptr)
{
	Node* ptr = ((LList*)list_ptr)->root;

	int c = 0;
	while((ptr = ptr->next) != NULL)
		++c;

	return c;
}

void* llget_data_node(void* node_ptr, int depth)
{
	if (depth == 0)
		if (node_ptr != NULL) return ((Node*)node_ptr)->data;
		else return NULL;
	else
	{
		if (node_ptr != NULL) return llget_data_node(((Node*)node_ptr)->next, (depth - 1));
		else return NULL;
	}
	
}

void* llget_data(void* list, int index)
{
	Node* node_ptr = ((LList*)list)->root;
	while(index > -1)
	{
		if (node_ptr->next != NULL)
			node_ptr = node_ptr->next;
		else return NO_DATA;
		--index;
	}
	return node_ptr->data;
}

Node* llget_node(Node* node, int index)
{
	if (index == 0)
		if (node != NULL) return node;
		else return NULL;
	else
	{
		if (node != NULL) return llget_node(node->next, (index - 1));
		else return NULL;
	}
	
}

void llset_data(void* list_ptr, int index, void* new_data)
{
	LList* list = list_ptr;
	Node* ptr = llget_node(list->root->next, index); 
	if (ptr != NULL)
		ptr->data = new_data;
}

LinkedListIterator ll_iterator_get_iterator(LinkedList list_ptr)
{
	return ((LList*)list_ptr)->root->next;
//	return ((LList*)list_ptr)->tail;
}

void* ll_iterator_this_value(LinkedListIterator lli_ptr)
{
	if (lli_ptr != NULL) return ((Node*)lli_ptr)->data;
	else return NO_DATA;
}

int ll_iterator_finished(LinkedListIterator lli_ptr)
{
	if (lli_ptr == NULL) return 0;
	return 1;
}

void ll_iterator_update_next(LinkedListIterator* lli_ptr)
{
	*lli_ptr = ((Node*)*lli_ptr)->next;
}
