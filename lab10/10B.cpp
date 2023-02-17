#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int INF = INT_MAX;

struct point {
    int x, y;
};

struct graph {
    explicit graph(const size_t &n) : vertexes(n), in_ostov(n, false), min_edge(n, INF) {}

    vector<point> vertexes;
    vector<bool> in_ostov;
    vector<double> min_edge;
};

double dist_between_points(const point &a, const point &b) {
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

void print_weight_of_MST(const vector<double> &min_edge) {
    double weight_of_mst = 0;
    for (double dist : min_edge)
        weight_of_mst += dist;
    cout << weight_of_mst << '\n';
}

void prima(graph &G) {
    G.min_edge[0] = 0;
    for (int i = 0; i < G.vertexes.size(); ++i) {
        int v = -1;

        for (int u = 0; u < G.vertexes.size(); ++u) {
            if (!G.in_ostov[u] && (v == -1 || G.min_edge[u] < G.min_edge[v]))
                v = u;
        }
        G.in_ostov[v] = true;

        // пересчет мин ребра
        for (int to = 0; to < G.vertexes.size(); ++to) {
            double dist = dist_between_points(G.vertexes[v], G.vertexes[to]);
            if (to != v) {
                if (!G.in_ostov[to] && dist < G.min_edge[to])
                    G.min_edge[to] = dist;
            }
        }
    }
    print_weight_of_MST(G.min_edge);
}


int main() {

    freopen("spantree.in", "r", stdin);
    freopen("spantree.out", "w", stdout);

    int n;
    cin >> n;
    graph G(n);

    for (auto &v : G.vertexes) {
        cin >> v.x >> v.y;
    }
    cout.precision(20);
    prima(G);

    return 0;
}
