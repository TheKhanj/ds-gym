#include <stdio.h>

void solve() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	for (int i = 0, l = 0, r = n - 1; i < n; i % 2 == 0 ? l++ : r--, i++)
		printf("%d ", arr[i % 2 == 0 ? l : r]);
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
