#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

long long p(long long a, long long b) {
	if (a > b)
		return 0;

	return b * (b - 1) / 2;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int arr[n];
		for (int i = 0; i < n; i++) {
			scanf("%d", arr + i);
			arr[i] += -i;
		}
		qsort(arr, n, sizeof(arr[0]), cmp);

		long long ans = 0;
		for (int i = 0; i < n;) {
			int base = i;
			while (i < n && arr[i] == arr[base])
				i++;
			ans += p(2, i - base);
		}
		printf("%lld\n", ans);
	}
}
