#include <stdio.h>

void solve() {
	int n;
	scanf("%d", &n);
	int arr[n], cnt[2][n];
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		cnt[0][i] = (i == 0 ? 0 : cnt[0][i - 1]) + (arr[i] % 2 == 0);
	}

	for (int i = n - 1; i >= 0; i--)
		cnt[1][i] = (i == n - 1 ? 0 : cnt[1][i + 1]) + (arr[i] % 2 == 0);

	for (int i = 0; i < n - 1; i++)
		if (cnt[0][i] == cnt[1][i + 1]) {
			printf("%d\n", i + 1);
			return;
		}
	printf("-1\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
