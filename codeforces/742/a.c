#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	if (n == 0) {
		printf("1\n");
		return 0;
	}

	int arr[] = {8, 4, 2, 6};
	printf("%d\n", arr[(n - 1) % 4]);
}
