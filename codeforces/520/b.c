#include <stdio.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int t = 0;
	while (n < m) {
		if (m % 2 == 0)
			m /= 2;
		else
			m++;

		t++;
	}
	t += n - m;
	printf("%d\n", t);
}
