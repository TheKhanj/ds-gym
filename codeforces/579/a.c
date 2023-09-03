#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int count = 0;
	while (n) {
		count += n % 2;
		n /= 2;
	}
	printf("%d", count);
}
