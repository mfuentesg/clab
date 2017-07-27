#ifndef SRC_LINKED_LIST_H_
#define SRC_LINKED_LIST_H_

struct LinkedListNode {
	struct LinkedListNode* next;
	unsigned int index;
	int value;
};

struct LinkedList {
	struct LinkedListNode* head;
	unsigned int length;
};

struct LinkedList* create_list(void);
struct LinkedListNode* create_node(unsigned int, int);

void l_push(int, struct LinkedList*);
void l_print(struct LinkedList*);
void l_prepend(struct LinkedList*);
void l_for_each(struct LinkedList*, void (int, int));

unsigned int l_length(struct LinkedList*);

#endif /* SRC_LINKED_LIST_H_ */
