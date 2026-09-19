#include <stdio.h>
#include <stdlib.h>

int imore(const void *a, const void *b) { return *(int *)b - *(int *)a; }

int main() {
	int k;
	scanf("%d", &k);
	int len = 12;
	int arr[len];
	for (int i = 0; i < len; i++)
		scanf("%d", arr + i);
	qsort(arr, len, sizeof(arr[0]), imore);

	int ans = 0, height = 0;
	for (int i = 0; i < len && height < k; i++)
		ans++, height += arr[i];

	printf("%d\n", height >= k ? ans : -1);
}
