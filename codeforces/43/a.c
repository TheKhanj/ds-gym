#include <stdio.h>
#include <string.h>

int main() {
	int t;
	scanf("%d", &t);

	char s[11];
	int teams_count = 0;
	char teams[2][11];
	int count = 0;

	while (t--) {
		scanf("%s", s);
		if (teams_count == 0) {
			strcpy(teams[teams_count++], s);
		}

		if (strcmp(s, teams[0]) == 0)
			count++;
		else {
			if (teams_count == 1) {
				strcpy(teams[teams_count++], s);
			}
			count--;
		}
	}

	printf("%s\n", count > 0 ? teams[0] : teams[1]);
}
