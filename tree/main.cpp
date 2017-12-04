#include <iostream>
#include "node.hpp"
#include "btree.hpp"

using std::unique_ptr;
using std::cout;
using std::endl;
using std::move;

int main(int argc, char **argv)
{

        btree tree;
        int x = 4;
        int y = 8;
        int z = 12;
        int z2 = 16;
        tree.insert(&x);
        tree.insert(&y);
        tree.insert(&z);
        tree.insert(&z2);
        cout << *tree.root << " " << *tree.root->r << " " << *tree.root->r->r << " " << *tree.root->r->r->r;

        return 0;
}
