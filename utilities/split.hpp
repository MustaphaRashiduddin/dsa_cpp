#ifndef _SPLIT_H
#define _SPLIT_H

#include <iostream>

struct split {
        friend std::ostream& operator<< (std::ostream& out, const split& s) { return out << std::endl << "---------------" << std::endl; }
};
split split;

#endif
