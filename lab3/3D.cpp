#include <iostream>
#include <vector>
using namespace std;

class QueueClass
{
private:
    vector<int> arr;
    unsigned len = 0; // длина очереди

    int l_son(int i) {
        return 2 * i + 1;
    }

    int r_son(int i) {
        return 2 * i + 2;
    }

    void siftUp(unsigned i) {
        if (i > 0 && arr[i] < arr[(i - 1) / 2]) {
            swap(arr[i], arr[(i - 1) / 2]);
            siftUp((i - 1) / 2);
        }
    }

    void siftDown(int i) {
        while (l_son(i) < len) {

            int left = l_son(i);          // left — левый сын
            int right = r_son(i);

            int temp = left;  // потенциально наибольший из двух дочерних элементов

            if (arr[left] > arr[right] && right < arr.size()) {
                temp = right;
            }

            if (arr[i] <= arr[temp]) {
                break;
            }

            swap(arr[i], arr[temp]);
            i = temp;
        }
    }

    int findIndex_X(int old) {
        for (int i = 0; i < len; i++) {
            if (arr[i] == old)
                return i;
        }
        return -100;
    }

public:
    QueueClass() {
        arr.resize(1000000);
    }
    void push(int value)
    {
        arr[len] = value;
        siftUp(len++);
    }

    int extract_min() // удаление первого эл-та массива (= минимального)
    {
        if (len < 1) {
            return 666;
        }
        int temp = arr[0];
        arr[0] = arr[len-1];
        len--;
        siftDown(0);
        return temp;
    }

    void decrease_key(int old, int y) {
        int temp = findIndex_X(old);
        arr[temp] = y;
        siftUp(temp);
    }
};

int main() {
    freopen("priorityqueue.in", "r", stdin);
    freopen("priorityqueue.out", "w", stdout);

    vector<int> keys;
    keys.reserve(1000000);

    QueueClass arr;
    string str;

    int keys_count = 0;
    while (cin >> str) {

        if (str == "push") {
            int temp_num;
            cin >> temp_num;
            arr.push(temp_num);
            keys[keys_count] = temp_num;
        }

        if (str == "extract-min") {
            int temp_res = arr.extract_min();
            if (temp_res == 666) {
                cout << "*" << '\n';
            }
            else {
                cout << temp_res << '\n';
            }
        }

        if (str == "decrease-key") {
            int x, y;
            cin >> x >> y;
            arr.decrease_key(keys[x - 1], y);
            keys[x - 1] = y;
        }
        keys_count++;
    }
    return 0;
}
