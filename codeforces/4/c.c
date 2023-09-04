#include <stddef.h>
#define __USE_MINGW_ANSI_STDIO 0

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000
#define BUFF_SIZE 1000

typedef struct my_set_data_t {
	int count;
	char *str;
} my_set_data_t;

typedef void *set_data_t;
typedef int (*set_data_cmp)(set_data_t, set_data_t);

int my_set_cmp(set_data_t a, set_data_t b) {
	my_set_data_t *d1 = a;
	my_set_data_t *d2 = b;

	return strcmp(d1->str, d2->str);
}

typedef struct set_t {
	int data_size;

	set_data_t arr[MAX_N];
	int arr_size;

	set_data_t buff[BUFF_SIZE];
	int buff_size;

	set_data_cmp cmp;
	__compar_fn_t cmp2;
} set_t;

void set_init(set_t *set, set_data_cmp cmp, int data_size) {
	set->arr_size = 0;
	set->buff_size = 0;
	set->cmp = cmp;
	set->data_size = data_size;
}

typedef struct binary_search_t binary_search_t;
typedef bool (*binary_search_check)(binary_search_t *, int pos);

struct binary_search_t {
	void *obj;
	void *looking;
	int l, r;
	binary_search_check check;
};

int binary_search_run(binary_search_t *bs) {
	int mid = (bs->l + bs->r) / 2;
	if (bs->l == bs->r - 1) {
		return bs->l;
	}

	if (bs->check(bs, mid)) {
		bs->l = mid;
	} else {
		bs->r = mid;
	}

	return binary_search_run(bs);
}

void binary_search_init(binary_search_t *bs, binary_search_check check, int l,
												int r, void *looking, void *obj) {
	bs->check = check;
	bs->l = l;
	bs->r = r;
	bs->looking = looking;
	bs->obj = obj;
}

bool my_bs_check(binary_search_t *bs, int pos) {
	set_t const *set = bs->obj;
	return set->cmp(bs->looking, set->arr[pos]) >= 0;
}

set_data_t set_find(set_t *set, set_data_t looking) {
	if (set->arr_size > 0) {
		binary_search_t bs;
		binary_search_init(&bs, my_bs_check, 0, set->arr_size, looking, set);
		const int pos = binary_search_run(&bs);

		set_data_t found = set->arr[pos];
		if (set->cmp(looking, found) == 0) {
			return found;
		}
	}

	for (int i = 0; i < set->buff_size; ++i) {
		set_data_t data = set->buff;
		if (set->cmp(looking, data) == 0) {
			return data;
		}
	}

	return NULL;
}

int my_set_cmp2(const void *a, const void *b) {
	my_set_data_t *const *d1 = a;
	my_set_data_t *const *d2 = b;

	return strcmp((*d1)->str, (*d2)->str);
}

void set_debug(set_t *set) {
	printf("debug:\n");
	for(int i=0;i<set->arr_size;i++) {
		my_set_data_t *foo = set->arr[i];
		printf("%s\n", foo->str);
	}
	printf("----\n");
}

static void set_sort_arr(set_t *set) {
	qsort(set->arr, (size_t)set->arr_size, sizeof(void *), my_set_cmp2);
}

static void set_unbuffer(set_t *set) {
	for (int i = 0; i < set->buff_size; i++) {
		set->arr[set->arr_size++] = set->buff[i];
	}

	set->buff_size = 0;
	set_sort_arr(set);
}

void set_insert(set_t *set, set_data_t data) {
	set->buff[set->buff_size++] = data;

	if (set->buff_size >= BUFF_SIZE) {
		set_unbuffer(set);
	}
}

int main() {
	int n;
	scanf("%d", &n);

	char s[n][40];
	my_set_data_t lookings[n];
	set_t set;
	set_init(&set, my_set_cmp, sizeof(my_set_data_t));

	for (int i = 0; i < n; i++) {
		char *str = s[i];
		scanf("%s", str);

		my_set_data_t *looking = lookings + i;
		looking->count = 1;
		looking->str = str;

		my_set_data_t *found = set_find(&set, looking);

		if (found == NULL) {
			printf("OK\n");
			// clone data
			set_insert(&set, looking);
		} else {
			printf("%s%d\n", str, found->count);
			found->count++;
		}
	}
}
