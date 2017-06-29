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
        l1.push(player(8, "spam", 40));
        l1.push(player(9, "jo", 10));
        cout << "prv bonanza: " << *l1.tail->prv->prv->prv->prv << split;
        cout << l1 << split;
        l1.pop();
        cout << l1 << split;
        l1.pop();
        l1.pop();
        cout << l1 << split;
        cout << "a pop: " << *l1.pop() << split;
        cout << l1 << split;
        cout << "popped: " << *l1.pop() << split;
        if (!l1.head) cout << "l1 is empty" << endl;

        return 0;
}
