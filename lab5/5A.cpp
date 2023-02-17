#include <iostream>
#include <vector>

using namespace std;

//struct node {
//    int key;
//    node* l_son;
//    node* parent;
//    node* r_son;
//};
//
//class BinTree {
//private:
//public:
//    void push(int K, int L, int R) {
//}
//};

int main() {
    freopen("height.in", "r", stdin);
    freopen("height.out", "w", stdout);

    int n; // число вершин
    cin >> n;

    if (n == 0) {
        cout << 0;
        return 0;
    }

    vector<int> arr(n, 1);
    int k, l, r;

    for (int i = 0; i < n; i++) {
        cin >> k >> l >> r;

        if (l != 0) {     // если есть левый сын
            arr[l-1] = arr[i] + 1;
        }
        if (r != 0) {
            arr[r-1] = arr[i] + 1;
        }
    }

    int height = 0;
    for (int i = 0; i < n; i++) {
        height = max(arr[i], height);
    }

    cout << height;

    return 0;
}
