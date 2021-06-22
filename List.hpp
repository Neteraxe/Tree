#include "node/ListNode.h"

template <typename T>
class List
{
	// all data contained
private:
	int _size;
	ListNode<T> *header;
	ListNode<T> *trailer;

	// means of abstraction, which more common in the class
protected:
	void init();
	int clear();

	// means of abstraction
public:
	// getter
	int size() const
	{
		return _size;
	}
	ListNode<T> *first() const
	{
		return header->succ;
	}
	ListNode<T> *last() const
	{
		return trailer->pred;
	}

	// constructor
	List<T>()
	{
		init();
	}
	List<T>(List<T> const &L);
	List<T>(List<T> const &L, int r, int n);

	// deconstructor
	~List<T>();

	// method
	T remove(ListNode<T> *p);

	// insert e which is type T as last node
	ListNode<T> *insertAsLast(T const &e);

	// traverse
	void traverse(void (*)(T &));
};

// means of combination
// construction
template <typename T>
void List<T>::init()
{
	// init data
	_size = 0;
	header = new ListNode<T>;
	trailer = new ListNode<T>;
	// build combination
	header->succ = trailer;
	header->pred = nullptr;
	trailer->pred = header;
	trailer->succ = nullptr;
};

template <typename T>
T List<T>::remove(ListNode<T> *p)
{
	T e = p->data;
	p->pred->succ = p->succ;
	p->succ->pred = p->pred;
	delete p;
	_size--;
	return e;
};

template <typename T>
int List<T>::clear()
{
	int oldSize = _size;
	while (_size > 0)
		remove(header->succ);
	return oldSize;
};

// A destructor is a special member function that is called when the lifetime of an object ends.
// The purpose of the destructor is to free the resources that the object may have acquired during its lifetime.
template <typename T>
List<T>::~List()
{
	clear();
	delete header;
	delete trailer;
};

template <typename T>
ListNode<T> *List<T>::insertAsLast(T const &e)
{
	_size++;
	return trailer->insertAsPred(e);
}
