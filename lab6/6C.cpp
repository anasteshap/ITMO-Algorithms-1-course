#include <iostream>
#include <vector>
#include <list>

using namespace std;

class LinkedMap {
private:
    struct Element { // структура элемента
        string key;
        string value;
        Element* prev;
        Element* next;
    };

     static Element* createElement(string key, string value) { // создание элемента
        auto* newElement = new Element(); // динамически
        newElement->key = key;
        newElement->value = value;
        newElement->prev = newElement->next = nullptr; // изначально следубщему и предыдущему присываеваем null

        return newElement;
    }

    vector<list<Element*>> hashTable; // таблца = вектор списков, элементы списка - указатели на Element

    Element* first = nullptr;
    Element* last = nullptr;

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

public:

    LinkedMap() {
        hashTable.resize(100001);
    }

    void put(string key, string value) {
        unsigned index = hash(key); // хеш
        for (Element*& i : hashTable[index]) {
            if (i->key == key) { // если элемент с таким ключом уже есть
                i->value = value; // меняем значение на новое
                return;
            }
        }
        Element* elementToPut = createElement(key, value); // если элемента с таким ключом нет, то создаем новый элемент
        elementToPut->prev = last;
        if (last != nullptr)
            last->next = elementToPut;
        last = elementToPut;
        if (first == nullptr)
            first = elementToPut;
        hashTable[index].push_back(elementToPut);
    }

    string get(string key) {
        unsigned index = hash(key); // хеш

        for (Element* i : hashTable[index]) {
            if (i->key == key)
                return i->value;
        }
        return "none";
    }

    void remove(string key) {
        unsigned index = hash(key); // хеш

        for (Element*& i : hashTable[index]) {

            if (i->key == key) {
                Element* elementToDelete = i;
                if (i->prev != nullptr) // если есть предыдущий
                    i->prev->next = i->next;
                else
                    first = i->next;

                if (i->next != nullptr) // если есть следующий
                    i->next->prev = i->prev;
                else
                    last = i->prev;
                hashTable[index].remove(i);

                delete elementToDelete; // удаление из динамической памяти
                return;
            }
        }
    }

    string prev(string key) {
        unsigned index = hash(key); // хеш

        for (Element* i : hashTable[index]) { // смотрим список (строчку) с хешем = index
            if (i->key == key) { // если нашли элемент, для которого нужно найти предыдущий
                if (i->prev != nullptr) // если есть предыдущий
                    return i->prev->value; // выводим его значение
                else
                    return "none";
            }
        }
        return "none"; // если нашли элемент, для которого нужно найти предыдущий
    }

    string next(string key) {
        unsigned index = hash(key); // хеш

        for (Element* i : hashTable[index]) {
            if (i->key == key) {
                if (i->next != nullptr)
                    return i->next->value;
                else
                    return "none";
            }
        }
        return "none";
    }

};

int main() {

    freopen("linkedmap.in", "r", stdin);
    freopen("linkedmap.out", "w", stdout);

    LinkedMap lmap;
    string command, x, y;

    while (cin >> command) {

        cin >> x;
        if (command == "put") {
            cin >> y;
            lmap.put(x, y);
        }
        else if (command == "get") {
            cout << lmap.get(x) << endl;
        }
        else if (command == "delete") {
            lmap.remove(x);
        }
        else if (command == "prev") {
            cout << lmap.prev(x) << endl;
        }
        else if (command == "next") {
            cout << lmap.next(x) << endl;
        }
    }

    return 0;
}