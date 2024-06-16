typedef struct node_t {
	int val;
	struct node_t *next;
} node_t;

node_t *deleteDuplicates(node_t *head) {
	node_t *ret = head;
	while (head) {
		node_t *s = head;
		while (head && head->val == s->val)
			head = head->next;
		s->next = head;
	}
	return ret;
}
