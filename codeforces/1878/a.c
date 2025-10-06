#include <stdbool.h>
#include <stdio.h>

bool is_possible(int n, int k) {
	bool ret = false;
	int arr[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		if (arr[i] == k) {
			ret = true;
		}
	}
	return ret;
}

void solve() {
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%s\n", is_possible(n, k) ? "YES" : "NO");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
}
