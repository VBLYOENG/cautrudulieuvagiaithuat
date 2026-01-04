#include <iostream>
using namespace std;

struct Node {
    int value;     
    Node* left;     
    Node* right;    
    Node(int v, Node* l = NULL, Node* r = NULL) {
        value = v;
        left = l;
        right = r;
    }
};
class BSTree {
private:
    Node *root;
    void lamRong (Node*& t) {
        if (t != NULL) {
            lamRong (t->left);  
            lamRong (t->right); 
            delete t;            
            t = NULL;
        }
    }
    void chenNut(int a1, Node*& t) {
        if (t == NULL) {
            t = new Node(a1);
        } else if (a1 < t->value) {
            chenNut(a1, t->left);
        } else if (a1 > t->value) {
            chenNut(a1, t->right);
        }
    }

    Node* timKiem(int a2, Node* t) {
        if (t == NULL) return NULL;
        if (a2 == t->value) return t; 
        if (a2 < t->value) return timKiem(a2, t->left);
        return timKiem(a2, t->right); 
    }
public:
    BSTree() {
        root = NULL;
    }
    ~BSTree() {
        lamRong (root);
    }
    bool isEmpty() {
        return root == NULL;
    }
    void lamRong () {
        lamRong (root);
    }
    void chenNut(int a1) {
        chenNut(a1, root);
    }
    Node* timKiem(int a2) {
        return timKiem(a2, root);
    }
    Node* getRoot() {
        return root;
    }
};
void duyetTruoc(Node* t) {
    if (t == NULL) return;
    cout << t->value << " ";
    duyetTruoc(t->left);     
    duyetTruoc(t->right); 
}
void duyetGiua(Node* t) {
    if (t == NULL) return;
    duyetGiua(t->left);
    cout << t->value << " ";
    duyetGiua(t->right);
}
void duyetSau(Node* t) {
    if (t == NULL) return;
    duyetSau(t->left);
    duyetSau(t->right);
    cout << t->value << " ";
}
int main() {
    BSTree bst;   
    bst.chenNut(5);
    bst.chenNut(6);
    bst.chenNut(3);
    bst.chenNut(8);
    bst.chenNut(7);
    bst.chenNut(4);
    bst.chenNut(2);
    Node *rootNode = bst.getRoot(); 
    cout << "duyet cay thu tu truoc: " << endl;
    duyetTruoc(rootNode);
    cout << endl;
    cout << "duyet cay thu tu giua: " << endl;
    duyetGiua(rootNode);
    cout << endl;
    cout << "duyet cay thu tu sau: " << endl;
    duyetSau(rootNode);
    cout << endl;
    Node* n1 = bst.timKiem(4);
    Node* n2 = bst.timKiem(9);
    if (n1 != NULL)
        cout << "Node co gia tri = 4 la " << n1->value << endl;
    if (n2 == NULL)
        cout << "Khong tim thay node co gia tri = 9" << endl;
    bst.lamRong();
    if (bst.isEmpty()) {
        cout << "Cay da bi xoa rong" << endl;
    }
    return 0;
}