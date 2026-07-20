#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? -(a) : (a))

int main() {
	int n;
	scanf("%d", &n);
	int arr[n], min = 1e5;
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		min = MIN(ABS(arr[i]), min);
	}

	printf("%d\n", min);
}
