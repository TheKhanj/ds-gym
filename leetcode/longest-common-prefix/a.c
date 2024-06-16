#include <stdio.h>
char *longestCommonPrefix(char **strs, int n) {
	if (n == 1)
		return strs[0];

	for (int l = 0;; l++)
		for (int i = 0; i < n - 1; i++)
			if (strs[i][l] == '\0' || strs[i][l] != strs[i + 1][l]) {
				strs[0][l] = '\0';
				return strs[0];
			}
}

void test() {
	char *strs[] = {"flower", "flow", "flight"};
	printf("%s\n", longestCommonPrefix(strs, 3));
}

int main() { test(); }
