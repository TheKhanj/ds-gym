#include <stdio.h>

void test() {
	int n;
	scanf("%d", &n);
	int arr[n];
	int x = 1;
	for (int i = 0; i < n; i += 2, x += 1)
		arr[i] = x;
	for (int i = (n / 2) * 2 - 1; i >= 0; i -= 2, x += 1)
		arr[i] = x;
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		test();
}
