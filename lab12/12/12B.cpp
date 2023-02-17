#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
ll INF = 10e11;

vector<ll> findLIS(vector<ll> arr, ll n) {
    vector<ll> d(n + 1, INF); // число, на которое оканчивается ВП длины i, а если таких чисел несколько — то наименьшее из них
    d[0] = -INF;

    vector<ll> pos(n + 1); // индексы элементов, на которые заканчиваются оптимальные подпоследовательности длины i
    vector<ll> prev(n);

    ll length = 0;
    pos[0] = -1;
    prev[0] = -1;

    for (ll i = 0; i < n; ++i) {
        ll j = upper_bound (d.begin(), d.end(), arr[i]) - d.begin();

        if (arr[i] < d[j]) {
            d[j] = arr[i];
            pos[j] = i;
            prev[i] = pos[j - 1];

            length = max(length, j);
        }
    }

    vector<ll> ans;
    ll p = pos[length];
    while (p != -1) {
        ans.push_back(arr[p]);
        p = prev[p];
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {

    ll n;
    cin >> n;
    vector<ll> arr(n);

    for (ll i = 0; i < n; ++i)
        cin >> arr[i];

    vector<ll> ans = findLIS(arr, n);

    cout << ans.size() << endl;
    for (const ll &i : ans)
        cout << i << ' ';

    return 0;
}