#include <stdio.h>

int main() {
	long long n;
	scanf("%lld", &n);
	long long ans;
	if (n == 3)
		ans = 6;
	else if (n == 2)
		ans = 2;
	else if (n == 1)
		ans = 1;
	else if (n % 2 == 0) {
		if (n % 3 == 0)
			ans = (n - 1) * (n - 2) * (n - 3);
		else
			ans = n * (n - 1) * (n - 3);
	} else
		ans = n * (n - 1) * (n - 2);
	printf("%lld\n", ans);
}
