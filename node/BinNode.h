#include <iostream>

using namespace std;
// You must know the pointer is a var that signs
// a ListNode<T> room init address, and read a type ListNode<T> address.
// 1.Pointer,

// 2.BinNode
template <typename T>
class BinNode
{
private:
    // all data contained
    T data;
    // parent, lChild, rChild
    BinNode<T> *lChild;
    BinNode<T> *rChild;

public:
    // means of abstraction
    // constructer
    BinNode(){};
    BinNode(T e) : data(e), lChild(nullptr), rChild(nullptr){};

    bool insert(BinNode<T> &n);
    void traverseInorder(BinNode<T> &n);
    void traversePostorder(BinNode<T> &n);
};

template <typename T>
void BinNode<T>::traverseInorder(BinNode<T> &n)
{
    if (n->lChild != nullptr)
        n->lChild->traverseInorder(n);
    cout << n.data;
    if (n->rChild != nullptr)
        n->rChild->traverseInorder();
}

template <typename T>
void BinNode<T>::traversePostorder(BinNode<T> &n)
{
    if (n->lChild != nullptr)
        n->lChild->traversePostorder(n);
    if (n->rChild != nullptr)
        n->rChild->traversePostorder();
    cout << n.data;
}

template <typename T>
bool BinNode<T>::insert(BinNode<T> &n)
{
    if (this->data > n.data)
    {
        if (this->lChild == nullptr)
            this->lChild = n;
        else
            this->lChild->insert(n);
    }
    else
    {
        if (this->rChild == nullptr)
            this->rChild = n;
        else
            this->rChild->insert(n);
    }
}
