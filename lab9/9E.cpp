#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum color {
    white,
    gray,
    black
};

struct graph {
    vector<vector<int>> edges;
    vector<int> color;
    vector<int> topsort;
//    vector<int> c;           // номер хода, на котором посещается вершина (размер вектора = n)
};

void visit(graph &G, int u) {
    G.color[u] = gray;

    for (auto v: G.edges[u]) {
        if (G.color[v] == white) {
            visit(G,v);
        }
    }
    G.color[u] = black;
    G.topsort.emplace(G.topsort.cbegin(), u);
}

void DFS(graph &G, int n) {

    G.color.resize(n, 0);
    for (int i = 0; i < n; i++) {
        if (G.color[i] == white) {
            visit(G,i);
        }
    }

    for (int i = 0; i < n - 1; i++) {
        if (find(G.edges[G.topsort[i]].begin(), G.edges[G.topsort[i]].end(), G.topsort[i + 1]) == G.edges[G.topsort[i]].end()) {
            cout << "NO\n";
            exit(0);
        }
    }
}

int main() {

    freopen("hamiltonian.in", "r", stdin);
    freopen("hamiltonian.out", "w", stdout);

    int n, m, a, b;
    cin >> n >> m;

    graph G;
    G.edges.resize(n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        G.edges[a - 1].push_back(b - 1);

    }

    DFS(G, n);
    cout << "YES\n";

    return 0;
}
