#include "bintreeadt.h"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class BinaryTree : public BinaryTreeADT {
    node* root;
    int size;

    node* createNode(int e) {
        node* n = new node;
        n->elem = e;
        n->parent = n->left = n->right = nullptr;
        return n;
    }
    int children(node* n) {
        int c = 0;
        if (n->left) c++;
        if (n->right) c++;
        return c;
    }
    bool isLeaf(node* n) {
        return left(n) == nullptr && right(n) == nullptr;
    }
    int depth(node* n) {
        if (n->parent) {
            return 1 + depth(n->parent);
        }
        return 0;
    }
    int height(node* n) {
        if (isLeaf(n)) {
            return 0;
        }
        if (!n->right) {
            return 1 + height(n->left);
        }
        if (!n->left) { //needed ba ni in an ordered tree?
            return 1 + height(n->right);
        }
        return 1 + max(height(n->left), height(n->right));
    }

    public:

    //constructor
    BinaryTree() {
        root = nullptr;
        size = 0;
    }

    //accessor methods
    node* left(node* p) {
        if (p->left) {
            return p->left;
        }
        return nullptr;
    }
    node* right(node* p) {
        if (p->right) {
            return p->right;
        }
        return nullptr;
    }
    node* sibling(node* p) {
        if (!p->parent) {
            throw logic_error(to_string(p->elem) + " is a root");
        }
        node* par = p->parent;
        if (p == par->left) {
            return par->right;
        } 
        return par->left;
    }

    //update methods
	node* addRoot(int e) {
        if (root) {
	    	throw logic_error("Already has root"); 
        }
		node* n = createNode(e);
		size++;
		root = n;
		return n;		
    }
	node* addLeft(node* p, int e) {
        if (p->left) {
            throw logic_error(to_string(p->elem) + " already has left child");
        }
        node* n = createNode(e);
        n->parent = p;
        size++;
        p->left = n;
        return n;
    }
	node* addRight(node* p, int e) {
        if (p->right) {
            throw logic_error(to_string(p->elem) + " already has right child");
        }
        node* n = createNode(e);
        n->parent = p;
        size++;
        p->right = n;
        return n;
    }
    int set(node* p, int e) {
        int swapped = p->elem;
        p->elem = e;
        return swapped;
    }
    void attach(node* p, node* t1, node* t2) {
        if (!isLeaf(p)) {
            throw logic_error(to_string(p->elem) + " is not a leaf");
        }
        p->left = t1;
        p->right = t2;
        t1 = t2 = nullptr;
        //update size of tree p ?
    }
    int remove(node* p) {
        if (children(p) == 2) {
            throw logic_error(to_string(p->elem) + " has two children");
        }
        int removed = p->elem;
        node* par = p->parent;
        node* pleft = p->left; //assuming properly ordered 
        pleft->parent = par;
        if (p == par->left) {
            par->left = pleft;
        } else {
            par->right = pleft;
        }
        size--;
        return removed;
    }

    //print
    void print() {
		cout << "Size: " << size << endl;
		print(root, 0);
	}
	void print(node* n, int depth) {
		if (n) {
			cout << n->elem << endl;
			if (n->left) {
                for (int i = 0; i < depth; i++) {
                    cout << "-";
                }
                cout << "- L:";
                print(n->left, depth + 1);
			}
			if (n->right) {		
                for (int i = 0; i < depth; i++) {
                    cout << "-";
                }
                cout << "- R:";
                print(n->right, depth + 1);
			}
		}
    }

};