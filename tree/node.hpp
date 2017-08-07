#ifndef _NODE_H
#define _NODE_H

#include <ostream>
#include <memory>
#include <iostream>

template <class T> struct node {
        node(T dat) : dat{new T(dat)}, r{nullptr}, l{nullptr} { }
        std::unique_ptr<T> dat;
        std::unique_ptr<node> r;
        std::unique_ptr<node> l;

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
template <class T> node<T>::node(const node& obj) : r{nullptr}, l{nullptr}
{ 
        dat = std::unique_ptr<T>{new T{*obj.dat}};
}

// copy assignment operator
template <class T> void node<T>::operator=(const node& obj)
{
        *dat = *obj.dat;
        r = obj.r;
        l = obj.l;
}

// move constructor
template <class T> node<T>::node(node&& obj) : dat{nullptr}, r{nullptr}, l{nullptr}
{ 
        std::swap(dat, obj.dat);
        std::swap(r, obj.r);
        std::swap(l, obj.l);
}

// move asignment operator
template <class T> void node<T>::operator=(node&& obj)  
{ 
        std::swap(dat, obj.dat);
        std::swap(r, obj.r);
        std::swap(l, obj.l);
        obj.dat = nullptr;
        obj.r = nullptr;
        obj.l = nullptr;
}  

#endif
