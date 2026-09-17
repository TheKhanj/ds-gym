#include <stdio.h>
#include <stdlib.h>

int iless(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void solve() {
	int n;
	scanf("%d", &n);
	int *arr[n];

	long long beauty = 0;
	int min1 = 1e9 + 1, min1_i = -1;
	int min2 = 1e9 + 1, min2_i = -1;
	for (int i = 0; i < n; i++) {
		int m;
		scanf("%d", &m);
		arr[i] = (int *)malloc(sizeof(int) * m);
		for (int j = 0; j < m; j++)
			scanf("%d", arr[i] + j);
		qsort(arr[i], m, sizeof(arr[i][0]), iless);
		beauty += arr[i][1];

		if (arr[i][0] < min1) {
			min1 = arr[i][0];
			min1_i = i;
		}
		if (arr[i][1] < min2) {
			min2 = arr[i][1];
			min2_i = i;
		}
	}

	beauty += (long long)arr[min1_i][0] - (long long)arr[min2_i][1];
	for (int i = 0; i < n; i++)
		free(arr[i]);

	printf("%lld\n", beauty);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
