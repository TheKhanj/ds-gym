typedef struct ctx_t {
	int *arr;
	int target;
} ctx_t;

int check(void *ctx, int mid) {
	ctx_t *d = (ctx_t *)ctx;
	return d->arr[mid] <= d->target;
}

typedef int (*check_fn)(void *ctx, int mid);

int bs(int l, int r, check_fn check, void *ctx) {
	if (l == r - 1)
		return l;
	int mid = (l + r) / 2;
	if (check(ctx, mid))
		return bs(mid, r, check, ctx);
	return bs(l, mid, check, ctx);
}

int searchInsert(int *arr, int n, int target) {
	ctx_t d = {.arr = arr, .target = target};
	if (target < arr[0])
		return 0;
	int index = bs(0, n, check, &d);
	if (arr[index] == target)
		return index;
	return index + 1;
}
