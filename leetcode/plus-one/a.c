#include <stdlib.h>
#include <string.h>

int *plusOne(int *arr, int n, int *ret_size) {
	int *ret = calloc(n + 1, sizeof(int));

	memcpy(ret + 1, arr, sizeof(int) * n);
	ret[n]++;
	for (int i = n; i >= 0; i--)
		if (ret[i] > 9)
			ret[i - 1] += ret[i] / 10, ret[i] %= 10;

	if (ret[0]) {
		*ret_size = n + 1;
		return ret;
	}
	*ret_size = n;
	return ret + 1;
}
