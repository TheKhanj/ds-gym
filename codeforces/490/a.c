#include <stdio.h>

#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef struct group_t {
	int programmer;
	int mathematician;
	int physicist;
} groupt_t;

void group_print(groupt_t *group) {
	printf("%d %d %d\n", group->programmer + 1, group->mathematician + 1,
				 group->physicist + 1);
}

int main() {
	int n;
	scanf("%d", &n);

	int count[3];
	for (int i = 0; i < 3; i++) {
		count[i] = 0;
	}

	groupt_t groups[n];

	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);

		const int type = --x;
		const int cnt = count[type];
		if (type == 0) {
			groups[cnt].programmer = i;
		} else if (type == 1) {
			groups[cnt].mathematician = i;
		} else {
			groups[cnt].physicist = i;
		}

		count[type]++;
	}

	const int min = MIN(count[0], MIN(count[1], count[2]));
	printf("%d\n", min);
	for (int i = 0; i < min; i++) {
		group_print(groups + i);
	}
}
