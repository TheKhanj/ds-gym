#include <stdbool.h>
#include <stdio.h>

int get_uniq(int *arr, int n) {
	int count = 0;
	for (int i = 0; i < n;) {
		count++;
		int c = arr[i];
		while (i < n && arr[i] == c)
			i++;
	}
	return count;
}

void solve() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);

	bool ret[n];
	int uniq = get_uniq(arr, n);
	if (uniq == 1) {
		printf("NO\n");
		return;
	}

	printf("YES\n");

	if (uniq == 2) {
		int i = 0;
		while (i < n && arr[i] == arr[0])
			i++;
		if (i == 1) {
			ret[0] = false;
			ret[1] = false;
			for (int x = 2; x < n; x++)
				ret[x] = true;
		} else {
			ret[0] = false;
			for (int x = 1; x < n; x++)
				ret[x] = true;
		}
	} else {
		ret[0] = false;
		for (int x = 1; x < n; x++)
			ret[x] = true;
	}

	for (int i = 0; i < n; i++)
		printf("%c", ret[i] ? 'R' : 'B');
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
