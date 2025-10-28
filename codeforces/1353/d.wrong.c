#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct range_t {
	size_t l, r;
} range_t;

size_t range_len(range_t *this) { return this->r - this->l; }

void range_init(range_t *this, size_t l, size_t r) {
	this->l = l;
	this->r = r;
}

typedef struct node_t node_t;
struct node_t {
	void *value;
	node_t *next;
};

void node_init(node_t *this, void *value, size_t bytes) {
	this->next = NULL;
	if (value != NULL) {
		this->value = malloc(bytes);
		memcpy(this->value, value, bytes);
	}
}

typedef struct queue_t {
	size_t bytes, size;
	node_t head, *tail;
} queue_t;

void queue_init(queue_t *this, size_t bytes) {
	node_init(&this->head, NULL, bytes);
	this->tail = &this->head;
	this->bytes = bytes;
	this->size = 0;
}

void queue_push(queue_t *this, void *value) {
	node_t *node = malloc(sizeof(node_t));
	node_init(node, value, this->bytes);

	assert(this->tail != NULL);
	assert(node != NULL);
	this->tail->next = node;
	this->tail = node;
	this->size++;
}

size_t queue_size(queue_t *this) { return this->size; }

void *queue_pop(queue_t *this) {
	assert(queue_size(this));

	node_t *node = this->head.next;

	void *value = node->value;
	this->head.next = node->next;
	free(node);
	this->size--;
	if (this->size == 0)
		this->tail = &this->head;
	return value;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);

		range_t whole;
		range_init(&whole, 0, n);

		queue_t q;
		queue_init(&q, sizeof(range_t));
		queue_push(&q, &whole);

		int arr[n], i = 1;
		while (queue_size(&q)) {
			range_t range = *(range_t *)queue_pop(&q);
			size_t len = range_len(&range);

			size_t mid = (range.l + range.r - 1) / 2;
			arr[mid] = i++;
			if (len == 1)
				continue;

			range_t left, right;
			range_init(&left, range.l, mid);
			range_init(&right, mid + 1, range.r);

			if (range_len(&left))
				queue_push(&q, &left);
			if (range_len(&right))
				queue_push(&q, &right);
		}

		for (int i = 0; i < n; i++)
			printf("%d ", arr[i]);
		printf("\n");

		// queue_free(&q);
	}
}
