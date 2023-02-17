#include <iostream>
#include <vector>

using namespace std;

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m, a, b;

    cin >> n >> m;
    vector<vector<int>> adjacencyMatrix(n, vector<int> (n, 0));

    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        adjacencyMatrix[a - 1][b - 1] = 1;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


