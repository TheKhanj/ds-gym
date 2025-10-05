#include <stdio.h>

int digitSum(int a) {
	int ret = 0;
	while (a) {
		ret += a % 10;
		a /= 10;
	}
	return ret;
}

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int a;
		scanf("%d", &a);
		printf("%d\n", digitSum(a));
	}
}
