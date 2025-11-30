#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int index;
	int words, quality;
} participant_t;

int cmp(const void *a, const void *b) {
	participant_t x = *(participant_t *)a;
	participant_t y = *(participant_t *)b;

	return x.quality - y.quality;
}

void solve() {
	int n;
	scanf("%d", &n);
	int pn = 0;
	participant_t p[n];

	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a > 10)
			continue;

		p[pn].words = a;
		p[pn].quality = b;
		p[pn].index = i;
		pn++;
	}

	qsort(p, pn, sizeof(p[0]), cmp);
	printf("%d\n", p[pn - 1].index + 1);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
