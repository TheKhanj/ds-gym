#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, x;
		scanf("%d %d", &n, &x);
		int has_ans =0;
		int j =0;
		for (int i = 1; i * i <= n; i++, j=i)
			if (n % i == 0 && n / i <= n / x) {
				has_ans = 1;
				printf("%d\n", n / i);
				break;
			}

		if(!has_ans)
		for (int i = j; i>=0; i--)
			if (n % i == 0 && i <= n / x) {
				has_ans = 1;
				printf("%d\n", i);
				break;
			}
	}
}
