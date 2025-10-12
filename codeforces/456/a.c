#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int price;
	int value;
} product_t;

int check_hypothesis(product_t *arr, int n) {
	for (int i = 1; i < n; i++)
		if (arr[i].value < arr[i - 1].value)
			return 1;
	return 0;
}

int cmp(const void *a, const void *b) {
	const product_t *x = (product_t *)a, *y = (product_t *)b;
	if (x->price == y->price)
		return x->value - y->value;
	return x->price - y->price;
}

int main() {
	int n;
	scanf("%d", &n);
	product_t arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d %d", &arr[i].price, &arr[i].value);
	qsort(arr, n, sizeof(arr[0]), cmp);
	printf("%s\n", check_hypothesis(arr, n) ? "Happy Alex" : "Poor Alex");
}
