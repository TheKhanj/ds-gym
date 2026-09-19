#include <stdio.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int arr[n];
	int max = 0, max_i = -1;
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		int cnt = (arr[i] / m) + (arr[i] % m == 0 ? 0 : 1);
		if (cnt >= max) {
			max = cnt;
			max_i = i;
		}
	}
	printf("%d\n", max_i + 1);
}
