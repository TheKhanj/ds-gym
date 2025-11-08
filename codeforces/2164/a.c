#include <stdio.h>

#define MAX(a, b) ((a) < (b) ? (b) : (a))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, x;
		scanf("%d", &n);
		int arr[n];
		for (int i = 0; i < n; i++)
			scanf("%d", arr + i);
		scanf("%d", &x);

		int max = arr[0], min = arr[0];
		for (int i = 0; i < n; i++) {
			max = MAX(arr[i], max);
			min = MIN(arr[i], min);
		}
		printf("%s\n", x <= max && x >= min ? "YES" : "NO");
	}
}
