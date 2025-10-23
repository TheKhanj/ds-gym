#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct stack_t {
	int cross;
	int year;
} stack_t;

int cmp(const void *a, const void *b) {
	const stack_t *x = a, *y = b;
	if (x->year == y->year)
		return x->cross - y->cross;
	return x->year - y->year;
}

int main() {
	int n;
	scanf("%d", &n);

	stack_t arr[2 * n];
	size_t sz = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[sz++] = (stack_t){
				.cross = +1,
				.year = a,
		};
		arr[sz++] = (stack_t){
				.cross = -1,
				.year = b,
		};
	}
	qsort(arr, sz, sizeof(arr[0]), cmp);

	int people = 0, max_people = 0, max_year = 0;
	for (size_t i = 0; i < sz; i++) {
		people += arr[i].cross;
		if (people > max_people) {
			max_year = arr[i].year;
			max_people = people;
		}
	}

	printf("%d %d\n", max_year, max_people);
}
