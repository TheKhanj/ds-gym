#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int max = MAX(a, b);
	int remain = 6 - max + 1;

	for (int i = 6; i >= 1; i--) {
		if (remain % i == 0 && 6 % i == 0) {
			printf("%d/%d\n", remain / i, 6 / i);
			break;
		}
	}
}
