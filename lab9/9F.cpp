#include <iostream>
#include <vector>

using namespace std;

struct graph {
    vector<vector<int>> edges;
    vector<bool> isPassed;
    vector<bool> win_pos;
};

void DFS(graph &G, int u) {
    G.isPassed[u] = true;

    for (auto v: G.edges[u]) {
        if (!G.isPassed[v]) {
            DFS(G,v);
        }

        if (!G.win_pos[v])
            G.win_pos[u] = true;
    }

}

int main() {

    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);

    int n, m, a, b, first;
    cin >> n >> m >> first;

    graph G;
    G.edges.resize(n);
    G.win_pos.resize(n, false);
    G.isPassed.resize(n, false);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        G.edges[a - 1].push_back(b - 1);
    }

    DFS(G,first - 1);

    if (G.win_pos[first - 1]) {
        cout << "First player wins\n";
    }
    else {
        cout << "Second player wins\n";
    }

    return 0;
}