#include "node.h"

class BinaryTreeADT {
	public:

    //accessor methods
    virtual node* left(node*) = 0;
    virtual node* right(node*) = 0;
    virtual node* sibling(node*) = 0;

    //update methods
	virtual node* addRoot(int) = 0;
	virtual node* addLeft(node*, int) = 0;
	virtual node* addRight(node*, int) = 0;
    virtual int set(node*, int) = 0;
    virtual void attach(node*, node*, node*) = 0;
    virtual int remove(node*) = 0;

    //print
	virtual void print() = 0;

};