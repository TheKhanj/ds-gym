#include <stdbool.h>
#include <stdio.h>

void solve() {
	int n;
	scanf("%d", &n);
	bool possible = false;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (i == 0 && x == 1)
			possible = true;
	}

	printf("%s\n", possible ? "YES" : "NO");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
