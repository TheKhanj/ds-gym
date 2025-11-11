#include <stdio.h>

void get_move(char c, int move[2]) {
	switch (c) {
	case 'R':
		move[0] = 1;
		move[1] = 0;
		break;
	case 'L':
		move[0] = -1;
		move[1] = 0;
		break;
	case 'U':
		move[0] = 0;
		move[1] = 1;
		break;
	case 'D':
		move[0] = 0;
		move[1] = -1;
		break;
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		char s[n + 1];
		scanf("%s", s);
		int candy = 0;

		int pos[2] = {0, 0};
		for (int i = 0; i < n; i++) {
			int move[2];
			get_move(s[i], move);
			pos[0] += move[0];
			pos[1] += move[1];

			if (pos[0] == 1 && pos[1] == 1) {
				candy = 1;
				break;
			}
		}

		printf("%s\n", candy ? "YES" : "NO");
	}
}
