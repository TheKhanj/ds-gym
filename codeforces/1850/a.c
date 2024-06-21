#include <stdio.h>

void swap(int *a, int *b) {
	*b ^= *a;
	*a ^= *b;
	*b ^= *a;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int a[3];
		scanf("%d %d %d", a, a + 1, a + 2);
		if (a[0] > a[1])
			swap(a, a + 1);
		if (a[1] > a[2])
			swap(a + 1, a + 2);
		if (a[0] > a[1])
			swap(a, a + 1);

		printf("%s\n", a[1] + a[2] >= 10 ? "YES" : "NO");
	}
}
