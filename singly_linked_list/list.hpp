#ifndef _LIST_H
#define _LIST_H

#include "node.hpp"

//TODO copy constructor
//TODO overload assignment operator

template <class T> class list {
        private:
                node<T> *head;
                void push(node<T> *cur, T val);
                void kill(node<T> *cur);
                static std::ostream& print(std::ostream& out, node<T> *n);

        public:
                list() : head(0) { }
                void push(T val);
                friend std::ostream& operator<<(std::ostream& out, const list& l) { return print(out, l.head); }
                ~list();
};

template <class T> void list<T>::push(T val)
{
        if (head == 0)
                head = new node<T>(val);
        else
                push(head, val);
}

template <class T> void list<T>::push(node<T>* cur, T val)
{
        if (cur->nxt != 0)
                push(cur->nxt, val);
        else 
                cur->nxt = new node<T>(val);
}

template <class T> std::ostream& list<T>::print(std::ostream& out, node<T> *n)
{
        out << *n;
        if (n->nxt != 0) {
                out << " ";
                print(out, n->nxt);
        }
        return out;
}

template <class T> list<T>::~list()
{
        if (head != 0) {
                kill(head);
        }
}

template <class T> void list<T>::kill(node<T> *cur)
{
        if (cur != 0) 
                kill(cur->nxt);
        delete cur;
}

#endif
