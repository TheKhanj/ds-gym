#include <stdbool.h>
#include <stdio.h>

void solve() {
	long long arr[3];
	for (int i = 0; i < 3; i++)
		scanf("%lld", arr + i);

	bool possimpble = false;
	for (int i = 0; i < 3; i++) {
		int j = i == 0 ? 1 : 0;
		int k = i == 2 ? 1 : 2;
		long long step = arr[k] - arr[j];
		if (k - j == 2) {
			if (step % 2 != 0)
				continue;
			step /= 2;
		}

		long long supposed = i == 0		? arr[j] - step
												 : i == 1 ? arr[j] + step
																	: arr[k] + step;
		if (supposed % arr[i] == 0 && supposed / arr[i] > 0)
			possimpble = true;
	}

	printf("%s\n", possimpble ? "YES" : "NO");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
