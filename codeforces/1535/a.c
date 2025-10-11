#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

int get_group(int *arr, int n, int val) {
	for (int i = 0; i < n; i++)
		if (arr[i] == val)
			return i / 2;

	assert(false && "unreachable code");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int arr[4];
		scanf("%d %d %d %d", arr, arr + 1, arr + 2, arr + 3);
		int finalists[2] = {0, 0};
		for (int i = 0; i < 4; i++) {
			if (arr[i] > finalists[1]) {
				finalists[0] = finalists[1];
				finalists[1] = arr[i];
			} else if (arr[i] > finalists[0]) {
				finalists[0] = arr[i];
			}
		}

		printf("%s\n",
					 get_group(arr, 4, finalists[0]) == get_group(arr, 4, finalists[1])
							 ? "NO"
							 : "YES");
	}
}
