#include <iostream>
#include <vector>
using namespace std;

bool cycleExists = false;

struct graph {
    vector<vector<int>> edges;
    vector<string> color;
    vector<int> parents;
    vector<int> cycle{}; // массив цикла
} G;

void visit(int u) {
    G.color[u] = "gray";

    for (auto v: G.edges[u]) {
        if (G.color[v] == "gray") { // проверка на наличие цикла
            G.parents[v] = u;

            if (!cycleExists) {
                for (int j = G.parents[v]; j != v;) {
                    G.cycle.emplace(G.cycle.cbegin(), j);
                    j = G.parents[j];
                }

                G.cycle.emplace(G.cycle.cbegin(), v);
                cycleExists = true;
                break;
            }

        }

        if (G.color[v] == "white") {
            G.parents[v] = u;
            visit(v);
        }
    }

    G.color[u] = "black";
}

void DFS(int n) {

    for (int i = 0; i < n; i++) {
        if (G.color[i] == "white") {
            visit(i);
        }

        if (cycleExists) {
            cout << "YES\n";
            for (int v : G.cycle) {
                cout << v + 1 << " ";
            }
            return;
        }
    }
}

int main() {

    freopen("cycle.in", "r", stdin);
    freopen("cycle.out", "w", stdout);

    int n, m, a, b;
    cin >> n >> m;

    G.edges.resize(n);
    G.color.resize(n, "white");
    G.cycle.resize(0);
    G.parents.resize(n,-1);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        G.edges[a - 1].push_back(b - 1);
    }

    DFS(n);

    if (!cycleExists) {
        cout << "NO\n";
    }

    return 0;
}


