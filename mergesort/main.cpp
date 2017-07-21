#include <vector>
#include <iostream>
#include "mylist.hpp"

using std::vector;
using std::list;
using std::cout;
using std::endl;
using std::string;

vector<int> merge_sort(vector<int>&, vector<int>&);
void merge_sort(mylist<vector<int>>&);
void split(mylist<vector<int>>&, vector<int>&);
void pvec(string&&, vector<int>);

int main (int argc, char **argv)
{
        // vector<int> v = {108, 15, 50, 4, 8, 42, 23, 16, 32, 40, 0, 42};
        vector<int> v = {8, 3, 1, 7, 0, 10, 2};
        mylist<vector<int>> lv; // list of a vector
        split(lv, v);
        if (lv._size > 1)
                merge_sort(lv);
        for (list<vector<int>>::const_iterator i=lv._list.begin(); i!=lv._list.end(); i++)
                pvec("lv", *i);
        return 0;
}

void merge_sort(mylist<vector<int>>& lv)
{
        if (lv._size %2 == 0) {
                for (list<vector<int>>::iterator i=lv._list.begin(); i!=lv._list.end(); ++i) {
                        *i = merge_sort(*i, *(++i));
                        lv.erase(i); // constant complexity for list
                }
        } else {
                lv._one_before = lv._list.end();
                lv._one_before--; // complexity of setting one_before is constant (always 2 steps)
                for (list<vector<int>>::iterator i=lv._list.begin(); i!=lv._one_before; ++i) {
                        *i = merge_sort(*i, *(++i));
                        lv.erase(i);
                }

                list<vector<int>>::iterator b=lv._list.begin();
                *b = merge_sort(*b, *lv._one_before);
                lv.erase(lv._one_before); // one before is never erased until the very end of this else case
        }

        if (lv._size != 1)
                merge_sort(lv);
}

vector<int> merge_sort(vector<int>& arr1, vector<int>& arr2)
{
        vector<int> merged;
        int i=0;
        int j=0;
        while (!(i == arr1.size() && j == arr2.size()))
                if (j == arr2.size() || (i < arr1.size() && arr1[i] < arr2[j]))
                        merged.push_back(arr1[i++]);
                else 
                        merged.push_back(arr2[j++]);

        return merged;
}

void split(mylist<vector<int>>& lv, vector<int>& v)
{
        vector<int> a;
        vector<int> b;
        int inc = 0;
        for (int i=0; i<v.size()/2; i++) {
                a.push_back(v[i]);
                inc = i;
        }
        for (int i=inc+1; i<v.size(); i++)
                b.push_back(v[i]);

        if (a.size() != 1)
                split(lv, a);
        else 
                lv.push_back(a);
        if (b.size() != 1)
                split(lv, b);
        else 
                lv.push_back(b);
}

void pvec(string&& lbl, vector<int> v)
{
        cout << lbl << ": ";
        for (int i=0; i<v.size(); i++)
                cout << v[i] << " ";
        cout << endl;
}
