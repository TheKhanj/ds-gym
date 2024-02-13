#include <cstdlib>
#include <set>
#include <stdbool.h>
#include <stdio.h>

class node_t {
public:
	bool visited = false;

	std::set<node_t *> adj;

	void connect(node_t *b) { this->adj.insert(b); }
};

class tree_t {
public:
	int n;
	node_t *nodes;
	tree_t(int n) {
		this->n = n;
		this->nodes = new node_t[n];
	}

	void connect(int a, int b) {
		auto aa = this->get_node(a);
		auto bb = this->get_node(b);
		aa->connect(bb);
	}

	node_t *get_node(int i) { return this->nodes + i; }

	bool has_loop(node_t *n, std::set<node_t *> *path) {
		n->visited = true;
		path->insert(n);
		for (auto it = n->adj.begin(); it != n->adj.end(); it++) {
			auto v = *it;
			if (v->visited) {
				bool has_loop = path->count(v) != 0;
				if (has_loop)
					return true;
			} else if (this->has_loop(v, path))
				return true;
		}
		path->erase(n);
		return false;
	};
};

void test_case() {
	int n, k;
	scanf("%d %d", &n, &k);
	int arr[n];

	tree_t t(n);

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", arr + j);
			if (j > 1)
				t.connect(arr[j - 1] - 1, arr[j] - 1);
		}
	}

	bool has_loop = false;
	auto path = std::set<node_t *>();
	for (int i = 0; i < n; i++) {
		auto n = t.get_node(i);
		if (!n->visited && t.has_loop(n, &path))
			has_loop = true;
	}

	printf("%s\n", has_loop ? "NO" : "YES");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		test_case();
}
