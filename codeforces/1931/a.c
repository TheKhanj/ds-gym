#include <stdio.h>

void solve(int x) {
	int ans[3];
	x -= 3;
	for (int i = 0; i < 3; i++) {
		ans[i] = 0;
		if (x > 25) {
			ans[i] = 25;
			x -= 25;
		} else {
			ans[i] = x;
			x = 0;
		}
	}
	for (int i = 2; i >= 0; i--) {
		printf("%c", ans[i] + 'a');
	}
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int x;
		scanf("%d", &x);
		solve(x);
	}
}
