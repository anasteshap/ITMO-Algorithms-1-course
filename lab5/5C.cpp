#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int value;
    Node *parent;
    Node *left;
    Node *right;
};

Node *exists(Node *tree, int key) {
    if (tree == nullptr || key == tree->value) {
        return tree;
    }

    if (key < tree->value) {
        return exists(tree->left, key);
    } else {
        return exists(tree->right, key);
    }
}

bool bool_exists(Node *tree, int key) {
    if (tree == nullptr) {
        return false;
    }
    if (key == tree->value) {
        return true;
    }
    if (key < tree->value) {
        return bool_exists(tree->left, key);
    } else
        return bool_exists(tree->right, key);
}

Node *insert(Node *&tree, int value) {
    if (tree == nullptr) {
        tree = new Node;
        tree->value = value;
        tree->parent = tree->left = tree->right = nullptr;
    } else if (value < tree->value) {
        insert(tree->left, value);
        tree->left->parent = tree;
    } else if (value > tree->value) {
        insert(tree->right, value);
        tree->right->parent = tree;
    }
    return tree;
}

Node *min(Node *tree) { // минимальный элемент
    while (tree->left != nullptr) {
        tree = tree->left;
    }
    return tree;
}

Node *max(Node *tree) { // максимальный элемент
    while (tree->right != nullptr) {
        tree = tree->right;
    }
    return tree;
}

Node *prev(Node *x) {
    if (x->left != nullptr) {
        return max(x->left);
    }
    Node *y = x->parent;
    while (y != nullptr && x == y->left) {
        x = y;
        y = y->parent;
    }
    return y;
}

Node *next(Node *x) {
    if (x->right != nullptr) {
        return min(x->right);
    }

    Node *y = x->parent;
    while (y != nullptr && x == y->right) {
        x = y;
        y = y->parent;
    }
    return y;
}

Node *deletion(Node *&root, Node *a) {
    if (root == nullptr)
        return root;
    if (a->value < root->value)
        root->left = deletion(root->left, a);
    else if (a->value > root->value)
        root->right = deletion(root->right, a);
    else if (root->left != nullptr && root->right != nullptr) {
        root->value = min(root->right)->value;
        root->right = deletion(root->right, exists(root, root->value));
    } else {
        if (root->left != nullptr)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("bstsimple.in", "r", stdin);
    freopen("bstsimple.out", "w", stdout);

    int a;
    string str;

    Node *tree = nullptr;

    while (cin >> str) {
        cin >> a;
        if (str == "insert") {
            insert(tree, a);

        } else if (str == "delete") {
            if (exists(tree, a) != nullptr) {
                deletion(tree, exists(tree, a));
            }

        } else if (str == "exists") {
            cout << (bool_exists(tree, a) ? "true" : "false") << '\n';

        } else if (str == "next") {
            if (bool_exists(tree, a)) { // если элемент с таким значением существует в дереве
                if (exists(tree, a) != max(tree)) { // если данный элемент не равен максимальному в дереве
                    cout << next(exists(tree, a))->value << '\n';
                } else {
                    cout << "none\n"; // если данный элемент - максимальный
                }

            } else { // если не существует
                insert(tree, a);
                if (exists(tree, a) == max(tree)) { // если данный элемент - узел с максимальным значением
                    cout << "none\n";
                    deletion(tree, exists(tree, a)); // удаляем вставленный элемент
                } else {
                    cout << next(exists(tree, a))->value << '\n';
                    deletion(tree, exists(tree, a)); // удаляем вставленный элемент
                }
            }

        } else if (str == "prev") {
            if (bool_exists(tree, a)) { // если элемент с таким значением существует в дереве
                if (exists(tree, a) != min(tree)) {
                    cout << prev(exists(tree, a))->value << '\n';
                } else {
                    cout << "none\n"; // если данный элемент - минимальный
                }

            } else { // если не существует
                insert(tree, a);

                if (exists(tree, a) == min(tree)) { // если данный элемент - узел с минимальным значением
                    cout << "none\n";
                    deletion(tree, exists(tree, a)); // удаляем вставленный элемент
                } else {
                    cout << prev(exists(tree, a))->value << '\n';
                    deletion(tree, exists(tree, a)); // удаляем вставленный элемент
                }
            }
        }


    }

    return 0;
}