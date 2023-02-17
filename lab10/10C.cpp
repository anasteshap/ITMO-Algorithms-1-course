#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
    int cost, v1, v2;
};

struct graph {
    explicit graph(const int& n, const int& m) {
        lengths.resize(m); color.resize(n); depth_of_tree.resize(n, 0);
    }
    vector<edge> lengths;
    vector<int> color;
    vector<int> depth_of_tree; // для присоединения дерева с меньшим кол-вом вершин к дереву с большим кол-вом
};

bool operator<(const edge& edge1, const edge& edge2) {
    return edge1.cost < edge2.cost;
}

int find_root(graph &G, int v) { // ищем корень дерева
    return v == G.color[v] ? v : (G.color[v] = find_root(G, G.color[v]));
}

void unions(graph &G, long long &sum, int index) {
    int from = find_root(G, G.lengths[index].v1);
    int to = find_root(G, G.lengths[index].v2);

    if (from != to) {
        sum += G.lengths[index].cost;
        if (G.depth_of_tree[from] < G.depth_of_tree[to])
            swap(from, to);

        G.color[to] = from; // to - мин дерево из этих двух
        G.depth_of_tree[from] += G.depth_of_tree[to];
//        if (G.depth_of_tree[from] == G.depth_of_tree[to])
//            ++G.depth_of_tree[from];
    }
}

void findMST(graph &G, int n, int m) {
    for (int i = 0; i < n; ++i) {
        G.color[i] = i;
    }
    sort(G.lengths.begin(), G.lengths.end());

    long long sum = 0;
    for (int i = 0; i < m; ++i) {
        unions(G, sum, i);
    }
    cout << sum;
}

int main() {

    int n, m, a, b, len;
    cin >> n >> m;

    graph G(n, m);
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> len;
        G.lengths[i] = edge{len, a - 1, b - 1};
    }

    findMST(G, n, m);
    return 0;
}