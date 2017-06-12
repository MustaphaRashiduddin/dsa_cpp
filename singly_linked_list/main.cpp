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
        cout << "l1" << l1 << split;
        list<player> l2{l1};
        l2.push(player(6, "bang", 18));
        l2.push(player(7, "smash", 10));
        l1 = std::move(l2);
        cout << "l1 after moving l2 into it: " << l1 << split;
        if (!l2.head) cout << "state of l2's head: null" << endl;

        return 0;
}
