#include <iostream>
#include <vector>

using namespace std;

struct node {
    int value;
    vector<int> vertexes{};
};

struct tree {
    vector<node> g;
    vector<vector<int>> d;
};

void dfs(tree& tree, int v) {
    tree.d[v][0] = 0;
    tree.d[v][1] = tree.g[v].value;

    for (int u : tree.g[v].vertexes) // проход по детям из узла v
        dfs(tree, u);

    for (int u : tree.g[v].vertexes) {
        tree.d[v][1] += tree.d[u][0];
        tree.d[v][0] += max(tree.d[u][0], tree.d[u][1]);
    }
}

int main() {
    freopen("selectw.in", "r", stdin);
    freopen("selectw.out", "w", stdout);

    int n, parent, value;
    cin >> n;

    tree tree;
    tree.g.resize(n);
    tree.d.resize(n, vector<int>(2));

    int root;
    for (int i = 0; i < n; ++i) {
        cin >> parent >> value;
        if (!parent) {
            root = i;
        } else {
            tree.g[parent - 1].vertexes.push_back(i); // добавляем детей
        }
        tree.g[i].value = value;
    }

    dfs(tree, root);
    cout << max(tree.d[root][0], tree.d[root][1]);

    return 0;
}
