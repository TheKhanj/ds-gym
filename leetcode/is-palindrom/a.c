#include <stdbool.h>
#include <stdio.h>

int to_array(int x, char *arr) {
	int n = 0;
	while (x) {
		arr[n++] = x % 10;
		x /= 10;
	}
	return n;
}

bool isPalindrome(int x) {
	char arr[50];
	if (x < 0)
		return false;
	int n = to_array(x, arr);

	for (int i = 0; 2 * i < n; i++)
		if (arr[i] != arr[n - 1 - i])
			return false;
	return true;
}

void test() { printf("%d\n", isPalindrome(-121)); }

// int main() { test(); }
