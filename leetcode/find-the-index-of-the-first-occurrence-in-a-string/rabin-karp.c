#include <stdbool.h>
#include <stdio.h>
#include <string.h>

long long mod = 1e9 + 7;

long long get_hash(char *s, int len) {
	long long hash = 0;

	for (int i = 0; i < len; i++) {
		char c = s[i];
		hash = ((c - 'a') + 26 * hash) % mod;
	}

	return hash;
}

long long power(long long a, long long b) {
	if (b == 0)
		return 1;
	if (b == 1)
		return a % mod;

	long long x = power(a, b / 2);
	return ((x * x) % mod * power(a, b % 2)) % mod;
}

int match(char *a, char *b, int n) {
	for (int i = 0; i < n; i++)
		if (a[i] != b[i])
			return false;
	return true;
}

int strStr(char *s, char *pattern) {
	int n = strlen(s);
	int pattern_len = strlen(pattern);
	if (pattern_len > n)
		return -1;

	long long p = power(26, pattern_len);
	long long hash = get_hash(s, pattern_len);
	long long pattern_hash = get_hash(pattern, pattern_len);

	for (int i = pattern_len; i <= n; i++) {
		if (hash == pattern_hash)
			if (match(s + i - pattern_len, pattern, pattern_len))
				return i - pattern_len;

		char curr = s[i] - 'a';
		char prev = s[i - pattern_len] - 'a';

		hash = (hash * 26 + curr) % mod;
		hash = (hash + mod - (p * prev) % mod) % mod;
	}

	return -1;
}

void test() { printf("%d\n", strStr("aadbutsad", "sad")); }

int main() { test(); }
