
// You must know the pointer is a var that signs
// a ListNode<T> room init address, and read a type ListNode<T> address.
// 1.Pointer,

// 2.ListNode
template <typename T>
struct ListNode
{
    // all data contained
    T data;
    ListNode<T> *pred;
    ListNode<T> *succ;
    // means of abstraction
    // constructer
    ListNode(){};
    ListNode(T e, ListNode<T> *p, ListNode<T> *s) : data(e), pred(p), succ(s){};

    // means of abstraction, method
    // insert a Node e which Pred this
    ListNode<T> *insertAsPred(T const &e);

    ListNode<T> *insertAsSucc(T const &e);
};

template <typename T>
ListNode<T> *ListNode<T>::insertAsPred(T const &e)
{
    ListNode<T> *x = new ListNode(e, pred, this);
    pred->succ = x;
    pred = x;
    return x;
};
