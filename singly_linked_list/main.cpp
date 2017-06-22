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
        l1.push(player(2, "mahdi", 48));
        l1.push(player(5, "bob", 38));
        list<player> l2{move(l1)};
        // list<player> l2{l1};
        cout << l2 << split;
        if(!l1.head) cout << "null" << split;
        // cout << *l2.pop() << split;
        cout << l2 << split;
        l2.insert(2, player(6, "som", 13));
        cout << l2 << split;
        l2.insert(player(11, "hah", 33));
        cout << l2 << split;
        l2.head = list_::insert(std::move(l2.head), 3, player(8, "lolz5", 11));
        cout << l2 << split;
        l2.pop();
        cout << l2 << split;
        cout << *l2.del(8) << split;
        cout << l2 << endl;

        return 0;
}
