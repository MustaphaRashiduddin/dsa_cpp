#include <iostream>
#include "list.hpp"
#include "../utilities/player.hpp"
#include "../utilities/split.hpp"

using std::cout;
using std::endl;
using std::string;

int main(int argc, char *argv[])
{
        list<player> l1;
        l1.push(player(1, "saif", 11));
        l1.push(player(3, "ali", 33));
        l1.push(player(2, "mahdi", 48));
        l1.push(player(5, "bob", 38));
        cout << l1 << split;
        list<player> l2{l1};
        l2.push(player(6, "bomb", 13));
        cout << l2 << split;
        list<player> l3{l1};
        cout << l3 << split;
        l3 = l2;
        cout << l3 << split;

        return 0;
}
