#include <iostream>
#include <map>
#include <limits.h>
using namespace std;
class Node
{
public:
    int num;
    int size;
    Node *next;
    Node *createNode(int);
    void insertBegin();
    void insertEnd();
    void insertBefore();
    void insertAfter();
    void display();
    void del();
    void reverse();
    void sort();
    void countSort(int *, int, int);
    void radixSort(int *, int n);
    void listSize();

} * start, *save, *node, *ptr, *rear;

Node *Node ::createNode(int num)
{
    ptr = new Node;
    ptr->num = num;
    ptr->next = NULL;
    return ptr;
}

void Node::insertBegin()
{
    cout << "ENTER A NUMBER\n";
    cin >> num;
    Node *node;
    node = createNode(num);
    if (node)
        cout << "NODE CREATED SUCCESSFULLY\n";
    else
    {
        cout << "OVERFLOW!!!\n";
    }
    if (start == NULL)
    {
        start = rear = node;
        start->next = start;
    }
    else
    {
        node->next = start;
        rear->next = node;
        start = node;
    }
}

void Node::insertEnd()
{
    cout << "ENTER A NUMBER\n";
    cin >> num;
    Node *node;
    node = createNode(num);
    if (node)
        cout << "NODE CREATED SUCCESSFULLY\n";
    else
    {
        cout << "OVERFLOW!!!\n";
    }
    if (start == NULL)
    {
        start = rear = node;
        start->next = start;
    }

    else
    {
        node->next = start;
        rear->next = node;
        rear = node;
    }
}
void Node::insertBefore()
{
    cout << "Enter the node value before which the node is to be inserted\n";
    int n;
    cin >> n;
    cout << "Enter new node value\n";
    int nn;
    cin >> nn;
    Node *node = createNode(nn);
    Node *temp = start, *prev;
    if (temp->num == n)
    {
        node->next = start;
        rear->next = node;
        start = node;
    }
    else
    {
        while (temp->num != n && temp != NULL)
        {
            prev = temp;
            temp = temp->next;
        }

        if (!temp)
        {
            cout << "Node with given value not found\n";
        }
        else
        {
            node->next = temp;
            prev->next = node;
        }
    }
}
void Node::insertAfter()
{
    cout << "Enter the node value after which the node is to be inserted\n";
    int n;
    cin >> n;
    cout << "Enter new node value\n";
    int nn;
    cin >> nn;
    Node *node = createNode(nn);
    Node *temp = start;

    while (temp->num != n && temp != NULL)
    {
        temp = temp->next;
    }

    if (!temp)
    {
        cout << "Node with given value not found\n";
    }
    else
    {
        node->next = temp->next;
        temp->next = node;
    }
}
void Node ::display()
{
    Node *temp = start;
    do
    {
        cout << temp->num << " -> ";
        temp = temp->next;
    } while (temp != start);
    cout << " null\n";
}
void Node ::del()
{
    cout << "\nENTER THE NUMBER TO BE DELETED\n";
    int num;
    cin >> num;
    Node *temp, *prev;
    temp = start;
    int index = 0;
    if (temp->num == num)
    {
        rear->next = start->next;
        start = start->next;
        delete (temp);
        size--;
        return;
    }
    else
    {
        do
        {
            if (temp->num == num)
            {
                if (temp->next != start)
                {
                    Node *p;
                    p = temp;
                    prev->next = temp->next;
                    index = -1;
                    delete (p);
                    size--;
                    break;
                }
                else
                {
                    Node *p;
                    p = temp;
                    prev->next = start;
                    delete (p);
                    index = -1;
                    size--;
                    break;
                }
            }
            else
            {
                index++;
                prev = temp;
                temp = temp->next;
            }
        } while (temp != start);
    }
    if (index != -1)
        cout << "Node not found\n";
}
void Node::reverse()
{
    Node *p, *q, *r;
    p = start;
    q = r = NULL;
    do
    {
        if (!q)
        {
            q = p;
            p = p->next;
            q->next = rear;
            r = q;
            q = p;
            p = p->next;
        }
        else
        {
            q->next = r;
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
    } while (p != start);
    rear = start;
    start = q;
}
void Node ::countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
void Node::radixSort(int arr[], int n)
{

    int m = getMax(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
void Node::listSize()
{
    int length = 0;
    Node *temp = start;
    length++;
    temp = temp->next;

    while (temp)
    {
        if (temp == start)
            break;
        length++;
        temp = temp->next;
    }
    size = length;
    cout << "Size of the linked list -> " << size << '\n';
}
void Node ::sort()
{
    Node *temp = start;
    int *arr = new int[size];
    int i = 0;
    arr[i++] = temp->num;
    temp = temp->next;
    while (temp)
    {
        if (temp == start)
            break;
        arr[i++] = temp->num;
        temp = temp->next;
    }

    radixSort(arr, size);
    cout << "Sorted list -> \n";
    for (int i = 0; i < size; i++)
        cout << arr[i] << '\t';
}

int main()
{
    int choice, num;
    char ch = 'y';
    start = rear = NULL;
    Node obj;
    while (ch == 'y')
    {
        cout << "1 -> Beg\n2 -> End\n3 -> Before\n4 -> After\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            obj.insertBegin();
            break;
        case 2:
            obj.insertEnd();
            break;
        case 3:
            obj.insertBefore();
            break;
        case 4:
            obj.insertAfter();
            break;
        }
        obj.display();
        cout << '\n';

        cout << "WANT TO INSERT MORE?\n";
        cin >> ch;
    }
    obj.listSize();
    obj.del();
    obj.display();
    cout << "Reversing the linked List -> \n";
    obj.reverse();
    obj.display();
    obj.sort();
    // obj.display();
}