#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int n, *arr;
	long long *sum;
} solution_t;

void solution_init(solution_t *s) {
	s->sum = (long long *)calloc(s->n, sizeof(long long));
	for (int i = 0; i < s->n; i++)
		s->sum[i] = s->arr[i] + (i == 0 ? 0 : s->sum[i - 1]);
}

bool solution_check(solution_t *s, int q, int mid) {
	return (mid == 0 ? 0 : s->sum[mid - 1]) < q;
}

int solution_bs(solution_t *s, int q, int l, int r) {
	if (l == r - 1)
		return l;
	int mid = (r + l) / 2;
	if (solution_check(s, q, mid))
		return solution_bs(s, q, mid, r);
	return solution_bs(s, q, l, mid);
}

int solution_query(solution_t *s, int q) { return solution_bs(s, q, 0, s->n); }

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);

	solution_t s = {.n = n, .arr = arr, .sum = NULL};
	solution_init(&s);

	int m;
	scanf("%d", &m);
	while (m--) {
		int q;
		scanf("%d", &q);
		printf("%d\n", solution_query(&s, q) + 1);
	}
}
