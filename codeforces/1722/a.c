#include <stdbool.h>
#include <stdio.h>

bool solve() {
	int n;
	scanf("%d", &n);
	char s[n + 1];
	scanf("%s", s);
	if (n != 5) {
		return false;
	}
	char name[] = "Timur";
	for (int i = 0; i < 5; i++) {
		bool found = false;
		for (int j = 0; j < 5; j++)
			if (s[j] == name[i]) {
				found = true;
				break;
			}

		if (!found)
			return false;
	}
	return true;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		printf("%s\n", solve() ? "YES" : "NO");
}
