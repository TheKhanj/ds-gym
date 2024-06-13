// This gets into TLE, but it's fine, the purpose was to implement z function
// and not to get accept.

#include <stdio.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

const int MAX_N = 3000;
const int MAX_Q_STR = 500000;

void z_function(char *s, int n, int *z) {
	memset(z, 0, n * sizeof(z[0]));

	int l = 0, r = 0;
	for (int i = 1; i < n; ++i) {
		if (i < r)
			z[i] = MIN(r - i, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] > r)
			l = i, r = i + z[i];
	}
}

void join(char *s, int n, char *s2, int n2, char *joined) {
	memcpy(joined, s, n);
	memcpy(joined + n, s2, n2);
	joined[n + n2] = 0;
}

int main() {
	int n, t;
	scanf("%d %d", &n, &t);
	char s[n + 1];
	scanf("%s", s);

	char q[MAX_Q_STR + 1];
	char joined[n + MAX_Q_STR + 1];

	while (t--) {
		scanf("%s", q);
		int q_len = strlen(q);
		join(q, q_len, s, n, joined);
		int joined_len = strlen(joined);
		int z[joined_len];
		z_function(joined, joined_len, z);
		int cnt = 0;
		for (int i = q_len; i < joined_len; i++)
			if (z[i] >= q_len)
				cnt++;
		printf("%d\n", cnt);
	}
}
