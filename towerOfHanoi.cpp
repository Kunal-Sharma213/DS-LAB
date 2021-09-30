#include <iostream>
using namespace std;
void TOH(int n, int A, int B, int C)
{
    if (n > 0)
    {
        TOH(n - 1, A, C, B);
        cout << "Disk moved from " << A << " to " << C << '\n';
        TOH(n - 1, B, A, C);
    }
}
int main()
{
    cout << "Enter number of disks\n";
    int n;
    cin >> n;
    TOH(n, 1, 2, 3);
}