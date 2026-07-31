#include <stdbool.h>
#include <stdio.h>

bool is_possible(int *arr, int n) {
	for (int i = 0; i < n - 2; i++) {
		if (arr[i] < 0)
			return false;
		arr[i + 1] -= 2 * arr[i];
		arr[i + 2] -= arr[i];
		arr[i] = 0;
	}
	return arr[n - 1] == 0 && arr[n - 2] == 0;
}

void solve() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	printf("%s\n", is_possible(arr, n) ? "YES" : "NO");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
