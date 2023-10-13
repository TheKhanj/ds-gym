#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool is_same(char *s1, int n1, char *s2, int n2) {
	if (n1 != n2) {
		return false;
	}

	for (int i = 0; i < n1; i++) {
		bool are_equal = true;
		bool are_equal2 = true;
		for (int j = 0; j < n1; j++) {
			char a = s1[j];
			char b = s2[(i + j) % n1];
			char c = s2[(i - j + n1) % n1];
			if (a != b) {
				are_equal = false;
			}
			if (a != c) {
				are_equal2 = false;
			}
		}

		if (are_equal) {
			return true;
		}
		if (are_equal2) {
			return true;
		}
	}
	return false;
}

int main() {
	int t;
	scanf("%d", &t);
	char s[2][10];
	while (t--) {
		scanf("%s %s", s[0], s[1]);
		int n1, n2;
		n1 = strlen(s[0]);
		n2 = strlen(s[1]);
		if (is_same(s[0], n1, s[1], n2)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}
