#include <iostream>

using std::cout;
using std::endl;

void mergesort(int[], unsigned l, unsigned r);
void parr(int[], unsigned);
void merge(int[], unsigned, unsigned, unsigned);

int main(int argc, char **argv)
{
        int arr[] = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};
        // int arr[] = {8, 3, 1, 7, 0, 10, 2};
        // int arr[] = {108, 15, 50, 4, 8, 42, 23, 16};
        // int arr[] = {38, 27, 43, 3, 9, 82, 10};
        int sz = sizeof arr / sizeof *arr;
        parr(arr, sz);
        mergesort(arr, 0, sz-1);
        parr(arr, sz);
        return 0;
}

void mergesort(int arr[], unsigned l, unsigned r)
{
        if (l<r) {
                unsigned m = l + (r-l) / 2;
                mergesort(arr, l, m);
                mergesort(arr, m+1, r);
                merge(arr, l, m, r);
        }
}

void parr(int arr[], unsigned l, unsigned r)
{
        for (int i=l; i<r; i++)
                cout << arr[i] << " ";
        cout << endl;
}

void merge(int arr[], unsigned l, unsigned m, unsigned r)
{
        unsigned l_sz = m-l+1;
        unsigned r_sz = r-m;
        int L[l_sz];
        int R[r_sz];
        for (int i=l; i<m+1; i++)
                L[i-l] = arr[i];
        for (int i=m+1; i<r+1; i++)
                R[i-m-1] = arr[i];

        int i = 0;
        int j = 0;
        int k = l;
        while (1) {
                if (i < l_sz && L[i] < R[j]) {
                        arr[k] = L[i];
                        ++i;
                        ++k;
                } else if (j < r_sz && L[i] >= R[j]) {
                        arr[k] = R[j];
                        ++j;
                        ++k;
                } else if (k == r+1 || i == l_sz || j == r_sz) {
                        break;
                }
        }
        while (i < l_sz) {
                arr[k] = L[i];
                ++i;
                ++k;
        }
        while (j < r_sz) {
                arr[k] = R[j];
                ++j;
                ++k;
        }
}

void parr(int arr[], unsigned sz)
{
        for (int i=0; i<sz; i++)
                cout << arr[i] << " ";
        cout << endl;
}
