#include <iostream>
#include <vector>

using namespace std;

int get_letter(string str, int i) {
    return (int)str[i];
}

void print_arr(vector<string>& arr, int n) {
    for (int j = 0; j < n; j++) {
            cout << arr[j] << endl;
    }
}

void radixSort(vector<string>& arr, int n, int m, int k) {
    int c[26];
    vector<string> res(n);

    for (int & j : c) {
        j = 0;
    }

    for (int j = 0; j < n; j++) {
        c[get_letter(arr[j], m - k) - 97]++; // 97 - код a
    }

    int count = 0;
    for (int & j : c) { //for (int j = 0; j < 26; j++)
        int temp = j;
        j = count;
        count += temp;
    }

    for (int j = 0; j < n; j++) {
        res[c[get_letter(arr[j], m - k) - 97]] = arr[j];
        c[get_letter(arr[j], m - k) - 97]++;
    }

    for(int j = 0; j < n; j++)
        arr[j] = res[j];
}

int main() {

    freopen("radixsort.in", "r", stdin);
    freopen("radixsort.out", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;
    vector<string> arr (n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= k; i++) {
        radixSort(arr, n, m, i);
    }

    print_arr(arr, n);

    return 0;
}