#include <iostream>

using std::cin, std::cout, std::ios_base, std::max;

class Node {
public:
    int key;
    int value;
    int height;
    Node* left;
    Node* right;

    Node(int key, int value) {
        this->key = key;
        this->value = value;
        this->height = 0;
        this->left = this->right = nullptr;
    }
};

class AVLTree {
private:
    Node* root;
    int size;

    Node* insert(Node* root, int key, int value) {
        int balance;
        
        if (root == nullptr) return new Node(key, value);

        if (root->key > key) root->left = insert(root->left, key, value);
        else root->right = insert(root->right, key, value);

        root->height = max(height(root->left), height(root->right)) + 1;

        balance = subTreeBalance(root);

        if (balance < -1 && value >= root->right->value) return leftRotate(root);
        else if (balance > 1 && value < root->left->value) return rightRotate(root);
        else if (balance > 1 && value >= root->left->value) {
            root->left  = leftRotate(root->left);
            return rightRotate(root);
        }
        else if (balance < -1 && value < root->right->value) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    int find(Node* root, int key) {
        if (root->key == key) return root->value;
        else if (root->key > key) return find(root->left, key);
        else return find(root->right, key);
    }

    void inOrderTraversal(Node* root){
        if (root == nullptr) return;

        inOrderTraversal(root->left);
        cout << root->value << ' ';
        inOrderTraversal(root->right);
    }

    void preOrderTraversal(Node* root) {
        if (root == nullptr) return;

        cout << root->value << ' ';
        inOrderTraversal(root->left);
        inOrderTraversal(root->right);
    }

    void postOrderTraversal(Node* root) {
        if (root == nullptr) return;

        inOrderTraversal(root->left);
        inOrderTraversal(root->right);
        cout << root->value << ' ';
    }

    int height(Node* root) {
        if (root == nullptr) return -1;

        return root->height;
    }

    int subTreeBalance(Node* root) {
        if (root == nullptr) return 0;

        return height(root->left) - height(root->right);
    }

public:
    AVLTree() {
        this->root = nullptr;
        this->size = 0;
    }

    ~AVLTree() {
    
    }

    void insert(int key, int value) {
        this->root = insert(this->root, key, value);
        this->size++;
    }

    int find(int key) {
        return find(this->root, key);
    }

    void inOrderTraversal(){
        inOrderTraversal(this->root);
    }

    void preOrderTraversal() {
        preOrderTraversal(this->root);
    }

    void postOrderTraversal() {
        postOrderTraversal(this->root);
    }

    Node* leftRotate(Node* root) {
        Node *r, *rl;
        
        r = root->right;
        rl = root->right->left;

        r->left = root;
        root->right = rl;

        root->height = max(height(root->left), height(root->right)) + 1;
        r->height = max(height(r->left), height(r->right)) + 1;

        return r;
    }

    Node* rightRotate(Node* root){
            Node *l, *lr;

            l = root->left;
            lr = root->left->right;
            
            l->right = root;
            root->left = lr;

            root->height = max(height(root->left), height(root->right)) + 1;
            l->height = max(height(l->left), height(l->right)) + 1;

            return l;
    }


};

void solve() {
    int n; // 0 < n <= 1000 - Quantidade de números inteiros (32 bits)
    
    cin >> n;
    // for (int i = 0; i < n; i++) -> inserir na avl;


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}