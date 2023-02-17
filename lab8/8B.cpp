#include <iostream>
#include <vector>

using namespace std;

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<vector<int>> adjacencyMatrix (n, vector<int> (n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adjacencyMatrix[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        if (adjacencyMatrix[i][i]) {
            cout << "NO";
            exit(0);
        }

        for (int j = 0; j < n; j++) {
            if (adjacencyMatrix[i][j] != adjacencyMatrix[j][i]) {
                cout << "NO";
                exit(0);
            }
        }
    }

    cout << "YES";
    return 0;
}
