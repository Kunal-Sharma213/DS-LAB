#include <iostream>
#include <cstring>
#include <map>
using namespace std;
template <typename T>
class ADT
{
public:
    int totalSize;
    int usedSize;
    T *p;
    ADT<T>(){};
    ADT<T>(int totalSize, int usedSize)
    {
        this->totalSize = totalSize;
        this->usedSize = usedSize;
        this->p = new T[usedSize];
    }
    void input();
    void insert(int, T);
    void del(int);
    void display();
    int binary_search(T);
    int linear_search(T);
    void sort();
    void functions(int);
    T kth(int);
    void empty();
    ~ADT()
    {
        delete p;
    }
};
template <typename T>
void ADT<T>::input()
{
    for (int i = 0; i < usedSize; i++)
        cin >> p[i];
}
template <typename T>
void ADT<T>::insert(int ind, T ele)
{
    if (ind > totalSize)
    {
        cout << "Index greater than total capacity\n";
        return;
    }
    if (ind == -1)
    {
        int index = 0;
        for (int i = 0; i < usedSize; i++)
        {
            if (p[i] > ele)
            {
                index = i;
                break;
            }
        }
        if (index == 0)
        {
            p[usedSize] = ele;
        }
        else
        {
            for (int i = usedSize; i > index; i--)
            {
                p[i] = p[i - 1];
            }
            p[index] = ele;
        }
        usedSize++;
    }
    else
    {
        for (int i = usedSize; i > ind; i--)
        {
            p[i] = p[i - 1];
        }
        p[ind] = ele;
        usedSize++;
    }
}
template <typename T>
void ADT<T>::del(int ind)
{
    if (ind > totalSize)
    {
        cout << "Index greater than total capacity\n";
        return;
    }
    for (int i = ind; i < usedSize - 1; i++)
    {
        p[i] = p[i + 1];
    }
    usedSize--;
}
template <typename T>
int ADT<T>::linear_search(T ele)
{
    for (int i = 0; i < usedSize; i++)
    {
        if (p[i] == ele)
            return i;
    }
    return -1;
}
template <typename T>
int ADT<T>::binary_search(T ele)
{
    int lb = 0, ub = usedSize - 1;
    while (lb <= ub)
    {
        int mid = lb + (ub - lb) / 2;
        if (p[mid] == ele)
            return mid;
        else if (p[mid] > ele)
            ub = mid - 1;
        else
            lb = mid + 1;
    }
    return -1;
}
template <typename T>
void ADT<T>::sort()
{
    int min;
    for (int i = 0; i < usedSize - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < usedSize; j++)
        {
            if (p[j] < p[min])
                min = j;
        }
        T temp = p[i];
        p[i] = p[min];
        p[min] = temp;
    }
}
template <typename T>
T ADT<T>::kth(int k)
{
    if (k < usedSize)
        return p[k];
    return -1;
}
template <typename T>
void ADT<T>::empty()
{
    delete p;
}
template <typename T>
void ADT<T>::functions(int choice)
{
    switch (choice)
    {
    case 1:
    {
        cout << "Enter array elements\n";
        input();
        cout << "Displaying array elements\n";
        display();
        bool loop = true;
        while (loop)
        {
            cout << "Enter the element to be inserted\n";
            T ele;
            cin >> ele;
            insert(-1, ele);
            display();
            cout << "Enter the element which is to be deleted\n";
            cin >> ele;
            int check = binary_search(ele);
            if (check != -1)
            {
                del(check);
                display();
            }

            else
                cout << "Element not found\n";
            cout << "Enter k\n";
            int k;
            cin >> k;
            if (kth(k) != -1)
                cout << "Kth element of the array is -> " << kth(k) << "\n";
            else
                cout << "Index out of range\n";

            cout << "Want to continue?(1/0)\n";
            cin >> loop;
        }
        cout << "Emptying the array--\n";
        empty();
    }
    break;
    case 2:
    {
        cout << "Enter array elements\n";
        input();
        cout << "Displaying array elements\n";
        display();
        cout << "Enter the index and the element to be inserted\n";
        T ele;
        int ind;
        cin >> ind >> ele;
        insert(ind, ele);
        display();
        cout << "Enter the element which is to be deleted\n";
        cin >> ele;
        int check = linear_search(ele);
        if (check != -1)
        {
            del(check);
            display();
        }
        else
            cout << "Element not found\n";

        cout << "Sorting ---\n";
        sort();
        display();
        cout << "Enter k\n";
        int k;
        cin >> k;
        if (kth(k) != -1)
            cout << "Kth element of the array is -> " << kth(k) << "\n";
        else
            cout << "Index out of range\n";
        cout << "Emptying the array--\n";
        empty();
    }
    }
}
template <typename T>
void ADT<T>::display()
{
    // stringstream s1, s2;
    // s1 << &p[0];
    // long x, address;
    // s1 >> hex >> x;
    for (int i = 0; i < usedSize; i++)
    {
        // long index = x + 4 * (i);
        // s2 << hex << index;
        // s2 >> address;
        cout << &p[i] << " -> " << p[i] << '\n';
        // cout << p[i] << "\n";
        // s2.clear();
        // s2.str("");
    }
}
int main()
{
    cout << "Enter array size\n";
    int n;
    cin >> n;
    int capacity = 100;
    cout << "Data types available - int, long, float, double\n Choose one\n";
    string type;
    cin >> type;
    cout << "1 -> Ordered list\n";
    cout << "2 -> Unordered list\n";
    int choice;
    cin >> choice;
    enum e
    {
        INT = 1,
        LONG,
        FLOAT,
        DOUBLE
    };
    static map<string, int> editCases{
        {"int", INT},
        {"long", LONG},
        {"float", FLOAT},
        {"double", DOUBLE}};
    switch (editCases.at(type))
    {
    case INT:
    {
        ADT<int> a(capacity, n);
        a.functions(choice);
    }
    break;
    case LONG:
    {
        ADT<long> a(capacity, n);
        a.functions(choice);
    }
    break;
    case FLOAT:
    {
        ADT<float> a(capacity, n);
        a.functions(choice);
    }
    break;
    case DOUBLE:
    {
        ADT<double> a(capacity, n);
        a.functions(choice);
    }
    break;
    default:
        cout << "Invalid\n";
    }
}