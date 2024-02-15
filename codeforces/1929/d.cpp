#include <stdio.h>
#include <vector>

long long mod = 998244353;

typedef struct node_t {
	std::vector<node_t *> adj;
	long long cached[3];
	node_t *parent = NULL;
	int index;

	node_t() {
		for (int i = 0; i < 3; i++)
			this->cached[i] = -1;
	}

	void connect(node_t *v) { this->adj.push_back(v); }

	long long dfs(node_t *parent, int count) {
		this->parent = parent;

		if (this->cached[count] >= 0)
			return this->cached[count];

		if (count == 0)
			return 1;
		if (count == 1) {
			long long sum = 1;

			for (int i = 0; i < this->adj.size(); i++) {
				node_t *v = this->adj[i];
				if (v == this->parent)
					continue;

				sum *= ((v->dfs(this, 0) + v->dfs(this, 1)) % mod);
				sum %= mod;
			}

			return this->cache(count, sum);
		}
		// count 2
		long long sum = 0;

		for (int i = 0; i < this->adj.size(); i++) {
			node_t *v = this->adj[i];
			if (v == this->parent)
				continue;

			sum += v->dfs(this, 2) + v->dfs(this, 1);
			sum %= mod;
		}

		return this->cache(count, sum);
	}

	long long cache(int count, long long ans) {
		// this->debug(count, ans);
		this->cached[count] = ans;
		return ans;
	}

	void debug(int count, int ans) {
		printf("debug i: %d, count: %d, ans: %d\n", this->index, count, ans);
	}
} node_t;

typedef struct tree_t {
	int n;
	node_t *nodes;

	tree_t(int n, node_t *nodes) {
		this->n = n;
		this->nodes = nodes;
		for (int i = 0; i < n; i++)
			nodes[i].index = i;
	}
} tree_t;

void test_case() {
	int n;
	scanf("%d", &n);

	node_t nodes[n];
	tree_t t(n, nodes);

	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--;
		v--;
		t.nodes[u].connect(t.nodes + v);
		t.nodes[v].connect(t.nodes + u);
	}

	node_t *root = t.nodes;
	long long ans = root->dfs(NULL, 0);
	// printf("test: %d\n", ans);
	ans += root->dfs(NULL, 1);
	// printf("test: %d\n", ans);
	ans += root->dfs(NULL, 2);
	ans %= mod;
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		test_case();
}
