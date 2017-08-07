#include <iostream>
#include "node.hpp"

using std::unique_ptr;
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
        // node(T dat) : dat{new T(dat)}, r{nullptr}, l{nullptr} { }
        node<int> root{node<int>{3}};
        cout << root << endl;
}
