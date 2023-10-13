#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		long long int ans = 0;
		long long x;
		while (n--) {
			scanf("%lld", &x);
			x--;
			ans += x;
		}
		if (ans % 2 == 0) {
			printf("Torob\n");
		} else {
			printf("Torob Che\n");
		}
	}
}
