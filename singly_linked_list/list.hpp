#ifndef _LIST_H
#define _LIST_H

#include "node.hpp"

//TODO copy constructor
//TODO overload assignment operator

template <class T> class list {
        public:
                std::unique_ptr<node<T>> head;
                std::unique_ptr<node<T>> push(std::unique_ptr<node<T>> cur, T val);
                static std::ostream& print(std::ostream& out, std::unique_ptr<node<T>> cur);

        public:
                list() : head{nullptr} { }
                void push(T val);
                friend std::ostream& operator<<(std::ostream& out, list& l) { return print(out, std::move(l.head)); }
                ~list() { }
};

template <class T> void list<T>::push(T val)
{
        if (head == nullptr)
                head = std::unique_ptr<node<T>>{new node<T>{val}};
        else
                head = push(std::move(head), val);
}

template <class T> std::unique_ptr<node<T>> list<T>::push(std::unique_ptr<node<T>> cur, T val)
{
        if (cur->nxt != nullptr) {
                cur->nxt = push(std::move(cur->nxt), val);
                return cur;
        } else  {
                cur->nxt = std::unique_ptr<node<T>>{new node<T>{val}};
                return cur;
        }
}

template <class T> std::ostream& list<T>::print(std::ostream& out, const std::unique_ptr<node<T>> cur)
{
        out << *cur;
        if (cur->nxt != nullptr) {
                out << " ";
                print(out, std::move(cur->nxt));
        }
        return out;
}

#endif
