#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dist;
queue<int> Q;

struct graph {
    vector<vector<int>> edges;
    vector<int> isPassed ;
} G;

int BFS() {
    dist[0] = 0;
    Q.push(0);

    while(!Q.empty()) {
        G.isPassed[Q.front()] = 1;

        for (int u: G.edges[Q.front()]) {
            if (!G.isPassed[u]) {
                if (dist[u] == -1) {
                    dist[u] = dist[Q.front()] + 1;
                }
                Q.push(u);
            }
        }

        Q.pop();
    }

}

int main() {

    freopen("pathbge1.in", "r", stdin);
    freopen("pathbge1.out", "w", stdout);


    int n, m, a, b;
    cin >> n >> m;

    dist.resize(n, -1);

    G.edges.resize(n);
    G.isPassed.resize(n);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        G.edges[a - 1].push_back(b - 1);
        G.edges[b - 1].push_back(a - 1);
    }

    BFS();

    for (int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }

    return 0;
}
