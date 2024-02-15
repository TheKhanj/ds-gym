#include <stdbool.h>
#include <stdio.h>

bool is_in(char c) {
	char arr[] = "codeforces";
	int n = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < n; i++) {
		if (c == arr[i]) {
			return true;
		}
	}

	return false;
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		char s[2];
		scanf("%s", s);
		printf("%s\n", is_in(s[0]) ? "YES" : "NO");
	}
}
