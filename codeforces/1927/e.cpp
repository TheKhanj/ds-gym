#include <set>
#include <stdio.h>

void test() {
	int n, k;
	scanf("%d %d", &n, &k);
	std::set<int> st;
	int arr[n];
	for (int i = 0; i < n; i++)
		st.insert(i + 1);

	for (int i = 0; i < k; i++) {
		if (i % 2 == 0) {
			for (int j = i; j < n; j += k) {
				auto it = st.begin();
				arr[j] = *it;
				st.erase(it);
			}
		}
	}

	for (int i = k - 1; i >= 0; i--) {
		if (i % 2 == 1) {
			for (int j = i; j < n; j += k) {
				auto it = --st.end();
				arr[j] = *it;
				st.erase(it);
			}
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		test();
}
