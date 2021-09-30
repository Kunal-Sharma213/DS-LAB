#include <iostream>
using namespace std;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int *A, int n)
{
    int flag = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(&A[j], &A[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            return;
        }
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
    bubbleSort(arr, n);
    cout << "Sorted array is -> \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << '\t';
}