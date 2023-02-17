#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findLIS(vector<int> arr, int n) {
    vector<int> d(n);
    vector<int> prev(n);

    for (int i = 0; i < n; ++i) {
        d[i] = 1;
        prev[i] = -1;

        for (int j = 0; j < i; ++j)
            if (arr[j] < arr[i] && d[j] + 1 > d[i]) {
                d[i] = d[j] + 1;
                prev[i] = j;
            }
    }

    int pos = 0;
    int l = d[0];
    for (int i = 0; i < n; ++i)
        if (d[i] > l) {
            pos = i;
            l = d[i];
        }

    vector<int> ans;
    while(pos != -1) {
        ans.emplace(ans.begin(), arr[pos]);
        pos = prev[pos];
    }

    return ans;
}

int main() {

    int n, a;
    cin >> n;
    vector<int> arr;

    for (int i = 0; i < n; ++i) {
        cin >> a;
        arr.push_back(a);
    }

    vector<int> ans = findLIS(arr, n);

    cout << ans.size() << '\n';
    for (int i: ans)
        cout << i << " ";
    return 0;
}