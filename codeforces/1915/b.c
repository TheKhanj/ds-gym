#include <stdio.h>

void solve() {
	int n = 3;
	char mat[n][n + 1];
	char ans;
	for (int i = 0; i < n; i++) {
		scanf("%s", mat[i]);
		char *row = mat[i];
		for (int j = 0; j < n; j++) {
			char c = row[j];
			if (c != '?')
				continue;

			ans = 'A';
			for (int y = 0; y < 3; y++)
				for (int x = 0; x < n; x++)
					if (row[x] == ans)
						ans++;
		}
	}

	printf("%c\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
