#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
const int INF = 1e9;

struct edge{
    int from, to, weight;
};

struct graph {
    explicit graph(const int& n) : edges(n), p(n, -1), dist(n, INF) {}
    std::vector<edge> edges;
    std::vector<int> p;
    std::vector<int> dist;
};

void algo(graph &g, const int& n) {
    g.dist[0] = 0;

    int x;
    for (int k = 0; k < n; ++k) {
        x = -1;
        for (const auto &e: g.edges) {
            auto new_dist = g.dist[e.from] + e.weight;
            if (new_dist < g.dist[e.to]) {
                g.dist[e.to] = std::max(-INF, new_dist);
                g.p[e.to] = e.from;
                x = e.to;
            }
        }
    }

    if (x == -1)
        cout << "NO\n";
    else {
        std::vector<int> cycle;

        for (int i = 0; i < n; ++i) { x = g.p[x]; }

        for (int cur = x;; cur = g.p[cur]) {
            cycle.emplace(cycle.cbegin(), cur);
            if (cur == x && cycle.size() > 1) { break; }
        }

        cout << "YES\n" << cycle.size() << '\n';
        for (int v : cycle) {
            cout << v + 1 << ' ';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, a;
    cin >> n;

    graph g(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a;
            g.edges.push_back({i, j, a});
        }
    }
    algo(g, n);

    return 0;
}