#include <stdio.h>

int main() {
	int n, t;
	scanf("%d %d", &n, &t);
	t--;
	int arr[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}

	int pos = 0;
	while (pos < t) {
		pos = arr[pos] + pos;
	}

	printf("%s\n", pos == t ? "YES" : "NO");
}
