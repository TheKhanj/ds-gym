#include <stdio.h>
#include <stdlib.h>

#define MAX(x, y) x > y ? x : y;

int compare(const void *_x, const void *_y) {
	return (*(int *)_y - *(int *)_x);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		char s[4];
		scanf("%s", (char *)&s);

		int count[10];
		for (int i = 0; i < 10; i++) {
			count[i] = 0;
		}

		for (int i = 0; i < 4; i++) {
			int index = s[i] - '0';
			count[index]++;
		}

		qsort(count, sizeof(count) / sizeof(int), sizeof(int), compare);

		int m = count[0];
		if (m == 4) {
			printf("-1\n");
			continue;
		}

		if (m == 3) {
			printf("6\n");
			continue;
		}

		printf("4\n");
	}
}
