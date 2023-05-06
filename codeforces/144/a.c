#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef struct soldier {
	int32_t pos, height;
} soldier;

static void soldier_copy(soldier *dest, soldier *src) {
	dest->height = src->height;
	dest->pos = src->pos;
}

static bool soldier_is_taller(soldier *a, soldier *b) {
	if (a->height == b->height) {
		return a->pos < b->pos;
	}

	return a->height > b->height;
}

static bool soldier_is_shorter(soldier *a, soldier *b) {
	if (a->height == b->height) {
		return a->pos > b->pos;
	}

	return a->height < b->height;
}

static void soldier_print(soldier *a) {
	printf("-- %d %d\n", a->pos, a->height);
}

int32_t main() {
	int32_t n;
	scanf("%d", &n);

	soldier tallest = {.height = -1, .pos = -1},
			shortest = {.height = 101, .pos = 101};

	for (int32_t i = 0; i < n; i++) {
		int32_t height;
		scanf("%d", &height);
		soldier current = {.pos = i, .height = height};

		if (soldier_is_taller(&current, &tallest)) {
			soldier_copy(&tallest, &current);
		}

		if (soldier_is_shorter(&current, &shortest)) {
			soldier_copy(&shortest, &current);
		}
	}

	printf("%d", n - 1 + tallest.pos - shortest.pos +
					 (tallest.pos > shortest.pos ? -1 : 0));
}
