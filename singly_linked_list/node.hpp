#ifndef _NODE_H
#define _NODE_H

#include <ostream>
#include <memory>

template <class T> struct node {
        std::unique_ptr<T> dat;
        std::unique_ptr<node> nxt;
        node(T dat) : dat{new T(dat)}, nxt{nullptr} { }
        node(const node& obj);
        void operator=(const node& obj);
        friend std::ostream& operator<<(std::ostream& out, const node& p) { return out << *p.dat; }
        ~node() { }
};

template <class T> node<T>::node(const node& obj) 
{ 
        dat = std::unique_ptr<T>{new T{*obj.dat}};
        nxt = obj.nxt; 
}

template <class T> void node<T>::operator=(const node& obj)
{
        *dat = *obj.dat;
        nxt = obj.nxt;
}

#endif
