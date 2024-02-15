#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int arr[3];
		for (int i = 0; i < 3; i++) {
			scanf("%d", arr + i);
		}
		qsort(arr, 3, sizeof(arr[0]), cmp);
		printf("%d\n", arr[1]);
	}
}
