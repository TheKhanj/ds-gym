#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

const int INF = 1e9 + 10;

void solve_test_case() {
	int n;
	scanf("%d", &n);
	int min = INF, max = 0;
	while (n--) {
		int x;
		scanf("%d", &x);
		min = MIN(x, min);
		max = MAX(x, max);
	}

	printf("%d\n", max - min);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve_test_case();
	}
}
