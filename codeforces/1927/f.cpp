#include <cstdlib>
#include <set>
#include <stdio.h>
#include <vector>

#define MIN(a, b) (a) < (b) ? (a) : (b)

typedef struct edge_t {
	int w;
	struct node_t *u, *v;
} edge_t;

typedef struct node_t {
	int index;
	std::vector<edge_t *> adj;
	std::multiset<node_t *> *group;
	bool vis = false;

	node_t() {
		this->group = new std::multiset<node_t *>();
		this->group->insert(this);
	}

	bool dfs(edge_t *e, node_t *v, std::vector<edge_t *> *path) {
		// printf("debug: %d %d\n", this->index, v->index);
		this->vis = true;
		if (v == this) {
			printf("%d %d\n", e->w, (int)path->size() + 1);

			node_t *last = v;
			printf("%d ", last->index + 1);
			for (int i = path->size() - 1; i >= 0; i--) {
				edge_t *e = (*path)[i];
				last = e->u == last ? e->v : e->u;
				printf("%d ", last->index + 1);
			}
			printf("\n");
			return true;
		}
		for (int i = 0; i < this->adj.size(); i++) {
			edge_t *e2 = this->adj[i];
			if (e2 == e)
				continue;
			node_t *next = e2->u == this ? e2->v : e2->u;
			// printf("adj: %d %d\n", this->index, next->index);
			if (next->vis == true)
				continue;

			path->push_back(e2);
			if (next->dfs(e, v, path)) {
				return true;
			}
			path->pop_back();
		}
		// printf("COMES HERE %d\n", this->index);
		return false;
	}
} node_t;

struct compare {
	bool operator()(edge_t *lhs, edge_t *rhs) const { return lhs->w < rhs->w; }
};

void found_ans(edge_t *e) {
	std::vector<edge_t *> path1;
	e->u->dfs(e, e->v, &path1);
}

void test_case() {
	int n, m;
	scanf("%d %d", &n, &m);
	node_t nodes[n];
	edge_t edges[m];
	std::multiset<edge_t *, compare> st;

	for (int i = 0; i < n; i++)
		nodes[i].index = i;

	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		u--;
		v--;

		edge_t *e = edges + i;
		e->u = nodes + u;
		e->v = nodes + v;
		e->w = w;
		st.insert(e);
	}

	edge_t *candidate = NULL;
	while (st.size()) {
		auto it = --st.end();
		st.erase(it);
		auto e = *it;

		// printf("inserting adj: %d %d\n", e->u->index, e->v->index);
		e->u->adj.push_back(e);
		e->v->adj.push_back(e);

		if (e->u->group == e->v->group) {
			// printf("found ans %d %d\n", e->u->index, e->v->index);
			candidate = e;
			continue;
		}

		auto min = e->u->group->size() < e->v->group->size() ? e->u : e->v;
		auto max = e->u == min ? e->v : e->u;
		auto g = min->group;
		for (auto it2 = g->begin(); it2 != g->end(); ++it2) {
			(*it2)->group = max->group;
			max->group->insert(*it2);
		}
	}
	found_ans(candidate);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		test_case();
}
