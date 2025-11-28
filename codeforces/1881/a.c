#include <stdio.h>

#define MAX(a, b) ((a) < (b) ? (b) : (a))

int equal(char *s1, char *s2, int n) {
	for (int i = 0; i < n; i++)
		if (s1[i] != s2[i])
			return 0;
	return 1;
}

int lg(int n1, int a) {
	int ans = 0;
	while (n1 < a) {
		ans++;
		n1 *= 2;
	}

	return ans;
}

void solve() {
	int n1, n2;
	scanf("%d %d", &n1, &n2);
	int mx = MAX(2 * n2, 2 * n1);
	char s1[mx + 1], s2[n2 + 1];
	scanf("%s", s1);
	scanf("%s", s2);

	int sz = n1;
	while (sz <= mx) {
		for (int i = sz; i < 2 * sz && i < mx; i++)
			s1[i] = s1[i - sz];
		sz *= 2;
	}
	s1[mx] = 0;

	for (int i = 0; i < mx - n2; i++)
		if (equal(s1 + i, s2, n2)) {
			printf("%d\n", lg(n1, i + n2));
			return;
		}
	printf("-1\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
