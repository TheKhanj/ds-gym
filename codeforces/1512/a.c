#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int switches_count = 0;
		int switch_pos;

		int last = -1;
		for (int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);

			if (last != -1 && last != x) {
				if (switches_count == 0) {
					switch_pos = i;
				}

				switches_count++;
			}

			last = x;
		}

		int ans = switch_pos;
		if (switches_count == 1 && ans == 1) {
			ans--;
		}

		printf("%d\n", ans + 1);
	}
}
