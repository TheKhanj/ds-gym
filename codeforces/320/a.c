#include <stdio.h>

int is_magical(int n) {
	while (n) {
		int d = n % 10;
		if (d != 4 && d != 1)
			return 0;

		int cnt = 0;
		while (n && n % 10 == d)
			n /= 10, cnt++;
		if (d == 4 && cnt > 2)
			return 0;
		if (d == 4) {
			if (!n)
				return 0;
			if (n % 10 != 1)
				return 0;
		}
	}
	return 1;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%s\n", is_magical(n) ? "YES" : "NO");
}
