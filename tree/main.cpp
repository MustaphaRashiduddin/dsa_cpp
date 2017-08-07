#include <iostream>
#include "node.hpp"

using std::unique_ptr;
using std::cout;
using std::endl;
using std::move;

int main(int argc, char **argv)
{
        // node(T dat) : dat{new T(dat)}, r{nullptr}, l{nullptr} { }
        node<int> root{node<int>{3}};
        unique_ptr<node<int>> r{new node<int>{5}};
        root.r = move(r);
        unique_ptr<node<int>> l{new node<int>{6}};
        root.l = move(l);
        cout << root << " " << *root.r << " " << *root.l << endl;
        return 0;
}
