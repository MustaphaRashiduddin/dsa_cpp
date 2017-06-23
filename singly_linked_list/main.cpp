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
        l1.head = list_::insert(std::move(l1.head), 3, player(8, "lolz5", 11));
        cout << l1 << split;
        return 0;
}
