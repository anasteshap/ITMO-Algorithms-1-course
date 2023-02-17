#include <iostream>
#include <vector>

using namespace std;

int main() {

    freopen("knapsack.in", "r", stdin);
    freopen("knapsack.out", "w", stdout);

    int sum, n;
    cin >> sum >> n;

    vector<vector<int>> a(n + 1, vector<int>(sum + 1, 0)); // таблица
    vector<int> w(n + 1);

    for (int i = 1; i < n + 1; ++i) {
        cin >> w[i];
    }

    for (int k = 1; k < n + 1; ++k) { // с k = 1, тк если предметов ноль, то и вместимость ноль
        for (int s = 0; s < sum + 1; ++s) {
            if (s >= w[k])
                a[k][s] = max(a[k - 1][s], a[k - 1][s - w[k]] + w[k]);
            else
                a[k][s] = a[k - 1][s];
        }
    }
    cout << a[n][sum] << '\n';

    return 0;
}