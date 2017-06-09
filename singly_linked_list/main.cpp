#include <iostream>
#include "list.hpp"
#include "../player.hpp"
#include "split.hpp"

using std::cout;
using std::endl;


int main(int argc, char *argv[])
{
        list<player> l;
        l.push(player(1, "saif", 11));
        l.push(player(3, "ali", 33));
        l.push(player(2, "mahdi", 48));
        l.push(player(5, "bob", 38));
        cout << l << split;
        return 0;
}
