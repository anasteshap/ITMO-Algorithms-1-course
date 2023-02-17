#include <iostream>
#include <vector>
using namespace std;

enum color {
    white,
    gray,
    black
};

struct graph {
    vector<vector<int>> edges;
    vector<vector<int>> invertedEdges;
    vector<int> color;
    vector<int> components;
    vector<int> topsort;
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

void findComponents(graph &G,int u, int numOFComp) {
    G.color[u] = gray;
    G.components[u] = numOFComp;

    for (auto v: G.invertedEdges[u]) {
        if (G.color[v] == white) {
            findComponents(G,v, numOFComp);
        }
    }
    G.color[u] = black;
}

int DFS(graph &G, int n, int numOFComp) {

    G.color.resize(n, 0);
    for (int i = 0; i < n; i++) {
        if (G.color[i] == white) {
            visit(G,i);
        }
    }

    G.color.clear();
    G.color.resize(n, 0);

    for (int i = 0; i < n; ++i) {
        int v = G.topsort[i];
        if (G.color[v] == white) {
            ++numOFComp;
            findComponents(G,v, numOFComp);
        }
    }
    return numOFComp;
}

int main() {

    freopen("cond.in", "r", stdin);
    freopen("cond.out", "w", stdout);

    int n, m, a, b;
    cin >> n >> m;

    graph G;
    G.edges.resize(n);
    G.invertedEdges.resize(n);
    G.topsort.resize(n);
    G.components.resize(n);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        G.edges[a - 1].push_back(b - 1);
        G.invertedEdges[b - 1].push_back(a - 1);
    }

    cout << DFS(G,n, 0) << "\n";
    if (DFS(G,n, 0)) {
        for (int i = 0; i < n; ++i) {
            cout << G.components[i] << " ";
        }
    }

    return 0;
}
