#include <stdio.h>

void solve() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);

	int ans = 0;
	for (int i = 0; i < n;) {
		int p = arr[i] % 2, len = 0;
		while (i < n && arr[i] % 2 == p)
			i++, len++;
		ans += len - 1;
	}

	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
