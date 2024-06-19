#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int size;
	int capacity;
	void **data;
} vec_t;

static inline void vec_init(vec_t *self, int initial_capacity) {
	self->size = 0;
	self->capacity = initial_capacity;
	self->data = malloc(self->capacity * self->capacity * sizeof(void *));
}

static inline void vec_push(vec_t *self, void *data) {
	self->data[self->size++] = data;

	if (self->size == self->capacity)
		self->data = realloc(self->data, (self->capacity *= 2) * sizeof(void *));
}

typedef struct node_t {
	int counted;
	char *word;
	char c;
	struct node_t *next[26];
} node_t;

static inline void node_init(node_t *self) {
	self->counted = 0;
	self->word = NULL;
	self->c = '.';
	for (int i = 0; i < 26; i++)
		self->next[i] = NULL;
}

typedef struct {
	node_t root;
	int node_size;
	node_t *nodes;
} trie_t;

static inline void trie_init(trie_t *self, int max_nodes) {
	node_init(&self->root);
	self->node_size = 0;
	self->nodes = malloc(max_nodes * sizeof(node_t));
}

static inline node_t *trie_new_node(trie_t *self) {
	return self->nodes + self->node_size++;
}

void trie_add_word(trie_t *self, node_t *node, char *word, char *initial) {
	if (*word == '\0') {
		node->word = initial;
		return;
	}

	int i = *word - 'a';

	if (!node->next[i]) {
		node->next[i] = trie_new_node(self);
		node_init(node->next[i]);
		node->next[i]->c = *word;
	}

	trie_add_word(self, node->next[i], word + 1, initial);
}

typedef struct {
	int *vis;
	vec_t *words;

	char **board;
	int n, m;

	trie_t *trie;
} dfs_t;

static inline void dfs_init(dfs_t *self, trie_t *trie, vec_t *words,
														char **board, int n, int m) {
	self->trie = trie;
	self->words = words;
	self->board = board;
	self->n = n;
	self->m = m;

	self->vis = calloc(n * m, sizeof(int));
}

static inline int dfs_visited(dfs_t *self, int i, int j) {
	return self->vis[i * self->m + j];
}

void dfs_traverse(dfs_t *self, int row, int col, node_t *node, int len) {
	if (!node)
		return;

	if (node->word && !node->counted) {
		node->counted = 1;
		vec_push(self->words, node->word);
	}

	self->vis[row * self->m + col] = 1;

	int dxs[] = {1, -1, 0, 0};
	int dys[] = {0, 0, 1, -1};

	for (int i = 0; i < 4; i++) {
		int x = row + dxs[i];
		int y = col + dys[i];

		if (x < 0 || y < 0 || x >= self->n || y >= self->m)
			continue;

		if (dfs_visited(self, x, y))
			continue;

		char c = self->board[x][y];
		node_t *next = node->next[c - 'a'];
		if (!next)
			continue;

		dfs_traverse(self, x, y, next, len + 1);
	}

	self->vis[row * self->m + col] = 0;
}

char **findWords(char **board, int size, int *col, char **words, int wordsSize,
								 int *returnSize) {
	trie_t t;
	int max_word_len = 0;
	for (int i = 0; i < wordsSize; i++)
		max_word_len += strlen(words[i]) + 1;
	trie_init(&t, max_word_len);

	for (int i = 0; i < wordsSize; i++)
		trie_add_word(&t, &t.root, words[i], words[i]);

	int m = *col;
	int n = size;

	dfs_t dfs;
	vec_t ret;
	vec_init(&ret, wordsSize);
	dfs_init(&dfs, &t, &ret, board, n, m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			dfs_traverse(&dfs, i, j, t.root.next[board[i][j] - 'a'], 0);

	*returnSize = ret.size;

	return (char **)ret.data;
}

void test() {
	char b[][5] = {"oaan", "etae", "ihkr", "iflv"};
	char w[][5] = {"oath", "pea", "eat", "rain"};
	char *board[] = {b[0], b[1], b[2], b[3]};
	char *words[] = {w[0], w[1], w[2], w[3]};

	int col = 4;
	int ret_size;

	char **ret = findWords(board, 4, &col, words, 4, &ret_size);
	printf("%d\n", ret_size);
	for (int i = 0; i < ret_size; i++)
		printf("%s\n", ret[i]);
}

int main() { test(); }
