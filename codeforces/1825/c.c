#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x < y ? x : y)

int32_t cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int32_t get_pos(int32_t i, int32_t pos, size_t size, int32_t left,
				int32_t right, int32_t m) {
	int32_t l = MIN(pos == 0 ? 0 : pos - i , left);
	int32_t r = MIN(pos == m + 1 ? 0 : m - pos - (size - 2 - i), right);

	// printf("--- %d %d -- %d -- %d %d\n", l, r, pos, left, right);

	return r + l + size - 2;
}

void debug(int32_t *arr, size_t size) {
	printf("-- ");
	for (int32_t i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void answer_test_case() {
	int32_t n, m;
	scanf("%d %d", &n, &m);

	int32_t x[n], x_size = 0;
	int32_t left = 0, right = 0;

	for (int32_t i = 0; i < n; i++) {
		int32_t tmp;
		scanf("%d", &tmp);
		if (tmp == -1) {
			left++;
		} else if (tmp == -2) {
			right++;
		} else {
			x[x_size++] = tmp;
		}
	}

	int32_t x_unique[x_size + 2], x_unique_size = 0;
	x_unique[x_unique_size++] = 0;

	qsort(x, x_size, sizeof(int32_t), cmp);
	for (int32_t i = 0; i < x_size;) {
		const int32_t val = x[i];
		x_unique[x_unique_size++] = val;

		while (x[i] == val) {
			i++;
		}
	}

	x_unique[x_unique_size++] = m + 1;
	// debug(x_unique, x_unique_size);
	// printf("-- %d %d\n", left, right);

	int32_t max_people = 0;
	for (int32_t i = 0; i < x_unique_size; i++) {
		const int32_t val = x_unique[i];

		int32_t curr = get_pos(i, val, x_unique_size, left, right, m);
		max_people = MAX(curr, max_people);
	}

	printf("%d\n", max_people);
}

int32_t main() {
	int32_t t;
	scanf("%d", &t);

	while (t--) {
		answer_test_case();
	}
}
