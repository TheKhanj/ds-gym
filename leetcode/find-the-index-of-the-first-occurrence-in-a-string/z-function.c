#include <stdio.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

void z_function(char *s, int n, int *z) {
	int l = 0;
	int r = 0;
	memset(z, 0, sizeof(z[0]) * n);
	for (int i = 1; i < n; i++) {
		if (i < r)
			z[i] = MIN(r - i, z[i - l]);
		while (z[i] + i < n && s[z[i] + i] == s[z[i]])
			z[i]++;
		if (r < z[i] + i)
			l = i, r = z[i] + i;
	}
}

int strStr(char *s, char *pattern) {
	int n = strlen(s);
	int pattern_len = strlen(pattern);
	if (pattern_len > n)
		return -1;

	int z_len = pattern_len + n;
	int z[z_len];
	char combined[z_len + 1];
	strcpy(combined, pattern);
	strcpy(combined + pattern_len, s);
	z_function(combined, z_len, z);

	for (int i = pattern_len; i < z_len; i++)
		if (z[i] >= pattern_len)
			return i - pattern_len;
	return -1;
}

void test() { printf("%d\n", strStr("aadbutsad", "sad")); }

int main() { test(); }
