#include <iostream>
#include <vector>

using namespace std;

bool check = true;

void treeCheck(int fatherIndex, vector< vector <int> >& arr, int minLimit, int maxLimit) {

    int l_son = arr[fatherIndex - 1][1];
    int r_son = arr[fatherIndex - 1][2];
    int father_value = arr[fatherIndex - 1][0];

    if (father_value <= minLimit || father_value >= maxLimit) {
        check = false;
        return;
    }

    if (l_son != 0) {
        treeCheck(l_son, arr, minLimit, father_value);
    }

    if (r_son != 0) {
        treeCheck(r_son, arr, father_value, maxLimit);
    }
}

int main() {

//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);

    freopen("check.in", "r", stdin);
    freopen("check.out", "w", stdout);

    int n; // число вершин
    cin >> n;

    if (n == 0) {
        cout << "YES";
        return 0;
    }

    vector< vector <int> > arr(n, vector <int> (3));

    for (int i = 0; i < n; i++) {
            cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    treeCheck(1, arr, - 1000000000, 1000000000);

    if (check) {
        cout << "YES";
    }
    else
        cout << "NO";

    return 0;
}