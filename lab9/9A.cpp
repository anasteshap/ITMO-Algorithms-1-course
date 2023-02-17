#include <iostream>
#include <vector>
#include <stack>

using namespace std;

stack<int> blackVertex;

struct graph {
    vector<vector<int>> edges;
    vector<string> color;
} G;

void visit(int u) {
    G.color[u] = "gray";

    //cout << u + 1 << " ";
    for (int v : G.edges[u]) {
        if (G.color[v] == "gray") { // проверка на наличие цикла
            cout << -1;
            exit(0);
        }
        if (G.color[v] == "white")
            visit(v);
    }

    G.color[u] = "black";
    blackVertex.push(u);
}

void DFS(int n) {

    for (int i = 0; i < n; i++) {
        //cout << endl << G.color[i] << " " << i + 1  <<"_________________" << endl;
        if (G.color[i] == "white") {
            visit(i);
        }
    }
}

int main() {

    freopen("topsort.in", "r", stdin);
    freopen("topsort.out", "w", stdout);

    int n, m, a, b;
    cin >> n >> m;

    //graph G;
    G.edges.resize(n);
    G.color.resize(n, "white");

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        G.edges[a - 1].push_back(b - 1);
    }

//    for (int i = 0; i < n; i++) {
//        for (int it : G.edges[i]) {
//            cout << it  + 1 << " ";
//        }
//        cout << endl;
//    }
//    cout << endl << endl;

    DFS(n);

    for (int i = 0; i < n; i++) {
        cout << blackVertex.top() + 1 << " ";
        blackVertex.pop();
    }

    return 0;
}
