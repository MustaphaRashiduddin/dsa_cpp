#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;
using std::string;

void merge_sort(vector<int>&, vector<int>&);
void split(vector<int>&);
void pvec(string&&, vector<int>&);

int main (int argc, char **argv)
{
        vector<int> arr1 = {9, 39, 55, 78, 86};
        vector<int> arr2 = {33, 45, 76, 78, 80};
        pvec("arr2", arr2);
        // vector<int> arr2 = {33, 45, 76, 78};
        // merge_sort(arr1, arr2);
        split(arr2);
        return 0;
}

void merge_sort(vector<int>& arr1, vector<int>& arr2)
{
        vector<int> merged;
        int i=0;
        int j=0;
        while (!(i == arr1.size() && j == arr2.size()))
                if (j == arr2.size() || (i < arr1.size() && arr1[i] < arr2[j]))
                        merged.push_back(arr1[i++]);
                else 
                        merged.push_back(arr2[j++]);

        pvec("arr1", arr1);
        pvec("arr2", arr2);
        pvec("merged", merged);
}

void split(vector<int> &v)
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
                split(a);
        else {
                pvec("a", a);
                pvec("b", b);
        }
        if (b.size() != 1)
                split(b);
        else {
                // pvec("b", b);
                // return;
        }
        
}

void pvec(string&& lbl, vector<int>& v)
{
        cout << lbl << ": ";
        for (int i=0; i<v.size(); i++)
                cout << v[i] << " ";
        cout << endl;
}
