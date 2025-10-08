#include <assert.h>
#include <stdio.h>

int get_score(int i, int j) {
	if (i >= 5)
		i = 9 - i;
	if (j >= 5)
		j = 9 - j;

	if (i == 0 || j == 0)
		return 1;
	if (i == 1 || j == 1)
		return 2;
	if (i == 2 || j == 2)
		return 3;
	if (i == 3 || j == 3)
		return 4;
	if (i == 4 || j == 4)
		return 5;

	assert(0);
}

void solve() {
	char s[10][11];
	for (int i = 0; i < 10; i++)
		scanf("%s", s[i]);

	int score = 0;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (s[i][j] == 'X')
				score += get_score(i, j);
	printf("%d\n", score);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
