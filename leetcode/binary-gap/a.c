#include <assert.h>
#include <stdio.h>
#include <string.h>

#define MAX(a, b) (a) < (b) ? (b) : (a)

void rev_range(char *a, char *b) {
	b--;

	while (a <= b) {
		// swap
		char tmp = *a;
		*a = *b;
		*b = tmp;
		a++;
		b--;
	}
}

void fill_str(char *s, int x) {
	int n = 0;
	while (x) {
		s[n++] = x % 2 + '0';
		x /= 2;
	}
	s[n] = '\0';

	rev_range(s, s + n);
}

int binaryGap(int x) {
	char s[31];
	fill_str(s, x);

	int n = strlen(s);
	// printf("debug: %d %s\n", n, s);
	int l, r;

	l = 0;
	while (l < n && s[l] == '0')
		l++;
	r = l + 1;

	int ans = 0;

	while (r < n) {
		while (r < n && s[r] == '0')
			r++;

		if (r == n)
			continue;

		ans = MAX(ans, r - l);

		l = r;
		r = l + 1;
	}

	return ans;
}

void test() {
	assert(binaryGap(22) == 2);
	// printf("debug: %d\n", binaryGap(8));
	assert(binaryGap(8) == 0);
	assert(binaryGap(5) == 2);
}

// int main() { test(); }
