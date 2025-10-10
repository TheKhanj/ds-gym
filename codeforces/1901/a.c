#include <stdio.h>

#define MAX(a, b) ((a) < (b) ? (b) : (a))

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d %d", &n, &k);
		int arr[n];
		int max = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", arr + i);
			max = MAX(max, arr[i] - (i != 0 ? arr[i - 1] : 0));
		}
		max = MAX(max, (k - arr[n - 1]) * 2);
		printf("%d\n", max);
	}
}
