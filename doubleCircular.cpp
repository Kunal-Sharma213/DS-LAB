#include <iostream>
#include <limits.h>
#include <cstring>
#include <vector>
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
    void listSize();
    void sort();
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
        start->next = start->prev = start;
    }
    else
    {
        node->next = start;
        node->prev = rear;
        start->prev = node;
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
        start->next = start->prev = start;
    }

    else
    {
        node->next = start;
        rear->next = node;
        node->prev = rear;
        start->prev = node;
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
        node->next = temp;
        node->prev = rear;
        start->prev = node;
        rear->next = node;
        start = node;
    }
    else
    {
        while (temp->num != n && temp->next != start)
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

    while (temp->num != n && temp != start)
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
        if (temp->next == start)
        {
            node->prev = temp;
            node->next = start;
            temp->next = node;
            start->prev = node;
            rear = node;
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
void Node ::display()
{
    Node *temp = start;
    do
    {
        cout << temp->num << " -> ";
        temp = temp->next;
    } while (temp != start);
    cout << " \n";
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
        start->prev = rear;
        rear->next = start;
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
                    temp->next->prev = prev;
                    delete (p);
                    index = -1;
                    size--;
                    break;
                }
                else
                {

                    prev->next = start;
                    start->prev = prev;
                    rear = prev;
                    delete (temp);
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
void Node ::reverse()
{
    Node *temp = start;
    while (temp != rear)
    {
        Node *nextNode = temp->next;
        temp->next = temp->prev;
        temp->prev = nextNode;
        temp = nextNode;
    }
    temp->next = temp->prev;
    temp->prev = start;
    temp = start;
    start = rear;
    rear = temp;
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
    int mx = INT_MIN;
    int *arr = new int[size];
    int i = 0;
    do
    {
        arr[i++] = temp->num;
        if (temp->num > mx)
            mx = temp->num;
        temp = temp->next;
    } while (temp != start);
    vector<int> countArr(mx + 1, 0);
    for (int i = 0; i < size; i++)
        countArr[arr[i]]++;
    cout << '\n';
    cout << "Sorted list -> \n";
    for (int i = 0; i < mx + 1; i++)
    {
        if (countArr[i] != 0)
        {
            for (int j = 0; j < countArr[i]; j++)
            {
                cout << i << '\t';
            }
        }
    }
    cout << '\n';
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
    obj.sort();
    cout << "Reversing the linked list -> \n";
    obj.reverse();
    obj.display();
}