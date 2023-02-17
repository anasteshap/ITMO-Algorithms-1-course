#include <iostream>
#include <vector>
#include <set>

using std::cin;
using std::cout;
using std::vector;

const long long INF = LLONG_MAX;

struct graph {
    vector<vector<std::pair<int, long long>>> edges;
    vector<long long> dist;
};


vector<long long> dijkstra(graph &g, int &n, long long start) {
    g.dist.clear();
    g.dist.resize(n, INF);
    g.dist[start] = 0;

    // 1 элемент - расстояние, 2 элемент - вершина
    std::set<std::pair<long long, int>> min_edges;
    min_edges.insert(std::make_pair(0, start));

    while (!min_edges.empty()) {
        int min_v = min_edges.begin()->second; // берем номер вершины с мин ребром
        min_edges.erase(min_edges.begin());

        for (int i = 0; i < g.edges[min_v].size(); ++i) { // просмотр по смежным вершинам с вершиной min_v
            int to = g.edges[min_v][i].first;
            long long len = g.edges[min_v][i].second;

            if (g.dist[min_v] + len < g.dist[to]) { // релаксация
                min_edges.erase(std::make_pair(g.dist[to], to));
                g.dist[to] = g.dist[min_v] + len;
                min_edges.insert(std::make_pair(g.dist[to], to));
            }
        }
    }

    return g.dist;
}

int main() {
    freopen("pathbgep.in", "r", stdin);
    freopen("pathbgep.out", "w", stdout);

    int n, m, a, b;
    long long c;
    cin >> n >> m;

    graph g;
    g.edges.resize(n, {});

    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        g.edges[a - 1].emplace_back(std::make_pair(b - 1, c));
        g.edges[b - 1].emplace_back(std::make_pair(a - 1, c));
    }

    for (const auto &d : dijkstra(g, n, 0)) {
        cout << d << ' ';
    }


    return 0;
}
