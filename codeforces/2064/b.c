#include <stdio.h>
#include <stdlib.h>

struct seg_t {
	int l, r;
};

int seg_size(const struct seg_t *a) { return a->r - a->l; }

int cmp(const void *a, const void *b) {
	const struct seg_t *x = a;
	const struct seg_t *y = b;

	if (seg_size(x) == seg_size(y))
		return x->l - y->l;

	return -(seg_size(x) - seg_size(y));
}

void solve() {
	int n;
	scanf("%d", &n);
	int arr[n], cnt[n];
	for (int i = 0; i < n; i++)
		cnt[i] = 0;
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i), cnt[arr[i] - 1]++;

	struct seg_t segs[n];
	int segs_len = 0;
	for (int l = 0; l < n;) {
		int r = l;
		while (r < n && cnt[arr[r] - 1] == 1)
			r++;
		if (l != r) {
			segs[segs_len++] = (struct seg_t){.l = l, .r = r};
			// printf("debug: %d %d\n", l, r);
			l = r;
		} else
			l = ++r;
	}

	qsort(segs, segs_len, sizeof(segs[0]), cmp);

	// printf("seglen: %d\n", segs_len);
	if (segs_len == 0)
		printf("0\n");
	else
		printf("%d %d\n", segs[0].l + 1, segs[0].r);
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--)
		solve();
}
