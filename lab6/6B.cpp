#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("map.in", "r", stdin);
    freopen("map.out", "w",stdout);

    vector<vector<pair<string, string>>> Hash(100001);
    string cmd, key, value;
    int x, a, index;
    bool isExists;

    while (cin >> cmd) {
        isExists = false; // изначально: такого элемента не существует

        cin >> key;
        x = 0; // хеш

        for (int i = key.length() - 1; i >= 0; i--) {
            x += ((int)(key[i])) * i;   // хешируем
        }
        a = abs(x % 100001); // a используется для индексации (строчек) => не может быть больше размера вектора

        for (int i = 0; i < Hash[a].size(); i++) { // проверка (построчно), существует ли такой элемент
            if (Hash[a][i].first == key) { // если элемент с таким кючем уже есть
                isExists = true; // значит существует
                index = i; // index - номер (в массиве) найденного элемента в строчке
                break;
            }
        }

        if (isExists && cmd == "delete")
            Hash[a].erase(Hash[a].begin() + index); // удаление элемента => размер вектора уменьшается

        if (cmd == "put") {
            cin >> value;
            if (!isExists) { // если элемента с таким ключем нет в таблице
                Hash[a].push_back(make_pair(key, value)); // в конец строчки добавляем пару (ключ,значение)
            }
            else { // если есть - меняем значение для этого ключа на новое
                Hash[a][index].second = value;
            }
        }

        if (cmd == "get") {
            if (isExists)
                cout << Hash[a][index].second << endl;
            else
                cout << "none" << endl;
        }
    }

    return 0;
}