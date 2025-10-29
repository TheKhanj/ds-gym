#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#define MAX_N 1000
#define MAX_NAME 32

typedef struct map_t {
	size_t size;
	char names[MAX_N][MAX_NAME + 1];
	int scores[MAX_N];
} map_t;

void map_init(map_t *this) { this->size = 0; }

int map_get(map_t *this, char *key) {
	for (size_t i = 0; i < this->size; i++)
		if (strcmp(this->names[i], key) == 0)
			return this->scores[i];

	assert(0 && "unreachable");
}

void map_set(map_t *this, char *key, int value) {
	for (size_t i = 0; i < this->size; i++)
		if (strcmp(this->names[i], key) == 0) {
			this->scores[i] = value;
			return;
		}

	strcpy(this->names[this->size], key);
	this->scores[this->size] = value;
	this->size++;
}

int map_has(map_t *this, char *key) {
	for (size_t i = 0; i < this->size; i++)
		if (strcmp(this->names[i], key) == 0)
			return 1;
	return 0;
}

int main() {
	int n;
	scanf("%d", &n);

	char names[n][MAX_NAME + 1];
	int scores[n];

	map_t mp;
	map_init(&mp);

	for (int i = 0; i < n; i++) {
		char name[MAX_NAME + 1];
		int score;
		scanf("%s %d", name, &score);

		strcpy(names[i], name);
		scores[i] = score;

		if (!map_has(&mp, name))
			map_set(&mp, name, 0);
		map_set(&mp, name, map_get(&mp, name) + score);
	}

	int max_score = 0;
	for (int i = 0; i < n; i++) {
		char name[MAX_NAME + 1];

		strcpy(name, names[i]);

		int curr_score = map_get(&mp, name);
		if (curr_score > max_score)
			max_score = curr_score;
	}

	map_t mp2;
	map_init(&mp2);

	for (int i = 0; i < n; i++) {
		char name[MAX_NAME + 1];
		int score;

		strcpy(name, names[i]);
		score = scores[i];

		if (!map_has(&mp2, name))
			map_set(&mp2, name, 0);
		map_set(&mp2, name, map_get(&mp2, name) + score);

		int curr_score = map_get(&mp2, name);
		if (curr_score >= max_score && map_get(&mp, name) == max_score) {
			printf("%s\n", name);
			break;
		}
	}
}
