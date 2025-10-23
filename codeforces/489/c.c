#include <stdio.h>
#include <string.h>

void get_max(int n, int m, char *s) {
	for (int i = 0; i < n; i++) {
		int rem = (m >= 9 ? 9 : m);
		s[i] = rem + '0';
		m -= rem;
	}
	s[n] = '\0';
}

void reverse(int n, char *s) {
	for (int i = 0; i < n - 1 - i; i++) {
		s[i] ^= s[n - 1 - i];
		s[n - 1 - i] ^= s[i];
		s[i] ^= s[n - 1 - i];
	}
}

void get_min(int n, char *s) {
	reverse(n, s);
	if (s[0] != '0')
		return;

	for (int i = 0; i < n; i++)
		if (s[i] != '0') {
			s[i]--;
			break;
		}
	s[0]++;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	if (n == 1 && m == 0) {
		printf("0 0\n");
		return 0;
	}
	if (m == 0 || (n * 9) < m) {
		printf("-1 -1\n");
		return 0;
	}
	char max[101], min[101];
	get_max(n, m, max);
	strcpy(min, max);
	get_min(n, min);
	printf("%s %s\n", min, max);
}
