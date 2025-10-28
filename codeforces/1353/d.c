#include <stdio.h>
#include <stdlib.h>

typedef struct range_t {
	size_t l, r;
} range_t;

size_t range_len(range_t *this) { return this->r - this->l; }

void range_init(range_t *this, size_t l, size_t r) {
	this->l = l;
	this->r = r;
}

void range_gen(range_t *ranges, size_t *size, int l, int r) {
	range_t *range = ranges + (*size)++;
	range_init(range, l, r);

	if (l == r - 1)
		return;

	size_t mid = (l + r - 1) / 2;
	if (mid - l)
		range_gen(ranges, size, l, mid);
	if (r - mid - 1)
		range_gen(ranges, size, mid + 1, r);
}
void range_print(range_t *this) { printf("[%lu:%lu)\n", this->l, this->r); }

int range_cmp(const void *a, const void *b) {
	range_t x = *(range_t *)a;
	range_t y = *(range_t *)b;

	size_t lenx = range_len(&x), leny = range_len(&y);
	if (lenx == leny)
		return (x.l > y.l) - (x.l < y.l);
	return (lenx < leny) - (lenx > leny);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		range_t ranges[n];
		size_t size = 0;
		range_gen(ranges, &size, 0, n);
		qsort(ranges, size, sizeof(ranges[0]), range_cmp);

		int ans[n];
		for (size_t i = 0; i < size; i++) {
			range_t *range = ranges + i;
			size_t mid = (range->r + range->l - 1) / 2;
			ans[mid] = i + 1;
			// range_print(range);
		}
		for (int i = 0; i < n; i++)
			printf("%d ", ans[i]);
		printf("\n");
	}
}
