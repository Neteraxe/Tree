#include <iostream>
#include <list>
#include "List.hpp"

using namespace std;

int main()
{
    int i;
    cout << "press 0 to exit, or others as input\n";
    List<int> array{};
    while (cin >> i)
    {
        if (i == 0)
            return 0;
        array.insertAsLast(i);

        cout << "current list:\n";
        
        ListNode<int> *p = array.first();
        while (p != array.last())
        {
            cout << p->data << "\t";
            p = p->succ;
        }
        cout << p->data << "\t";

        cout << "\npress 0 to exit, or others as input\n";
    }
}
