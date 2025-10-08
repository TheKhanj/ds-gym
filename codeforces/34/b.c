#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int arr[n], wanted[n], wanted_ind = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		if (arr[i] < 0) {
			wanted[wanted_ind++] = arr[i];
		}
	}

	qsort(wanted, wanted_ind, sizeof(wanted[0]), cmp);

	int sum = 0;
	for (int i = 0; i < m && i < wanted_ind; i++)
		sum += wanted[i];

	printf("%d\n", -sum);
}
