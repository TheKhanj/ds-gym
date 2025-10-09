#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		char s[n];
		scanf("%s", s);
		int opens = 0, moves = 0;
		for (int i = 0; i < n; i++)
			if (s[i] == '(')
				opens++;
			else if (opens == 0)
				moves++;
			else
				opens--;
		printf("%d\n", moves);
	}
}
