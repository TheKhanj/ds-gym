#include <stdio.h>

#define MAX(a, b) ((a) < (b) ? (b) : (a))

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	int ans = 0;
	for (int i = 0; i < n;) {
		int base = i;
		do
			i++;
		while (i < n && arr[i] > arr[i - 1]);
		ans = MAX(ans, i - base);
	}
	printf("%d\n", ans);
}
