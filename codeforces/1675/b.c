#include <stdio.h>

void solve() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	int ans = 0;
	for (int i = n - 1; i > 0; i--) {
		while (arr[i - 1] >= arr[i]) {
			if (arr[i - 1] == 0) {
				ans = -1;
				goto print;
			}
			arr[i - 1] /= 2, ans++;
		}
	}

print:
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
