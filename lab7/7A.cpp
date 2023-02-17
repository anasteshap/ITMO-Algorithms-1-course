#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int key;
    int leftC;
    int rightC;

    Node(int k, int l, int r) {
        key = k;
        leftC = l;
        rightC = r;
    }

    int height;

    bool leftExists() {
        return leftC != -1;
    }

    bool rightExists() {
        return rightC != -1;
    }

};

class AVL {
public:
    vector<Node*> tree;

    void height_counter() {
        if (!tree.empty()) {
            height_pass(tree[0]);
        }

    }

    void height_pass(Node* element) {

        if (element->leftExists()) {
            height_pass(tree[element->leftC]);
        }
        if (element->rightExists()) {
            height_pass(tree[element->rightC]);
        }

        element->height = max(height_left(element), height_right(element)) + 1;
    }

    int height_left(Node* element) {
        if (element->leftExists()) {
            return tree[element->leftC]->height;
        }
        else {
            return 0;
        }
    }


    int height_right(Node* element) {
        if (element->rightExists()) {
            return tree[element->rightC]->height;
        }
        else {
            return 0;
        }
    }

    int balance(int k) {
        int left = 0;
        int right = 0;

        if (height_left(tree[k])) {
            left = tree[tree[k]->leftC]->height;
        }

        if (height_right(tree[k])) {
            right = tree[tree[k]->rightC]->height;
        }

        return right - left;
    }

};



int main() {
    ios_base::sync_with_stdio(false);

    freopen("balance.in", "r", stdin);
    freopen("balance.out", "w", stdout);

    int n;
    cin >> n;

    int key, left, right;
    AVL avl;

    for (int i = 0; i < n; i++) {
        cin >> key >> left >> right;
        Node* element = new Node(key, left - 1, right - 1);
        avl.tree.push_back(element);
    }

    avl.height_counter();

    for (int i = 0; i < avl.tree.size(); i++) {
        cout << avl.balance(i) << "\n";
    }

    return 0;
}