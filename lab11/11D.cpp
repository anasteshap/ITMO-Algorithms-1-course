#include <iostream>
#include <vector>
#include <limits>

const long long INF = std::numeric_limits<long long>::max();

struct edge {
    int to;
    long long len;
};

struct graph {
    explicit graph(const int& n) : edges(n), used(n) {}
    std::vector<std::vector<edge>> edges;
    std::vector<bool> used;
};

void dfs(graph& g, const int& v) {
    g.used[v] = true;
    for (const edge& e: g.edges[v]) {
        if (!g.used[e.to])
            dfs(g, e.to);
    }
}

void bellmanFord(graph& g, const int& n, const int& start) {
    std::vector<long long> dist(n, INF);
    dist[start] = 0;

    for (int k = 0; k < n; ++k) { // количество итераций
        for (int from = 0; from < n; ++from) { // для каждой вершин
            for (const edge& e: g.edges[from]) { // смотрим смежные
                int to = e.to;

                if (dist[from] < INF) {
                    if (!g.used[to] && (dist[from] + e.len < dist[to])) {
                        if (k == n - 1) {
                            dfs(g, to);
                        } else {
                            dist[to] = std::max(-INF, dist[from] + e.len);
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF)
            std::cout << "*\n";
        else if (g.used[i] || dist[i] < -5e18) // расстояние до вершины уменьшилось (меньше чем (-long long / 2))
            std::cout << "-\n";
        else
            std::cout << dist[i] << '\n';
    }
}

int main()
{
    freopen("path.in", "r", stdin);
    freopen("path.out", "w", stdout);

    int n, m, s, from, to;
    long long len;

    std::cin >> n >> m >> s;
    graph g(n);

    for (int i = 0; i < m; ++i) {
        std::cin >> from >> to >> len;
        g.edges[from - 1].push_back({to - 1, len});
    }

    bellmanFord(g, n, s - 1);
    return 0;
}