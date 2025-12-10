#include <stdio.h>

void solve() {
	int n;
	scanf("%d", &n);
	int arr[n];
	int ans[2 * n], ans_len = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		if (i != 0 && arr[i] < arr[i - 1])
			ans[ans_len++] = 1;
		ans[ans_len++] = arr[i];
	}
	printf("%d\n", ans_len);
	for (int i = 0; i < ans_len; i++)
		printf("%d ", ans[i]);
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
