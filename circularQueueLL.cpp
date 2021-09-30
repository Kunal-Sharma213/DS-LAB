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
    void enqueue();
    void display();
    int dequeue();
    void listSize();
    int isEmpty();

} * start, *save, *node, *ptr, *rear;

Node *Node ::createNode(int num)
{
    ptr = new Node;
    ptr->num = num;
    ptr->next = NULL;
    return ptr;
}

void Node::enqueue()
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
int Node ::isEmpty()
{
    if (rear->next == NULL)
        return 1;
    return 0;
}
int Node ::dequeue()
{
    Node *temp;
    if (isEmpty())
    {
        cout << "Queue is Empty\n";
        return -1;
    }
    if (rear == start)
    {
        delete start;
        return 0;
    }
    Node *p = start;
    rear->next = start->next;
    start = start->next;
    cout << "Element popped -> " << p->num << '\n';
    delete p;
    size--;
    return 0;
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
int main()
{
    start = rear = NULL;
    char ch = 'y';
    Node obj;
    while (ch == 'y')
    {
        obj.enqueue();
        cout << "Want to enqueue more elements?(y/n)\n";
        cin >> ch;
    }
    obj.listSize();
    obj.display();
    cout << "Want to dequeue elements?(y/n)\n";
    cin >> ch;
    int res;
    while (ch == 'y')
    {
        res = obj.dequeue();
        if (res != -1)
        {
            obj.display();
            cout << "Want to dequeue more elements?(y/n)\n";
            cin >> ch;
        }
        else
            break;
    }
}