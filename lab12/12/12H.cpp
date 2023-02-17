#include <iostream>
#include <vector>

using namespace std;

const int mod = 1000000000;

int main() {

    int n;
    cin >> n;

    if (n == 1) {
        cout << 0;
        return 0;
    }

    vector<vector<int>> arr(n, vector<int>(n, 0));
    vector<int> color(n, 0);

    for (int i = 0; i < n; ++i)
        cin >> color[i];

    for (int i = 0; i < n; ++i)
        arr[i][i] = 1;

    for (int k = 1; k < n; ++k) // подстрока из [2, 3, ... n] эл-тов (k = 1, 2, ... n - 1)
        for (int i = 0; i + k < n; ++i) {
            int j = i + k;

            if (color[i] != color[j])
                arr[i][j] = (arr[i + 1][j] % mod + arr[i][j - 1] % mod - arr[i + 1][j - 1] % mod) % mod;
            else
                arr[i][j] = (arr[i + 1][j] % mod + arr[i][j - 1] % mod + 1) % mod;
        }

    cout << (arr[0][n - 1] + mod) % mod;
    return 0;
}