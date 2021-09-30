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
    void insert(Node **, int);
    void insertBegin();
    void insertEnd();
    void insertBefore();
    void insertAfter();
    void display();
    void del();
    int Delete(Node **, int);
    void reverse();
    void listSize();
    void sort();
} * start, *save, *ptr, *rear;

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
    }
    else
    {
        save = start;
        start = node;
        node->next = save;
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
    }

    else
    {
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
        save = start;
        start = node;
        node->next = save;
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
    if (temp->num == n)
    {
        node->next = temp->next;
        temp->next = node;
    }
    else
    {
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
                index++;
                prev = temp;
                temp = temp->next;
            }
        }
    }
    if (index != -1)
        cout << "Node not found\n";
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
void Node::reverse()
{
    Node *p, *q, *r;
    p = start;
    q = r = NULL;
    while (p)
    {
        if (!q)
        {
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
    }
    rear = start;
    start = q;
}
int Max(int A[], int n)
{
    int mymax = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > mymax)
        {
            mymax = A[i];
        }
    }
    return mymax;
}
void Node ::insert(Node **ptrBins, int idx)
{
    Node *temp = new Node;
    temp->num = idx;
    temp->next = NULL;

    if (ptrBins[idx] == NULL)
    {
        ptrBins[idx] = temp;
    }
    else
    {
        Node *p = ptrBins[idx];
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}
int Node ::Delete(Node **ptrBins, int idx)
{
    Node *p = ptrBins[idx];
    ptrBins[idx] = ptrBins[idx]->next;
    int x = p->num;
    delete p;
    return x;
}
void Node ::sort()
{
    int *arr = new int[size];
    Node *temp = start;
    for (int i = 0; i < size; i++)
    {
        arr[i] = temp->num;
        temp = temp->next;
    }
    int mymax = Max(arr, size);

    Node **bins = new Node *[mymax + 1];

    for (int i = 0; i < mymax + 1; i++)
    {
        bins[i] = nullptr;
    }

    for (int i = 0; i < size; i++)
    {
        insert(bins, arr[i]);
    }

    int i = 0;
    int j = 0;
    while (i < mymax + 1)
    {
        while (bins[i] != nullptr)
        {
            arr[j++] = Delete(bins, i);
        }
        i++;
    }

    delete[] bins;

    cout << "Sorted linked list -> \n";
    for (int i = 0; i < size; i++)
        cout << arr[i];
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