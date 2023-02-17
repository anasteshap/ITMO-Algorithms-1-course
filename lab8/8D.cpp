#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct graph {
    vector<vector<int>> edges;
    vector<int> isPassed ;
} G;

queue<int> tempQueue;
vector<int> components;
int countOfComponents = 0;

void BFS(int v) {
    tempQueue.push(v);
    countOfComponents++;

    while (!tempQueue.empty()) {

        G.isPassed[tempQueue.front()] = 1;
        components[tempQueue.front()] = countOfComponents;

        for (int u: G.edges[tempQueue.front()]) {
            if (!G.isPassed[u]) {
                tempQueue.push(u);
            }
        }

        tempQueue.pop();
    }
}

void howMuchComponents() {
    for (int i = 0; i < G.edges.size(); i++) {
        if (!G.isPassed[i]) {
            tempQueue.push(i);
            BFS(i);
        }
    }
}

int main() {

    freopen("components.in", "r", stdin);
    freopen("components.out", "w", stdout);

    // поиск в ширину

    int n, m, a, b;
    cin >> n >> m;

    G.edges.resize(n);
    G.isPassed.resize(n);
    components.resize(n);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        G.edges[a - 1].push_back(b - 1);
        G.edges[b - 1].push_back(a - 1);
    }

    howMuchComponents();

    cout << countOfComponents << '\n';
    for (int i = 0; i < n; i++) {
        cout << components[i] << " ";
    }

    return 0;
}