#include <iostream>
#include <list>
#include <cmath>
#include <limits.h>
using namespace std;
class Node
{
public:
    int num;
    int size;
    Node *next;
    Node *prev;
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
    void radixSort(int *, int, int);
    void listSize();
} * start, *save, *node, *ptr, *rear;
Node *Node ::createNode(int num)
{
    ptr = new Node;
    ptr->num = num;
    ptr->next = NULL;
    ptr->prev = NULL;
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
    }
    else
    {
        node->next = start;
        start->prev = node;
        start = node;
    }
}
void Node::insertEnd()
{
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
        }

        else
        {
            rear->next = node;
            node->prev = rear;
            rear = node;
        }
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
        node->next = temp;
        temp->prev = node;
        start = node;
    }
    else
    {
        while (temp->num != n && temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp->num != n)
        {
            cout << "Node with given value not found\n";
            return;
        }
        else
        {
            node->next = temp;
            temp->prev = node;
            prev->next = node;
            node->prev = prev;
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
        return;
    }
    else
    {
        if (temp->next == NULL)
        {
            temp->next = node;
            node->prev = temp;
            rear = temp;
        }
        else
        {
            node->next = temp->next;
            node->prev = temp;
            temp->next->prev = node;
            temp->next = node;
        }
    }
}
void Node::listSize()
{
    int length = 0;
    Node *temp = start;
    while (temp)
    {
        length++;
        temp = temp->next;
    }
    size = length;
    cout << "Size of the linked list -> " << size << '\n';
}
void Node ::display()
{
    Node *temp = start;
    while (temp)
    {
        cout << temp->num << " -> ";
        temp = temp->next;
    }
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
        start = temp->next;
        delete (temp);
        size--;
        return;
    }
    else
    {
        while (temp)
        {
            if (temp->num == num)
            {
                if (temp->next == NULL)
                {
                    Node *p;
                    p = temp;
                    prev->next = NULL;
                    delete (p);
                    index = -1;
                    size--;
                    break;
                }
                Node *p;
                p = temp;
                prev->next = temp->next;
                temp->next->prev = prev;
                delete (p);
                index = -1;
                size--;
                break;
            }
            else
            {
                index++;
                prev = temp;
                temp = temp->next;
            }
        }
    }
    if (index != -1)
        cout << "Node not found\n";
}
void Node ::reverse()
{
    Node *p = start;
    Node *temp;
    while (p != NULL)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if (p != NULL && p->next == NULL)
        {
            start = p;
        }
    }
}
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void Node ::radixSort(int *arr, int n, int digits)
{
    int i, j, m, p = 1, index, temp, count = 0;
    list<int> pocket[10];
    for (i = 0; i < digits; i++)
    {
        m = pow(10, i + 1);
        p = pow(10, i);
        for (j = 0; j < n; j++)
        {
            temp = arr[j] % m;
            index = temp / p;
            pocket[index].push_back(arr[j]);
        }
        count = 0;
        for (j = 0; j < 10; j++)
        {

            while (!pocket[j].empty())
            {
                arr[count] = *(pocket[j].begin());
                pocket[j].erase(pocket[j].begin());
                count++;
            }
        }
    }
}
void Node ::sort()
{
    Node *temp = start;
    int *arr = new int[size];
    int i = 0;
    int mx = INT_MIN;
    while (temp)
    {
        arr[i] = temp->num;
        temp = temp->next;
        if (arr[i] > mx)
            mx = arr[i];
        i++;
    }
    for (int i = 0; i < size; i++)
        cout << arr[i] << '\t';
    int digits = 0;
    while (mx)
    {
        digits++;
        mx = mx / 10;
    }
    cout << digits << '\n';
    radixSort(arr, size, digits);
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
}