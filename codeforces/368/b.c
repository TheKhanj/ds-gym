#include <stdio.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	int sz = 100000 + 1;
	int vis[sz];
	int cnt = 0;
	int ans[n];
	for (int i = 0; i < sz; i++)
		vis[i] = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (vis[arr[i]] == 0) {
			cnt++;
			vis[arr[i]] = 1;
		}
		ans[i] = cnt;
	}

	for (int i = 0; i < m; i++) {
		int a;
		scanf("%d", &a);
		printf("%d\n", ans[--a]);
	}
}
