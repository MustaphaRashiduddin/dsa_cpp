#include <iostream>
#include "node.hpp"
#include "btree.hpp"

using std::unique_ptr;
using std::cout;
using std::endl;
using std::move;

int main(int argc, char **argv)
{

        // works
        /*
         * node root{node{3}};
         * std::unique_ptr<node> new_node{new node{root}};
         * cout << root << " " << *new_node;
         */

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

        // works
        /*
         * unique_ptr<int> dat = std::unique_ptr<int>{new int(3)};
         * cout << *dat;
         */
        return 0;
}
