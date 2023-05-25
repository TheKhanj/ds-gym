#include <stdio.h>
#include <stdlib.h>

struct vec_t {
	void **arr;
	int max_size;
	int size;
};

void vec_init(struct vec_t *vec) {
	vec->size = 0;
	vec->max_size = 1;
	vec->arr = malloc(sizeof(void *));
}

void vec_push(struct vec_t *vec, void *x) {
	vec->arr[vec->size++] = x;

	if (vec->size == vec->max_size) {
		vec->max_size *= 2;
		vec->arr = realloc(vec->arr, vec->max_size * sizeof(void *));
	}
}

void vec_deinit(struct vec_t *vec) { free(vec->arr); }

char *get_hour(int hour, int minute) {
	char *ret = malloc(6);
	int i = 0;
	if (hour >= 10) {
		ret[i++] = '1';
		hour -= 10;
	}
	ret[i++] = hour % 10 + '0';
	ret[i++] = ':';
	ret[i++] = minute / 10 + '0';
	ret[i++] = minute % 10 + '0';
	ret[i++] = '\0';

	return ret;
}

int count_bit(int x) {
	int ret = 0;
	while (x) {
		ret += x % 2;
		x /= 2;
	}

	return ret;
}

void magic(struct vec_t *vec, int size, int ones) {
	for (int i = 0; i < (1 << size); i++) {
		if (count_bit(i) == ones) {
			int *x = malloc(sizeof(int));
			*x = i;
			vec_push(vec, x);
		}
	}
}

char **readBinaryWatch(int turnedOn, int *returnSize) {
	struct vec_t ret;
	vec_init(&ret);

	for (int i = 0; i <= turnedOn && i <= 4; i++) {
		int j = turnedOn - i;

		if (j >= 6) {
			continue;
		}

		struct vec_t a, b;
		vec_init(&a);
		vec_init(&b);

		magic(&a, 4, i);
		magic(&b, 6, j);

		for (int x = 0; x < a.size; x++) {
			for (int y = 0; y < b.size; y++) {
				int x_value = *(int *)a.arr[x];
				int y_value = *(int *)b.arr[y];

				if (x_value >= 12) {
					continue;
				}

				if (y_value >= 60) {
					continue;
				}

				char *result = get_hour(x_value, y_value);
				vec_push(&ret, result);
			}
		}

		vec_deinit(&a);
		vec_deinit(&b);
	}

	*returnSize = ret.size;

	return (char **)ret.arr;
}
