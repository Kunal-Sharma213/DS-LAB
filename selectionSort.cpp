#include <iostream>
using namespace std;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int *A, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int j;
        int k;
        for (j = k = i; j < n; j++)
        {
            if (A[j] < A[k])
            {
                k = j;
            }
        }
        swap(&A[i], &A[k]);
    }
}
int main()
{
    cout << "Enter length of the array\n";
    int n;
    cin >> n;
    cout << "Enter elements of the array\n";
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    selectionSort(arr, n);
    cout << "Sorted array is -> \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << '\t';
}