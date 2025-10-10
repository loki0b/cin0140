#include <iostream>

using std::cin, std::cout, std::max;

template <typename k, typename v>
class node {
public:
    k key;
    v value;
    int height;
    node<k, v>* left;
    node<k, v>* right;

    node(k key, v value) {
        this->left = nullptr;
        this->right = nullptr;
        this->key = key;
        this->value = value;
        this->height = 0;
    }
};

template <typename k, typename v>
class avlTree {
private:
    node<k ,v>* root;    
    
    node<k, v>* insert(node<k, v>* root, k key, v value) {
        int balance;

        if (root == nullptr) return new node<k, v>(key, value);

        if (root->key > key) root->left = insert(root->left, root, key, value);
        else root->right = insert(root->right, root, key, value);
        
        root->height = max(height(root->left), height(root->right)) + 1;

        balance = subTreeBalance(root);

        if (balance < -1 && key >= root->right->key) return leftRotate(root);
        else if (balance > 1 && key < root->left->key) return rightRotate(root);
        else if (balance < -1 && key < root->right->key) {
            root->right = rightRotate(root->right);
            
            return leftRotate(root);
        }
        else if (balance > 1 && key >= root->left->key) {
            root->left = leftRotate(root->left);
            
            return rightRotate(root);
        }

        return root;
    }

    node<k, v>* leftRotate(node<k, v>* root) {
        node<k, v> *right, *rightLeft;

        right = root->right;
        rightLeft = root->right->left;

        // Rotating
        right->left = root;
        root->right = rightLeft;

        root->height = max(height(root->left), height(root->right)) + 1;
        right->height = max(height(right->left), height(right->right)) + 1;

        return right;
    }

    node<k, v>* rightRotate(node<k, v>* root) {
        node<k, v> *left, *leftRight;

        left = root->left;
        leftRight = root->left->right;

        // Rotating
        left->right = root;
        root->left = leftRight;

        root->height = max(height(root->left), height(root->right)) + 1;
        left->height = max(height(left->left), height(left->right)) + 1;

        return left;
    }

    int height(node<k, v>* root) {
        if (root == nullptr) return -1;

        return root->height;
    }

    int subTreeBalance(node<k, v>* root) {
        if (root == nullptr) return 0;

        return height(root->left) - height(root->right);
    }

    int find(node<k, v>* root, k key) {
        if (root->key == key) return root->value;
        else if (root->key > key) return find(root->left, key);
        else return find(root->right, key);
    }

    void preOrderTraversal(node<k, v>* root) {
        if (root == nullptr) return;

        cout << root->key << ": " << root->value << ' ';
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }


    void inOrderTraversal(node<k, v>* root) {
        if (root == nullptr) return;

        inOrderTraversal(root->left);
        cout << root->key << ": " << root->value << ' ';
        inOrderTraversal(root->right);
    }

    void postOrderTraversal(node<k, v>* root) {
        if (root == nullptr) return;

        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->key << ": " << root->value << ' ';
    }

public:
    int size; // Number of elements

    avlTree() {
        this->root = nullptr;
        this->size = 0;
    }

    void insert(k key, v value) {
        this->root = insert(this->root, nullptr, key, value);
        this->size++;
    }


    int find(k key) {
        if (this->size > 0) return find(this->root, key);

        return -1;
    }

    void preOrderTraversal() {
        preOrderTraversal(this->root);
    }

    void inOrderTraversal() {
        inOrderTraversal(this->root);
    }

    void postOrderTraversal() {
        postOrderTraversal(this->root);
    }

};

int main(void) {

    avlTree<int, int> tree;
    tree.insert(0, 0);
    tree.insert(1, 1);

    tree.inOrderTraversal();
    cout << '\n';
    return 0;
}