typedef struct node_t {
	int val;
	struct node_t *next;
} node_t;

node_t *mergeTwoLists(node_t *l1, node_t *l2) {
	if (!l1)
		return l2;
	if (!l2)
		return l1;

	if (l1->val > l2->val) {
		node_t *tmp = l1;
		l1 = l2;
		l2 = tmp;
	}
	node_t *start = l1;

	while (l1 && l2) {
		node_t *next = l1->next;

		if (!next) {
			l1->next = l2;
			break;
		};

		if (l2->val < next->val)
			l1->next = l2;

		l1 = next;
		if (l1->val > l2->val) {
			node_t *tmp = l1;
			l1 = l2;
			l2 = tmp;
		}
	}

	return start;
}
