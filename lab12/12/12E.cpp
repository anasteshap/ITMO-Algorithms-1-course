#include <iostream>
#include <vector>

using namespace std;

struct graph {
    vector<vector<int>> g;
    vector<vector<int>> d;
};

void dfs(int v, graph &tree) {
    for (int u: tree.g[v])
        dfs(u, tree);

    for (int u: tree.g[v]) {
        tree.d[v][1] += tree.d[u][0]; // вершина v + дети вершины u
        tree.d[v][0] += max(tree.d[u][0], tree.d[u][1]); // максимум между (внуками для вершины v) / (вершиной u + внуками для вершины u)
    }
}

int main() {
    int n, parent, root;
    cin >> n;

    graph tree;
    tree.g.resize(n);
    tree.d.resize(n,{0, 1});

    for (int i = 0; i < n; ++i) {
        cin >> parent;
        if (!parent) {
            root = i;
        }
        else {
            tree.g[parent - 1].push_back(i);
        }
    }

    dfs(root, tree);
    cout << max(tree.d[root][0], tree.d[root][1]);
    return 0;
}