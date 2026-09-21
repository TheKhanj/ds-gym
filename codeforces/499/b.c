#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

// const int MAX_LEN = 1000;
// const int MAX_LEN = 9999991;
// const int MAX_LEN = 99991;
// const int MAX_LEN = 10007;
const int MAX_LEN = 5003;
const int MAX_COLLISIONS = 12;

int hash(const char *s) {
	char c;
	uint64_t h = 0;

	while ((c = (*s++)))
		h = c + (h << 16) + (h << 6) - h;

	return h % MAX_LEN;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int s[MAX_LEN][MAX_COLLISIONS];

	for (int i = 0; i < MAX_LEN; i++)
		for (int j = 0; j < MAX_COLLISIONS; j++)
			s[i][j] = -1;

	char a[m][11], b[m][11];
	for (int i = 0; i < m; i++) {
		scanf("%s %s", a[i], b[i]);
		int h = hash(a[i]);
		// no collisions
		int index = 0;
		while (index < MAX_COLLISIONS && s[h][index] != -1)
			index++;
		assert(index < MAX_COLLISIONS);

		s[h][index] = i;
	}
	for (int i = 0; i < n; i++) {
		char input[11];
		scanf("%s", input);

		int h = hash(input);
		int index = 0;
		for (; index < MAX_COLLISIONS && s[h][index] != -1; index++)
			if (strcmp(a[s[h][index]], input) == 0)
				break;
		int found = s[h][index];
		char *ans = strlen(a[found]) <= strlen(b[found]) ? a[found] : b[found];
		printf("%s%c", ans, i == n - 1 ? '\n' : ' ');
	}
}
