#ifndef _LIST_H
#define _LIST_H

#include "node.hpp"

namespace list_ {
        template <class T> std::unique_ptr<node<T>> deep_copy(std::unique_ptr<node<T>> lhs_node, const node<T> *const rhs_node); 
        template <class T> std::ostream& print(std::ostream& out, const node<T> *const cur);
        // template <class T> std::unique_ptr<node<T>> insert(std::unique_ptr<node<T>> cur, int id, T dat);
        template <class T> std::unique_ptr<T> del(node<T> *cur, int id);
}

template <class T> struct list {
        // data members
        std::unique_ptr<node<T>> head;
        node<T> *tail;

        // methods
        list() : head{nullptr}, tail{nullptr} { }
        void push(T&& val);
        std::unique_ptr<T> pop(); 
        void insert(int id, T dat) { head = insert(std::move(head), id, dat); };
        std::unique_ptr<node<T>> insert(std::unique_ptr<node<T>> cur, int id, T dat);
        void insert(T dat); // insert at head 
        std::unique_ptr<T> del(int id);

        // rule of 5
        list(list& obj); // copy constructor
        void operator=(const list& obj); // copy assignment operator
        list(list&& obj) : head{nullptr} { std::swap(head, obj.head); } // move constructor
        void operator=(list&& obj); // move assignment operator
        ~list() { }

        // overloaded operators
        friend std::ostream& operator<<(std::ostream& out, list& l) { return list_::print(out, l.head.get()); }
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
        if (head == nullptr) {
                head = std::unique_ptr<node<T>>{new node<T>{val}};
        } else {
                std::unique_ptr<node<T>> tmp = std::unique_ptr<node<T>>{new node<T>{val}};
                if (!tail) {
                        tmp->prv = head.get();
                        head->nxt = std::move(tmp);
                        tail = head->nxt.get();
                } else {
                        tail->nxt = std::move(tmp);
                        node<T> *tmp2 = tail;
                        tail = tail->nxt.get();
                        tail->prv = tmp2;
                }
        }
}

template <class T> std::ostream& list_::print(std::ostream& out, const node<T> *const cur)
{
        out << *cur;
        if (cur->nxt != nullptr) {
                out << " ";
                list_::print(out, cur->nxt.get());
        }
        return out;
}

template <class T> std::unique_ptr<T> list<T>::pop()
{
        std::unique_ptr<T> dat = std::move(tail->dat);
        if (tail->prv) {
                tail = tail->prv;
                tail->nxt = nullptr;
        } else {
                head = nullptr;
        }
        return dat;
}

template <class T> std::unique_ptr<node<T>> list<T>::insert(std::unique_ptr<node<T>> cur, int id, T dat)
{
        while (cur->nxt && cur->dat->getid() != id) {
                cur->nxt = insert(std::move(cur->nxt), id, dat);
                return cur;
        }

        std::unique_ptr<node<T>> mNode = nullptr;
        if (cur->dat->getid() == id) {
                std::unique_ptr<T> mDat{new T{dat}};
                mNode = std::unique_ptr<node<T>>{new node<T>{*mDat}};
        } else {
                return cur;
        }

        if (cur->nxt) {
                cur->nxt->prv = mNode.get();
                mNode->nxt = std::move(cur->nxt);
        }
        mNode->prv = cur.get();
        cur->nxt = std::move(mNode);
        if (tail->nxt) tail = cur->nxt.get();
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
        return list_::del(head.get(), id);
}

template <class T> std::unique_ptr<T> list_::del(node<T> *cur, int id)
{
        if (id != cur->nxt->dat->id)
                return list_::del(cur->nxt.get(), id);
        std::unique_ptr<T> dat = std::move(cur->nxt->dat);
        cur->nxt = std::move(cur->nxt->nxt);
        return dat;
}

#endif
