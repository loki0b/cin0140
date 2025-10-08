#include <iostream>

using std::cin, std::cout, std::ios_base, std::max;

bool rotate = false;

class Node {
public:
    int value;
    int height;
    Node* left;
    Node* right;

    Node(int value) {
        this->value = value;
        this->height = 0;
        this->left = this->right = nullptr;
    }
};

class AVLTree {
private:
    Node* root;
    int size;

    Node* insert(Node* root, int value) {
        int balance;
        
        if (root == nullptr) { 
            if (this->size == 0) cout << "no rotation!";
            return new Node(value);
        }

        if (root->value > value) root->left = insert(root->left, value);
        else root->right = insert(root->right, value);

        root->height = max(height(root->left), height(root->right)) + 1;

        balance = subTreeBalance(root);

        if (balance < -1 && value >= root->right->value) { 
            rotate = true;
            cout << root->value << " is unbalanced, L-rotation!";
            return leftRotate(root);
        }
        else if (balance > 1 && value < root->left->value) {
            rotate = true;
            cout << root->value << " is unbalanced, R-rotation!";
            return rightRotate(root);
        }
        else if (balance > 1 && value >= root->left->value) {
            rotate = true;
            cout << root->value << " is unbalanced, LR-rotation!";
            root->left  = leftRotate(root->left);
            return rightRotate(root);
        }
        else if (balance < -1 && value < root->right->value) {
            rotate = true;
            cout << root->value << " is unbalanced, RL-rotation!";
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        else if (this->root == root && !rotate) {
            cout << "no rotation!";
        }

        return root;
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

    void inOrderTraversal(Node* root){
        if (root == nullptr) return;

        inOrderTraversal(root->left);
        cout << ' ' << root->value;
        inOrderTraversal(root->right);
    }

    void preOrderTraversal(Node* root) {
        if (root == nullptr) return;

        cout << ' ' << root->value;
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }

    void postOrderTraversal(Node* root) {
        if (root == nullptr) return;

        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << ' ' << root->value;
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

    void insert(int value) {
        this->root = insert(this->root, value);
        this->size++;
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

};

void solve() {
    AVLTree tree;
    int n, num; 

    
    cin >> n; // 0 < n <= 1000 - Quantidade de números inteiros (32 bits)
    for (int i = 0; i < n; i++) {
        rotate = false;
        cin >> num;
        cout << "insert " << num << ": ";
        tree.insert(num);
        cout << '\n';
    }

    cout << "preorder:";
    tree.preOrderTraversal();
    cout << '\n';
    cout << "inorder:";
    tree.inOrderTraversal();
    cout << '\n';
    cout << "postorder:";
    tree.postOrderTraversal();
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}