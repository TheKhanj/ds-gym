#include <stdio.h>

#define MAX(a, b) ((a) < (b) ? (b) : (a))

void solve() {
	int n;
	scanf("%d", &n);
	char s[n + 1];
	scanf("%s", s);
	int len = 0, sum = 0;
	for (int i = 0; i < n;) {
		char c = s[i];
		if (c == '#') {
			i++;
			continue;
		}

		int r = i, l = i;
		while (r < n && s[r] == c)
			r++;
		int size = r - l;
		sum += size;
		len = MAX(len, size);

		i = r;
	}
	if (len >= 3)
		printf("2\n");
	else
		printf("%d\n", sum);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
