#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Set {
private:
    vector<list<string>> hashTable; // таблица ключей

    unsigned hash(string key) { // хеширование
        unsigned hash = 0; //хеш
        int charCode;
        const int k = 199; // константа

        for (char i: key) {
            charCode = tolower(i) - 'a';
            hash = (hash * k + charCode) % hashTable.size();
        }

        return hash;
    }

public:
    Set() : Set (251) {}

    Set(unsigned size) {
        hashTable.resize(size);
    }

    bool exists(string key) {
        unsigned index = hash(key);
        for (string i : hashTable[index]) {
            if (i == key)
                return true;
        }
        return false;
    }

    void put(string key) {
        if (!exists(key)) // добавляем, если не найден
            hashTable[hash(key)].push_back(key);
    }

    vector<string> getAll() {
        vector<string> result;
        for (list<string> values : hashTable) { // проходим по спискам
            for (string value : values) { // проходим по элементам списков - строчки ключей
                result.push_back(value); // вектор всех включей из таблицы
            }
        }
        return result;
    }

    void remove(string key) {
        unsigned index = hash(key); // хеш

        for (auto i = hashTable[index].begin(); i != hashTable[index].end(); i++) { //проходим по списку с индексом хеша
            if (*i == key) {
                hashTable[index].erase(i); // удаляе
                return;
            }
        }
    };
};


class MultiMap {
private:
    struct Element {
        string key;
        Set* values;
    };

    vector<list<Element>> hashTable;
    unsigned valueSetSize;

    unsigned hash(string key) { // хеширование
        unsigned hash = 0; //хеш
        int charCode;
        const int k = 199; // константа

        for (char i : key) {
            charCode = tolower(i) - 'a';
            hash = (hash * k + charCode) % hashTable.size();
        }

        return hash;
    }

    Set* getValueSet(string key) {
        unsigned index = hash(key);

        for (Element& element: hashTable[index]) {
            if (element.key == key) {
                return element.values;
            }
        }

        return nullptr;
    }


public:
    MultiMap() : MultiMap(100003, 251) {}

    MultiMap(unsigned mapSize) : MultiMap(mapSize, 251) {}

    MultiMap(unsigned mapSize, unsigned valueSetSize) {
        hashTable.resize(mapSize);
        this->valueSetSize = valueSetSize;
    }

    void put(string key, string value) {
        Set* valueSet = getValueSet(key);

        if (valueSet != nullptr) { // если такой нет
            valueSet->put(value);
        }
        else {
            Element newEl;
            newEl.key = key;
            newEl.values = new Set(); //---------------------------------
            newEl.values->put(value);
            hashTable[hash(key)].push_back(newEl);
        }
    }

    vector<string> get(string key) {
        Set* valueSet = getValueSet(key);

        if (valueSet != nullptr) {
            return valueSet->getAll();
        }
        else {
            return vector<string>(0);
        }
    }

    void deletion(string key, string value) {
        Set* valueSet = getValueSet(key);

        if (valueSet != nullptr) {
            valueSet->remove(value);
        }
    }

    void deletionAll(string key) {
        Set* valueSet = getValueSet(key);

        if (valueSet != nullptr) {
            for (auto i = hashTable[hash(key)].begin(); i != hashTable[hash(key)].end(); i++) {
                if (i->key == key) {
                    hashTable[hash(key)].erase(i);
                    return;
                }
            }
        }
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("multimap.in", "r", stdin);
    freopen("multimap.out", "w", stdout);

    MultiMap mm(10001, 251);
    string command, x, y;

    while (cin >> command) {
        cin >> x;

        if (command == "put") {
            cin >> y;
            mm.put(x, y);
        }
        else if (command == "get") {
            vector<string> arr = mm.get(x) ;
            cout << arr.size();
            for (int i = 0; i < arr.size(); i++) {
                cout << " " << arr[i];
            }
            cout << endl;
        }
        else if (command == "delete") {
            cin >> y;
            mm.deletion(x, y);
        }
        else if (command == "deleteall") {
            mm.deletionAll(x);
        }
    }

    return 0;
}
