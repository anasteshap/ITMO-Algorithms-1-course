#include <iostream>
#include <vector>

using namespace std;

struct Graph {
    vector<vector<int>> g;
    vector<int> visited;
    vector<int> visitedAll;
    vector<int> matching;
};

bool kuhn(Graph &graph, int v) {

    if (graph.visited[v])
        return false;
    graph.visited[v] = true;

    for (int to : graph.g[v]) {
        if (graph.matching[to] == -1 || kuhn(graph, graph.matching[to])) {
            graph.matching[to] = v;
            return true;
        }
    }
    return false;
}

int main() {

    freopen("matching.in", "r", stdin);
    freopen("matching.out", "w", stdout);

    int n, m, k, a, b;
    cin >> n >> m >> k;

    Graph graph;
    graph.g.resize(n, {});
    graph.matching.resize(m, -1); //содержит информацию о паросочетании
    graph.visited.resize(n, false);
    graph.visitedAll.resize(n, false);

    for (int i = 0; i < k; ++i) {
        cin >> a >> b;
        graph.g[--a].push_back(--b);
    }

    for (int i = 0; i < n; ++i) {
        for (int v : graph.g[i]) {
            if (graph.matching[v] == -1) {
                graph.matching[v] = i;
                graph.visitedAll[i] = true;
                break;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!graph.visitedAll[i]) {
            graph.visited.assign(n, false);
            kuhn(graph, i);
        }
    }

    int count = 0;
    for (int i = 0; i < m; ++i) {
        if (graph.matching[i] != -1)
            ++count;
    }

    cout << count;
    return 0;
}