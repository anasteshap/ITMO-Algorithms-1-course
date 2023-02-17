#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("knight2.in", "r", stdin);
    freopen("knight2.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    n += 2;
    m += 2;

    vector<vector<int>> dp (n + 1, vector<int>(m + 1, 0));
    dp[2][2] = 1;

    for (int x = 2, y = 2; x < n - 1 || y < m;) {
        int i = x, j = y;
        while (i >= 2 && j < m) { // проход по диагоналям ( / )
            // в (i, j) можно прийти из 4-х клеток: (i−2, j−1), (i−2, j+1), (i−1, j−2), (i+1, j−2)
            dp[i][j] += dp[i - 2][j - 1] + dp[i - 2][j + 1] + dp[i - 1][j - 2] + dp[i + 1][j - 2];
            i--, j++;
        }
        x == n - 1 ? y++ : x++;
    }

    cout << dp[n - 1][m - 1];
    return 0;
}
