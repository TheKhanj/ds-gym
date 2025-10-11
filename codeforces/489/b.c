#include <stdio.h>
#include <stdlib.h>

#define ABS(a) ((a) > 0 ? (a) : -(a))

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main() {
	int n;
	scanf("%d", &n);
	int boys[n];
	for (int i = 0; i < n; i++)
		scanf("%d", boys + i);
	int m;
	scanf("%d", &m);
	int girls[m];
	for (int i = 0; i < m; i++)
		scanf("%d", girls + i);

	qsort(boys, n, sizeof(boys[0]), cmp);
	qsort(girls, m, sizeof(girls[0]), cmp);

	int *boy = boys, *girl = girls;
	int ans = 0;

#define NOT_END (boy != boys + n && girl != girls + m)
#define MATCH (ABS(*boy - *girl) <= 1)

	while (NOT_END) {
		while (NOT_END && !MATCH) {
			if (*girl > *boy)
				boy++;
			else
				girl++;
		}
		if (NOT_END && MATCH) {
			ans++;
			boy++;
			girl++;
		}
	}

	printf("%d\n", ans);
}
