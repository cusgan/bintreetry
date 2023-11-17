#include <iostream>
#include <stdexcept>
#include "bintree.h"
using namespace std;

int main() {
	BinaryTreeADT* tree = new BinaryTree();

	node* root = tree->addRoot(50);
    //tree->print();
    node* lip = tree->addLeft(root, 25);
    node* ryt = tree->addRight(root, 75);
    //tree->print();
    node* liplip = tree->addLeft(lip, 20);
    node* lipryt = tree->addRight(lip, 30);
    //tree->print();
    node* rytlip = tree->addLeft(ryt, 70);
    node* rytryt = tree->addRight(ryt, 80);
    //tree->print();
    tree->addLeft(liplip, 15);
    tree->addRight(liplip, 22);
    //tree->print();
    tree->addLeft(lipryt, 28);
    tree->addRight(lipryt, 35);
    //tree->print();
    tree->addLeft(rytlip, 65);
    tree->addRight(rytlip, 72);
    tree->addLeft(rytryt, 78);
    //tree->addRight(rytryt, 85);
    //tree->print();
    tree->remove(rytryt);
    tree->print();


    return 0;
}