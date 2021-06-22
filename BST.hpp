#include "node/BinNode.h"

// Tree and List is a Recursion Definition
// Which means that actually only need a Class

template <typename T>
class BST
{
private:
    /* data */
    BinNode<T> *root;

public:
    BST() : root(nullptr){};
    ~BST() = default;
    void inOrder();
    void postOrder();
    void insert();
};

template <typename T>
void BST<T>::inOrder(){

};
