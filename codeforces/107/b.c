#include <stdio.h>

int main() {
	int n, m, h;
	scanf("%d %d %d", &n, &m, &h);
	int arr[m];
	int sum = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d", arr + i);
		sum += arr[i];
	}

	if (n > sum)
		return printf("-1\n"), 0;

	int x = arr[--h] - 1;
	int y = sum - 1 - x;
	int s = x + y;
	int a = n - 1;

	if (a > y)
		return printf("1.0\n"), 0;

	float gooz = 1;
	for (int i = y + 1; i <= s; i++)
		gooz *= (float)(i - a) / (float)i;
	float ans = 1.0 - gooz;

	printf("%.6f\n", ans);
}
