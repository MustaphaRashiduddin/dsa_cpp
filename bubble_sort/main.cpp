#include <iostream>

using std::swap;
using std::cout;
using std::endl;

void bubble_sort(int[], unsigned);
void parr(int[], unsigned);

int main()
{
        int arr[] = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};
        // int arr[] = {8, 3, 1, 7, 0, 10, 2};
        // int arr[] = {108, 15, 50, 4, 8, 42, 23, 16};
        // int arr[] = {38, 27, 43, 3, 9, 82, 10};
        int sz = sizeof arr / sizeof *arr;
        parr(arr, sz);
        bubble_sort(arr, sz);
        parr(arr, sz);
}

void bubble_sort(int arr[], unsigned sz)
{
        for (int i=0; i<sz-1; i++)
                for (int j=0; j<sz-1; j++)
                        if (arr[j] > arr[j+1])
                                swap(arr[j], arr[j+1]);
}

void parr(int arr[], unsigned sz)
{
        for (int i=0; i<sz; i++)
                cout << arr[i] << " ";
        cout << endl;
}
