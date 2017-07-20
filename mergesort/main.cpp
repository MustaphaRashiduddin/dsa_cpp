#include <vector>
#include <list>
#include <iostream>

using std::vector;
using std::list;
using std::cout;
using std::endl;
using std::string;

vector<int> merge_sort(vector<int>&, vector<int>&);
void merge_sort(list<vector<int>>&);
void split(list<vector<int>>&, vector<int>&);
void pvec(string&&, vector<int>);

int main (int argc, char **argv)
{
        /*
         * vector<int> arr1 = {4, 15, 16, 50};
         * vector<int> arr2 = {8, 23, 42, 108};
         */
        vector<int> v = {108, 15, 50, 4, 8, 42, 23, 16};
        list<vector<int>> lv;
        split(lv, v);
        merge_sort(lv);
        merge_sort(lv);
        merge_sort(lv);
        for (list<vector<int>>::const_iterator i=lv.begin(); i!=lv.end(); i++)
                pvec("lv", *i);
        return 0;
}

void merge_sort(list<vector<int>>& lv)
{
        for (list<vector<int>>::iterator i=lv.begin(); i!=lv.end(); ++i)
        {
                *i = merge_sort(*i, *(++i));
                lv.erase(i); // constant complexity for list
        }
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

        /*
         * pvec("arr1", arr1);
         * pvec("arr2", arr2);
         * pvec("merged", merged);
         */
        return merged;
}

void split(list<vector<int>>& lv, vector<int>& v)
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

        // printing stuff
        if (a.size() != 1)
                split(lv, a);
        else {
                // pvec("a", a);
                lv.push_back(a);
        }
        if (b.size() != 1)
                split(lv, b);
        else {
                // pvec("b", b);
                lv.push_back(b);
        }
}

void pvec(string&& lbl, vector<int> v)
{
        cout << lbl << ": ";
        for (int i=0; i<v.size(); i++)
                cout << v[i] << " ";
        cout << endl;
}
