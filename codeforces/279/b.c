#include <stdbool.h>
#include <stdio.h>

#define MAX(a, b) ((a) < (b) ? (b) : (a))

typedef struct {
	int *arr, *sum;
	int n;
	int t;
	int start;
} counter_t;

int counter_sum(counter_t *c, int len) {
	int end = (len + c->start - 1) % c->n;
	return c->sum[end] - (c->start == 0 ? 0 : c->sum[c->start - 1]);
}

bool counter_check(counter_t *c, int len) {
	int sum = counter_sum(c, len);
	return sum <= c->t;
}

int counter_count(counter_t *c, int l, int r) {
	if (l == r - 1) {
		return l;
	}

	int mid = (l + r) / 2;
	if (counter_check(c, mid)) {
		return counter_count(c, mid, r);
	}
	return counter_count(c, l, mid);
}

int main() {
	int n, t;
	scanf("%d %d", &n, &t);
	int arr[n], sum[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		sum[i] = (i == 0 ? 0 : sum[i - 1]) + arr[i];
	}

	int maxCnt = 0;
	for (int i = 0; i < n; i++) {
		counter_t c = {
				.arr = arr,
				.sum = sum,
				.n = n,
				.t = t,
				.start = i,
		};
		int cnt = counter_count(&c, 0, n - i + 1);
		maxCnt = MAX(cnt, maxCnt);
	}
	printf("%d\n", maxCnt);
}
