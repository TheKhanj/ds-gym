#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
	int val;
	struct node_t *next;
} node_t;

void myReorder(node_t *head, node_t **l, node_t **r) {
	if (head == *l) {
		node_t *r_tmp = (**r).next;
		(*r)->next = NULL;
		if (*l != *r)
			(*l)->next = (*r);
		*r = r_tmp;
		return;
	}

	myReorder(head->next, l, r);
	*l = head;

	node_t *l_tmp = (**l).next;
	node_t *r_tmp = (**r).next;
	(**l).next = *r;
	(**r).next = l_tmp;

	*r = r_tmp;
}

int getLength(node_t *head) {
	int n = 0;
	while (head) {
		n++;
		head = head->next;
	}

	return n;
}

node_t *getIndex(node_t *head, int n) {
	for (int i = 0; i < n; i++) {
		head = head->next;
	}
	return head;
}

/**
 * Definition for singly-linked list.
 */
void reorderList(node_t *head) {
	int n = getLength(head);

	node_t *l = getIndex(head, n % 2 == 1 ? n / 2 : n / 2 - 1);
	node_t *r = getIndex(head, n % 2 == 1 ? n / 2 : n / 2);

	myReorder(head, &l, &r);
}

void test() {
	int n = 4;
	node_t arr[n];
	for (int i = 0; i < n; i++) {
		arr[i].val = i + 1;
		arr[i].next = arr + i + 1;
		if (i == n - 1)
			arr[i].next = NULL;
	}

	reorderList(arr);

	node_t *head = arr;
	for (int i = 0; i < n; i++) {
		printf("%d ", head->val);
		head = head->next;
	}
}

int main() { test(); }
