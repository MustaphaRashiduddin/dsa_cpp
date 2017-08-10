#ifndef _BTREE_HPP
#define _BTREE_HPP
#include "node.hpp"

typedef int T;

// template <class T>
struct btree {
        std::unique_ptr<node> root;

        btree() : root{nullptr} { }
        void insert(T *dat);
        void _insert(T *dat, node *cur);
        void print();
        void _print(node *cur);
};

void btree::insert(T* dat)
{
        if (!root) {
                root = std::unique_ptr<node>{new node{*dat}};
        } else {
                if (*dat > *root->dat) {
                        if (!root->r)
                                root->r = std::unique_ptr<node>{new node{*dat}};
                        else
                                _insert(dat, root->r.get());
                } else {
                        if (!root->l)
                                root->l = std::unique_ptr<node>{new node{*dat}};
                        else
                                _insert(dat, root->l.get());
                }
        }
}

void btree::print()
{
        _print(root.get());
}

void btree::_print(node *cur)
{
        // print nodes
}

void btree::_insert(T *dat, node *cur)
{
        if (*dat > *cur->dat.get()) {
                if (cur->r) 
                        _insert(dat, cur->r.get());
                else
                        cur->r = std::unique_ptr<node>{new node{*dat}};
        } else {
                if (cur->l)
                        _insert(dat, cur->l.get());
                else
                        cur->l = std::unique_ptr<node>{new node{*dat}};
        }
}

#endif
