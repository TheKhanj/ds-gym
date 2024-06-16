#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) < (b) ? (b) : (a))

char *addBinary(char *a, char *b) {
	int an = strlen(a), bn = strlen(b);
	int len = MAX(an, bn) + 1;
	char *ret = calloc(len + 1, sizeof(char));
	ret[len] = '\0';

	int carrier = 0;
	for (int i = len - 1, ia = an - 1, ib = bn - 1; ib >= 0 || ia >= 0;
			 i--, ia--, ib--) {
		int s;
		assert(ia >= 0 || ib >= 0);
		if (ia < 0)
			s = b[ib] - '0' + carrier;
		else if (ib < 0)
			s = a[ia] - '0' + carrier;
		else
			s = a[ia] - '0' + b[ib] - '0' + carrier;

		ret[i] = s % 2 + '0';
		carrier = s / 2;
	}
	*ret = carrier + '0';

	if (*ret == '0')
		ret++;

	return ret;
}

void test() { printf("%s\n", addBinary("0", "0")); }

int main() { test(); }
