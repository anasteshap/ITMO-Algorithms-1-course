#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("set.in", "r", stdin);
    freopen("set.out", "w",stdout);

    vector<vector<int>> Hash(1001);
    string cmd;
    int x, a, index;
    bool isExists;

    while (cin >> cmd) {
        isExists = false; // изначально: такого элемента не существует

        cin >> x;
        a = x % 1001; // a используется для индексации (строчек) => не может быть больше размера вектора

        if (a < 0)
            a = -a;

        for (int i = 0; i < Hash[a].size(); i++) { // проверка, существует ли такой элемент
            if (Hash[a][i] == x) {
                isExists = true;
                index = i; // столбец
                break;
            }
        }

        if (isExists && cmd == "delete")
            Hash[a].erase(Hash[a].begin() + index); // удаление элемента => размер вектора уменьшается

        if (!isExists && cmd == "insert")
            Hash[a].push_back(x);

        if (cmd == "exists") {
            if (isExists)
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
    }

    return 0;
}