#ifndef _LIST_H
#define _LIST_H

#include "node.hpp"

namespace _list {
        template <class T> std::unique_ptr<node<T>> push(std::unique_ptr<node<T>> cur, T& val);
        template <class T> std::unique_ptr<node<T>> deep_copy(std::unique_ptr<node<T>> lhs_node, const node<T> *const rhs_node); 
        template <class T> std::ostream& print(std::ostream& out, const node<T> *const cur);
        template <class T> std::unique_ptr<T> pop(node<T> *cur);
        template <class T> std::unique_ptr<node<T>> insert(std::unique_ptr<node<T>> cur, int id, T dat);
        template <class T> std::unique_ptr<T> del(node<T> *cur, int id);
}

template <class T> struct list {
        // data members
        std::unique_ptr<node<T>> head;

        // methods
        list() : head{nullptr} { }
        void push(T&& val);
        std::unique_ptr<T> pop(); 
        void insert(int id, T dat) { head = _list::insert(std::move(head), id, dat); };
        void insert(T dat); // insert at head 
        std::unique_ptr<T> del(int id);

        // rule of 5
        list(list& obj); // copy constructor
        void operator=(const list& obj); // copy assignment operator
        list(list&& obj) : head{nullptr} { std::swap(head, obj.head); } // move constructor
        void operator=(list&& obj); // move assignment operator
        ~list() { }

        // overloaded operators
        friend std::ostream& operator<<(std::ostream& out, list& l) { return _list::print(out, l.head.get()); }
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

// move assignment operator
template <class T> void list<T>::operator=(list&& obj)
{
        head = nullptr;
        std::swap(head, obj.head);
        obj.head = nullptr;
}

template <class T> std::unique_ptr<node<T>> deep_copy(std::unique_ptr<node<T>> lhs_node, const node<T> *const rhs_node) 
{
        lhs_node = std::unique_ptr<node<T>>{new node<T>{*rhs_node}};
        if (rhs_node->nxt)
                lhs_node->nxt = deep_copy(std::move(lhs_node->nxt), rhs_node->nxt.get());
        return lhs_node;
}

template <class T> void list<T>::push(T&& val)
{
        if (head == nullptr)
                head = std::unique_ptr<node<T>>{new node<T>{val}};
        else
                head = _list::push(std::move(head), val);
}

template <class T> std::unique_ptr<node<T>> _list::push(std::unique_ptr<node<T>> cur, T& val)
{
        if (cur->nxt != nullptr) {
                cur->nxt = _list::push(std::move(cur->nxt), val);
                return cur;
        } else {
                cur->nxt = std::unique_ptr<node<T>>{new node<T>{val}};
                return cur;
        }
}

template <class T> std::ostream& _list::print(std::ostream& out, const node<T> *const cur)
{
        out << *cur;
        if (cur->nxt != nullptr) {
                out << " ";
                _list::print(out, cur->nxt.get());
        }
        return out;
}

template <class T> std::unique_ptr<T> list<T>::pop()
{
        if (!head->nxt) {
                std::unique_ptr<T> dat = std::move(head->dat);
                head = nullptr;
                return dat;
        }
        return _list::pop(head.get()); 
}

template <class T> std::unique_ptr<T> _list::pop(node<T> *cur)
{
        if (cur->nxt->nxt != nullptr)
                return std::move(_list::pop(cur->nxt.get()));
        std::unique_ptr<T> dat = std::move(cur->nxt->dat);
        cur->nxt = nullptr;
        return dat;
}

template <class T> std::unique_ptr<node<T>> _list::insert(std::unique_ptr<node<T>> cur, int id, T dat)
{
        while (cur->nxt && cur->dat->id != id) {
                cur->nxt = _list::insert(std::move(cur->nxt), id, dat);
                return cur;
        }

        std::unique_ptr<node<T>> mNode = nullptr;
        if (cur->dat->id == id) {
                std::unique_ptr<T> mDat{new T{dat}};
                mNode = std::unique_ptr<node<T>>{new node<T>{*mDat}};
        } else {
                return cur;
        }

        if (cur->nxt) 
                mNode->nxt = std::move(cur->nxt);
        cur->nxt = std::move(mNode);
        return cur;
}

template <class T> void list<T>::insert(T dat)
{
        std::unique_ptr<node<T>> temp = std::move(head);
        std::unique_ptr<T> mDat{new T{dat}};
        std::unique_ptr<node<T>> mNode{new node<T>{*mDat}};
        mNode->nxt = std::move(temp);
        head = std::move(mNode);
}

template <class T> std::unique_ptr<T> list<T>::del(int id)
{
        if (head->dat->id == id) {
                std::unique_ptr<T> dat = std::move(head->dat);
                head = std::move(head->nxt);
                return dat;
        }
        return _list::del(head.get(), id);
}

template <class T> std::unique_ptr<T> _list::del(node<T> *cur, int id)
{
        if (id != cur->nxt->dat->id)
                return _list::del(cur->nxt.get(), id);
        std::unique_ptr<T> dat = std::move(cur->nxt->dat);
        cur->nxt = std::move(cur->nxt->nxt);
        return dat;
}

#endif
