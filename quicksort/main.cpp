#include <iostream>

using std::cout;
using std::endl;
using std::swap;

void qsort(int[], unsigned, unsigned);
void parr(int[], unsigned);

int main(int argc, char **argv)
{
        // int arr[] = {8, 3, 1, 7, 0, 10, 2};
        int arr[] = {108, 15, 50, 4, 8, 42, 23, 16};
        int arr_sz = sizeof arr / sizeof *arr;
        parr(arr, arr_sz);
        qsort(arr, 0, arr_sz);
        parr(arr, arr_sz);
        return 0;
}

void qsort(int arr[] , unsigned l, unsigned r)
{
        int p = r-1;
        for (int i=l; i<r; i++) {
                if (arr[l] > arr[p]) {
                        swap(arr[l], arr[p]);
                        swap(arr[l], arr[p-1]);
                        --p;
                } else {
                        ++l;
                }
        }
        if (p != -1) qsort(arr, 0, p);
        if (l != r) qsort(arr, l, r);
}

void parr(int arr[], unsigned sz)
{
        for (int i=0; i<sz; i++)
                cout << arr[i] << " ";
        cout << endl;
}
