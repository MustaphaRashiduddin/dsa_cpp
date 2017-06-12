#ifndef _LIST_H
#define _LIST_H

#include "node.hpp"

template <class T> class list {
        private:
                std::unique_ptr<node<T>> head;
                std::unique_ptr<node<T>> push(std::unique_ptr<node<T>> cur, T val);

                // methods
                std::unique_ptr<node<T>> deep_copy(std::unique_ptr<node<T>> lhs_node, const node<T> *rhs_node); 
                static std::ostream& print(std::ostream& out, const node<T> *cur);

        public:
                bool exist() { return head != nullptr; }
                list() : head{nullptr} { }
                void push(T val);
                friend std::ostream& operator<<(std::ostream& out, list& l) { return print(out, l.head.get()); }

                // rule of 5
                list(list& obj); // copy constructor
                void operator=(const list& obj); // copy assignment operator
                list(list&& obj); // move constructor
                void operator=(list&& obj); // move assignment operator
                ~list() { }
};

// copy constructor
template <class T> list<T>::list(list& obj)
{
        if (obj.head)
                head = deep_copy(std::move(head), obj.head.get());
}

// copy assignment operator
template <class T> void list<T>::operator=(const list& obj)
{
        head = nullptr;
        if (obj.head)
                head = deep_copy(std::move(head), obj.head.get());
}

// move constructor
template <class T> list<T>::list(list&& obj) : head{nullptr}
{
        std::swap(head, obj.head);
}

// move assignment operator
template <class T> void list<T>::operator=(list&& obj)
{
        head = nullptr;
        std::swap(head, obj.head);
        obj.head = nullptr;
}

template <class T> std::unique_ptr<node<T>> list<T>::deep_copy(std::unique_ptr<node<T>> lhs_node, const node<T> *rhs_node) 
{
        lhs_node = std::unique_ptr<node<T>>{new node<T>{*rhs_node}};
        if (rhs_node->nxt)
                lhs_node->nxt = deep_copy(std::move(lhs_node->nxt), rhs_node->nxt.get());
        return lhs_node;
}


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

template <class T> std::ostream& list<T>::print(std::ostream& out, const node<T> *cur)
{
        out << *cur;
        if (cur->nxt != nullptr) {
                out << " ";
                print(out, cur->nxt.get());
        }
        return out;
}

#endif
