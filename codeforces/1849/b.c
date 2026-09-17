#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int v, index;
} pii;

int imore(const void *a, const void *b) {
	pii x = (*(pii *)a);
	pii y = (*(pii *)b);

	return x.v == y.v ? x.index - y.index : x.v > y.v ? -1 : 1;
}

void solve() {
	int n, k;
	scanf("%d %d", &n, &k);
	pii arr[n];
	for (int i = 0; i < n; i++) {
		arr[i].index = i;
		scanf("%d", &arr[i].v);
		arr[i].v = arr[i].v % k;
		if (arr[i].v == 0)
			arr[i].v = k;
	}
	qsort(arr, n, sizeof(arr[0]), imore);
	for (int i = 0; i < n; i++)
		printf("%d%c", arr[i].index + 1, i == n - 1 ? '\n' : ' ');
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
