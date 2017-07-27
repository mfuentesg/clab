#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

struct LinkedList* create_list() {
	struct LinkedList* list = (struct LinkedList*) malloc(sizeof(struct LinkedList));
	list->head = NULL;
	list->length = 0;

	return list;
}

struct LinkedListNode* create_node(unsigned int index, int value) {
	struct LinkedListNode* node = (struct LinkedListNode*) malloc(sizeof(struct LinkedListNode));
	node->next = NULL;
	node->index = index;
	node->value = value;

	return node;
}

void l_push(int value, struct LinkedList* list) {
	if (list->head == NULL) {
		list->length = 0;
		list->head = create_node(0, value);
	} else {
		struct LinkedListNode* current = list->head;

		while(current->next) {
			current = current->next;
		}

		current->next = create_node(list->length, value);
	}

	list->length += 1;
}

void l_print(struct LinkedList* list) {
	if (l_length(list)) {
		struct LinkedListNode* current = list->head;

		while(current) {
			printf("Element at %d -> %d\n", current->index, current->value);
			current = current->next;
		}
	}
}

void l_for_each(struct LinkedList* list, void callback(int, int)) {
	struct LinkedListNode* current = list->head;
	while(current) {
		(*callback)(current->value, current->index);
		current = current->next;
	}
}

unsigned int l_length(struct LinkedList* list) {
	return list->head == NULL ? 0 : list->length;
}
