
// You must know the pointer is a var that signs
// a ListNode<T> room init address, and read a type ListNode<T> address.
// 1.Pointer,

// 2.BinNode
template <typename T>
struct BinNode
{
    // all data contained
    T data;
    // add height
    int height;
    // parent, lChild, rChild
    BinNode<T> *parent;
    BinNode<T> *lChild;
    BinNode<T> *rChild;
    // means of abstraction
    // constructer
    ListNode(){};
    ListNode(T e, BinNode<T> *p, BinNode<T> *s) : data(e), pred(p), succ(s) {}

    // means of abstraction, method
    // insert a Node e which Pred this
    BinNode<T> *insertAsPred(T const &e);
    BinNode<T> *insertAsSucc(T const &e);
};

template <typename T>
BinNode<T> *BinNode<T>::insertAsPred(T const &e)
{
    ListNode<T> *x = new ListNode(e, pred, this);
    pred->succ = x;
    pred = x;
    return x;
};
