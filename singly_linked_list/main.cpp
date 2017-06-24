#include <iostream>
#include "list.hpp"
#include "../utilities/player.hpp"
#include "../utilities/split.hpp"

using std::cout;
using std::endl;
using std::string;
using std::move;

int main(int argc, char *argv[])
{
        list<player> l1;
        l1.push(player(1, "saif", 11));
        l1.push(player(3, "ali", 33));
        l1.push(player(5, "bob", 38));
        if (l1.head) cout << *l1.del(3) << split;
        cout << l1 << split;
        if (l1.head) cout << *l1.del(1) << split;
        cout << l1 << split;
        cout << *l1.del(5) << split;
        if (!l1.head) cout << "null" << endl;

        return 0;
}
