#include <stdio.h>

void test() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int j = 0; j < n; j++)
		for (int i = 0; i < k; i++)
			printf("%c", 'a' + i);
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		test();
}
