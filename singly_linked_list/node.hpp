#ifndef _NODE_H
#define _NODE_H

#include <ostream>
#include <memory>
#include <iostream>

template <class T> struct node {
        node(T dat) : dat{new T(dat)}, nxt{nullptr} { }
        std::unique_ptr<T> dat;
        std::unique_ptr<node> nxt;

        // rule of 5
        node(const node& obj); // copy constructor
        void operator=(const node& obj); // copy assignment operator
        node(node&& obj); // move constructor
        void operator=(node&& obj); // move assignment operator
        ~node() { }

        // overloaded operators
        friend std::ostream& operator<<(std::ostream& out, const node& p) { return out << *p.dat; }
};

// copy constructor
template <class T> node<T>::node(const node& obj) : nxt{nullptr}
{ 
        dat = std::unique_ptr<T>{new T{*obj.dat}};
}

// copy assignment operator
template <class T> void node<T>::operator=(const node& obj)
{
        *dat = *obj.dat;
        nxt = obj.nxt;
}

// move constructor
template <class T> node<T>::node(node&& obj) : dat{nullptr}, nxt{nullptr}
{ 
        std::swap(dat, obj.dat);
        std::swap(nxt, obj.nxt);
}

// move asignment operator
template <class T> void node<T>::operator=(node&& obj)  
{ 
        std::swap(dat, obj.dat);
        std::swap(nxt, obj.nxt);
        obj.dat = nullptr;
        obj.nxt = nullptr;
}  

#endif
