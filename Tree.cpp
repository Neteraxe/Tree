typedef int Rank;
#define ListNodePos(T) ListNode<T>*	//ListNodePos(T) is an address with ListNode<T> size

template <typename T> struct ListNode {
	// all data contained
	T data;	
	ListNodePos(T) pred;
	ListNodePos(T) succ;
	// means of abstraction
	ListNode() {};
	ListNode( T e, ListNodePos(T) p, ListNodePos(T) s) : data(e), pred(p), succ(s) {}

	//
	ListNodePos(T) insertAsPred(T const& e);
	ListNodePos(T) insertAsSucc(T const& e);
}

template <typename T> class List {
	// all data contained
private:
	int _size;
	ListNodePos(T) header;
	ListNodePos(T) trailer;

	// means of abstraction, which more common in the class
protected:
	void init();
	int clear();
	
	// means of abstraction
public:
	List() {init();}
	List(List<T> const& L); 
	List(List<T> const& L, Rank r, int n);	
	~List();

}

// means of combination
template <typename T> void List<T>::init() {
	// init data
	_size = 0;
	header = new ListNode<T>;
	trailer = new ListNode<T>;
	// build combination
	header->succ = trailer;
	header->pred = nullptr;
	trailer->pred = header;
	trailer->succ = nullptr;
}



