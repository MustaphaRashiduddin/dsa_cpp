#ifndef _MYLIST_HPP
#define _MYLIST_HPP
#include <list>

template <class T> struct mylist {
        std::list<T> _list;
        typename std::list<T>::iterator _one_before; // initialize in main
        unsigned _size;
        void push_back(T& e);
        void erase(typename std::list<T>::iterator i);

        mylist() { _size = 0; }
};

template <class T> void mylist<T>::push_back(T& e)
{
        _list.push_back(e);
        _size++;
}

template <class T> void mylist<T>::erase(typename std::list<T>::iterator i)
{
        _list.erase(i);
        _size--;
}

#endif
