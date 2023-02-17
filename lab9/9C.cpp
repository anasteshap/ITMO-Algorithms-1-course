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
    vector<int> visited;
    vector<int> bipartite; // вектор цветов для вершин из двух долей
};

void visit(graph &G, int u, int part, int& len) {
    G.visited[u] = gray;
    G.bipartite[u] = part;

    for (const int &v : G.edges[u]) {
        if (G.bipartite[v] == part || (len % 2 == 0 && G.visited[v] == gray && G.bipartite[v] == part)) { // если смежная вершина - из той же доли
            cout << "NO\n";
            exit(0);

        } else if (G.visited[v] == white) { // если она не посещена
            len++;
            visit(G, v, -part, len);
        }
    }

    G.visited[u] = black;
}

void DFS(graph &G, int n) {

    for (int i = 0; i < n; i++) {
        if (G.visited[i] == white) {
            int len = 0;
            visit(G, i, 1, len);
        }
    }
}

int main() {

    freopen("bipartite.in", "r", stdin);
    freopen("bipartite.out", "w", stdout);

    int n, m, a, b;
    cin >> n >> m;

    if (n == 1 || !n) {
        cout << "NO";
        return 0;
    }

    graph G;
    G.edges.resize(n);
    G.visited.resize(n, white);
    G.bipartite.resize(n);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        G.edges[a - 1].push_back(b - 1);
        G.edges[b - 1].push_back(a - 1);
    }

    DFS(G, n);
    cout << "YES";

    return 0;
}

// условия:
// цикл четной длины
// смежные вершины окрашены в другой цвет (если пройдены)
// если не пройдены -> окрасить в другой цвет