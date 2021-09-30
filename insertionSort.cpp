#include <iostream>
using namespace std;
void insertionSort(int *A, int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int x = A[i];
        while (j > -1 && A[j] > x)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
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
    insertionSort(arr, n);
    cout << "Sorted array is -> \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << '\t';
}