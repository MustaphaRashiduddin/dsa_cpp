#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

void merge_sort(vector<int>&, vector<int>&);

int main (int argc, char **argv)
{
        vector<int> arr1 = {9, 39, 55, 78, 86};
        vector<int> arr2 = {33, 45, 76, 78, 80};
        merge_sort(arr1, arr2);
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

        for (int i=0; i<merged.size(); i++)
                cout << merged[i] << " ";
}
