#include <stdio.h>

void solve() {
	int src[2], dst[2];
	scanf("%d %d", src + 0, src + 1);
	scanf("%d %d", dst + 0, dst + 1);
	if (dst[1] < src[1]) {
		printf("-1\n");
		return;
	}
	int ans = dst[1] - src[1];
	src[0] += ans;
	int diff = src[0] - dst[0];
	if (diff < 0) {
		printf("-1\n");
		return;
	}
	ans += diff;
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
