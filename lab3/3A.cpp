#include <iostream>
#include <vector>

using namespace std;

int main() {

    freopen("isheap.in", "r", stdin);
    freopen("isheap.out", "w", stdout);

    vector<int> arr;
    int n, a;
    bool flag = true;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (2 * i + 1 < n) {
            if (arr[i] > arr[2 * i + 1]) {
                cout << "NO";
                flag = false;
                break;
            }
        }

        if (2 * i + 2 < n) {
            if (arr[i] > arr[2 * i + 2 ]) {
                cout << "NO";
                flag = false;
                break;
            }
        }
    }

    if (flag) {
        cout << "YES";
    }
    return 0;
}
