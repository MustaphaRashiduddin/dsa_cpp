#ifndef _NODE_H
#define _NODE_H

#include <ostream>

template <class T> struct node {
        T *dat;
        node *nxt;
        node(T dat) : dat(new T(dat)), nxt(0) { }
        node(const node& obj);
        void operator=(const node& obj);
        friend std::ostream& operator<< (std::ostream& out, const node& p) { return out << *p.dat; }
        ~node() { delete dat; }
};

template <class T> node<T>::node(const node& obj) 
{ 
        dat = new T(*obj.dat);
        nxt = obj.nxt; 
}

template <class T> void node<T>::operator=(const node& obj)
{
        *dat = *obj.dat;
        nxt = obj.nxt;
}

#endif
