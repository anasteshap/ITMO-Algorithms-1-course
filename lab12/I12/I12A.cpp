#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int inf = INT_MAX;

struct Graph {
    vector<vector<int>> g;
    vector<bool> visited;
    vector<int> parent;
};

bool bfs(Graph &graph, int start, int finish, int n) {

    queue<int> q;
    q.push(start);

    for (int i = 0; i < n; ++i) {
        graph.visited[i] = false;
    }
    graph.visited[start] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int i = 0; i < n; ++i) {
            if (!graph.visited[i] && graph.g[v][i] > 0) {

//                if (i == finish) {
//                    graph.parent[i] = v;
//                    return true;
//                }

                graph.parent[i] = v;
                graph.visited[i] = true;
                q.push(i);
            }
        }
    }
    return graph.visited[finish];
//    return false;
}

int fordFulkerson(Graph &graph, int start, int finish, int n) {
    int max_flow = 0;

    while (bfs(graph, start, finish, n)) {
        int path_flow = inf;

        for (int i = finish; i != start; i = graph.parent[i]) {
            int prev = graph.parent[i];
            path_flow = min(path_flow, graph.g[prev][i]);
        }

        for (int i = finish; i != start; i = graph.parent[i]) {
            int prev = graph.parent[i];
            graph.g[i][prev] += path_flow;
            graph.g[prev][i] -= path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {

    freopen("maxflow.in", "r", stdin);
    freopen("maxflow.out", "w", stdout);

    int n, m, v1, v2, w;
    cin >> n >> m;

    Graph graph;
    graph.g.resize(n, vector<int> (n, 0));
    graph.parent.resize(n, -1);
    graph.visited.resize(n);

    for (int i = 0; i < m; ++i) {
        cin >> v1 >> v2 >> w;
        graph.g[v1 - 1][v2 - 1] = w;
    }

    cout << fordFulkerson(graph, 0, n - 1, n);
    return 0;
}
