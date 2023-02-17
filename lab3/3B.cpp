#include <iostream>
#include <vector>

using namespace std;

int n;

void siftUp(vector<int>& arr, int i) {
    while (arr[i] > arr[(i - 1) / 2]) {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void siftDown(vector<int>& arr, int i, int last) { // last - элемент,  который последний был изменен
    while (2 * i + 1 < last) {                 // после swap(arr[0], arr[last]);

        int left = 2 * i + 1;          // left — левый сын
        int right = 2 * i + 2;

        int temp = left;  // потенциально наибольший из двух дочерних элементов

        if (arr[left] < arr[right] && right < last) {
            temp = right;
        }
        if (arr[i] >= arr[temp]) {
            break;
        }
        swap(arr[i], arr[temp]);
        i = temp;
    }
}

int main() {

    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);

    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) { // создание кучи
        cin >> arr[i];
        siftUp(arr, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[i], arr[0]);
        siftDown(arr, 0, i);
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
