//
// Created by Anastasiia on 20.12.2021.
//



#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class ComplexNode {
public:

    int key = 0;
    int left = -1;
    int right = -1;

    ComplexNode(int k, int l, int r) {
        key = k;
        left = l;
        right = r;
    }

    bool leftExists() {
        return left != -1;
    }

    bool rightExists() {
        return right != -1;
    }

};


class Node {
public:
    int key = 0;
    int height = 0;
    int absoluteIndex = -1;

    Node* leftChild = nullptr;
    Node* rightChild = nullptr;

    Node(int k, Node* l, Node* r) {
        key = k;
        leftChild = l;
        rightChild = r;
    }

    Node(int k, int index) {
        key = k;
        absoluteIndex = index;
    }

    bool leftExists() {
        return leftChild != nullptr;
    }

    bool rightExists() {
        return rightChild != nullptr;
    }

};

class AVL {
public:
    vector<ComplexNode*> tree;
    vector<ComplexNode*> tempTree;

    Node* root = nullptr;

    void calculateHeights() {
        if (!tree.empty()) {
            heightDFS(root);
        }

    }

    void heightDFS(Node* v) {
        if (v->leftExists()) {
            heightDFS(v->leftChild);
        }

        if (v->rightExists()) {
            heightDFS(v->rightChild);
        }

        updateHeight(v);
    }

    void updateHeight(Node* v) {
        v->height = max(leftHeight(v), rightHeight(v)) + 1;
    }

    int leftHeight(Node* v) {
        if (v->leftExists()) {
            return v->leftChild->height;
        }
        else {
            return 0;
        }
    }


    int rightHeight(Node* v) {
        if (v->rightExists()) {
            return v->rightChild->height;
        }
        else {
            return 0;
        }
    }

    int balance(Node* v) {
        if (v == nullptr) {
            return 0;
        }

        int l = 0;
        int r = 0;

        if (v->leftExists()) {
            l = v->leftChild->height;
        }

        if (v->rightExists()) {
            r = v->rightChild->height;
        }

        return r - l;
    }

    // поворот


    void initTree() {
        root = new Node(tree[0]->key, 0);
        initDFS(root);
    }

    void initDFS(Node* v) {

        if (tree[v->absoluteIndex]->leftExists()) {
            int i = tree[v->absoluteIndex]->left;
            v->leftChild = new Node(tree[i]->key, i);
            initDFS(v->leftChild);
        } else {
            v->leftChild = nullptr;
        }

        if (tree[v->absoluteIndex]->rightExists()) {
            int i = tree[v->absoluteIndex]->right;
            v->rightChild = new Node(tree[i]->key, i);
            initDFS(v->rightChild);
        } else {
            v->rightChild = nullptr;
        }

    }

    Node* rotateLeft(Node* v) {

        Node* u = v->rightChild;
        v->rightChild = u->leftChild;
        u->leftChild = v;

        updateHeight(v);
        updateHeight(u);

        return u;
    }

    Node* rotateRight(Node* v) {

        Node* u = v->leftChild;
        v->leftChild = u->rightChild;
        u->rightChild = v;

        updateHeight(v);
        updateHeight(u);

        return u;
    }

    Node* toBalance(Node* v) {
        if (balance(v->rightChild) < 0) {
            v->rightChild = rotateRight(v->rightChild);
        }
        return rotateLeft(v);
    }

    void traversalBFS() {

        queue<Node*> q;
        q.push(root);

        int n = 1;

        while (!q.empty()) {

            Node* v = q.front();
            q.pop();

            int leftN = 0;
            int rightN = 0;

            if (v->leftChild != nullptr) {
                q.push(v->leftChild);
                leftN = ++n;
            }

            if (v->rightChild != nullptr) {
                q.push(v->rightChild);
                rightN = ++n;
            }


            tempTree.push_back(new ComplexNode(v->key, leftN, rightN));
        }

    }

};



int main() {
    ios_base::sync_with_stdio(false);

    freopen("rotation.in", "r", stdin);
    freopen("rotation.out", "w", stdout);

    int n, k, l, r;
    cin >> n;
    AVL avl;

    for (int i = 0; i < n; i++) {
        cin >> k >> l >> r;
        avl.tree.push_back(new ComplexNode(k, l - 1, r - 1));
    }

    avl.initTree();
    avl.calculateHeights();
    avl.root = avl.toBalance(avl.root);
    avl.traversalBFS();

    cout << avl.tempTree.size() << "\n";

    for (auto t : avl.tempTree) {
        cout << t->key << " " << t->left << " " << t->right << "\n";
    }

    return 0;
}