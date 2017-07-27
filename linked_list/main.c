#include <stdio.h>
#include "linked_list.h"

void on_each_element(int value, int index) {
	printf("the value is %d at %d\n", value, index);
}

int main() {
	struct LinkedList* list = create_list();
	l_push(1, list);
	l_push(2, list);
	l_push(3, list);

	l_for_each(list, on_each_element);

	return 0;
}
