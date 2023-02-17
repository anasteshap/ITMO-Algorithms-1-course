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


long long dijkstra(graph &g, int &n, long long start, long long finish) {
    g.dist.resize(n, INF);
    g.dist[start] = 0;

    // 1 элемент - расстояние, 2 элемент - вершина
    std::set<std::pair<long long, int>> min_edges; // временный set, чтобы хранить вершины, упорядоченно по их в расстояниям
    min_edges.insert(std::make_pair(0, start));

    while (!min_edges.empty()) {
        int min_v = min_edges.begin()->second; // берем номер вершины с мин ребром
        min_edges.erase(min_edges.begin());

        for (int i = 0; i < g.edges[min_v].size(); ++i) { // просмотр по смежным вершинам с вершиной min_v
            int to = g.edges[min_v][i].first; // берем первую смежную вершину
            long long len = g.edges[min_v][i].second;

            if (g.dist[min_v] + len < g.dist[to]) { // релаксация
                min_edges.erase(std::make_pair(g.dist[to], to)); // удаляем старую пару
                g.dist[to] = g.dist[min_v] + len;
                min_edges.insert(std::make_pair(g.dist[to], to)); // меняем ее на обновленную
            }
        }
    }

    return g.dist[finish] == LLONG_MAX ? -1 : g.dist[finish];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("pathmgep.in", "r", stdin);
    freopen("pathmgep.out", "w", stdout);

    int n;
    long long s, f, a;
    cin >> n >> s >> f;

    graph g;
    g.edges.resize(n, {});

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a;
            if (a > 0) {
                g.edges[i].emplace_back(std::make_pair(j, a));
            }
        }
    }

    cout << dijkstra(g, n, s - 1, f - 1);
    return 0;
}




/*
void relax(graph &g, int &v) {
    for (auto &edge : g.edges[v]) {
        if (g.dist[v] + edge.second < g.dist[edge.first]) { // если (расст до V + смежное с V ребро (v,u) < расст до u)
            g.dist[edge.first] = g.dist[v] + edge.second;
        }
    }
}
*/

/*
    for (const auto &v : g.edges[start]) {
        int min_v = -1;
        for (int i = 0; i < n; ++i) {
            if (!g.used[i] && (min_v == -1 || g.dist[v.first] < g.dist[min_v]))
                min_v = v.first;
        }
        cout << min_v << std::endl;

//        if (g.dist[min_v] == INF || min_v == finish) { break; }
        if (g.dist[min_v] == INF) { break; }
        g.used[min_v] = true;

        relax(g, min_v);
    }

*/