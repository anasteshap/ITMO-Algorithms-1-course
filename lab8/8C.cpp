#include <iostream>
#include <vector>

using namespace std;

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> adjacencyMatrix (n, vector<int> (n, 0));

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adjacencyMatrix[a - 1][b - 1]++;
        adjacencyMatrix[b - 1][a - 1]++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adjacencyMatrix[i][j] > 1) {
                cout << "YES";
                exit(0);
            }
        }
    }

    cout << "NO";
    return 0;
}
