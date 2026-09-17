#include <assert.h>
#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int first(char *s, int n, int i, char c) {
	while (i < n && s[i] != c)
		i++;
	if (i < n && s[i] == c)
		return i;
	i = 0;
	while (i < n && s[i] != c)
		i++;
	return i;
}

int solve() {
	int n;
	char c;
	scanf("%d %c", &n, &c);

	char s[n + 1];
	scanf("%s", s);

	if (c == 'g')
		return 0;

	int ret = 0;
	for (int i = 0; i < n;) {
		int prev = i;
		i = first(s, n, i, c);
		if (i < prev)
			break;
		int j = first(s, n, i, 'g');
		fprintf(stderr, "debug: i(%d), j(%d)\n", i, j);
		assert(i < n && j < n);

		int diff = j - i;
		assert(diff != 0);
		if (diff < 0)
			diff = j + n - i;

		ret = MAX(ret, diff);
		if (j < i)
			break;
		i = j + 1;
	}
	return ret;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		fprintf(stderr, "test(%d)\n", i);
		printf("%d\n", solve());
	}
}
