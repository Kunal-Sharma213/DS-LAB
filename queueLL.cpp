#include <iostream>
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
    int isEmpty();
    void listSize();

} * start, *rear, *ptr;
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
    }

    else
    {
        rear->next = node;
        rear = node;
    }
}
int Node::dequeue()
{
    if (isEmpty())
    {
        cout << "Empty Queue\n";
        return -1;
    }
    Node *p = start;
    start = start->next;
    cout << "Element popped -> " << p->num << '\n';
    delete p;
    return 1;
}
int Node ::isEmpty()
{
    if (start == NULL)
        return 1;
    else
        return 0;
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
int main()
{
    start = rear = NULL;
    Node obj;
    char ch = 'y';
    while (ch == 'y')
    {
        obj.enqueue();
        cout << "Want to push more elements?(y/n)\n";
        cin >> ch;
    }
    cout << "Queue is -> \n";
    obj.display();
    cout << "Want to pop some elements?(y/n)\n";
    cin >> ch;
    int res;
    while (ch == 'y')
    {
        res = obj.dequeue();
        if (res != -1)
        {
            cout << "Updated Queue is -> \n";
            obj.display();
            cout << "Want to pop more elements?(y/n)\n";
            cin >> ch;
        }
        else
            break;
    }
}