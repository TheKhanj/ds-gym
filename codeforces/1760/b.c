#include <stdio.h>

#define MAX(a, b) ((a) < (b) ? (b) : (a))

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		char s[n + 1];
		scanf("%s", s);
		char max = s[0];
		for (int i = 0; i < n; i++)
			max = MAX(max, s[i]);
		printf("%d\n", max - 'a' + 1);
	}
}
