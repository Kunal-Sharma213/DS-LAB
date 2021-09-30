#include <iostream>

using namespace std;

class Queue
{
private:
    int size;
    int front;
    int rear;
    int *Q;

public:
    Queue(int size);
    ~Queue();
    bool isFull();
    bool isEmpty();
    void enqueue(int x);
    int dequeue();
    void display();
};

Queue::Queue(int size)
{
    this->size = size;
    front = -1;
    rear = -1;
    Q = new int[size];
}

Queue::~Queue()
{
    delete[] Q;
}

bool Queue::isEmpty()
{
    if (front == rear)
    {
        return true;
    }
    return false;
}

bool Queue::isFull()
{
    if (rear == size - 1)
    {
        return true;
    }
    return false;
}

void Queue::enqueue(int x)
{
    if (isFull())
    {
        cout << "Queue Overflow" << endl;
    }
    else
    {
        rear++;
        Q[rear] = x;
    }
}

int Queue::dequeue()
{
    int x = -1;
    if (isEmpty())
    {
        cout << "Queue Underflow" << endl;
    }
    else
    {
        front++;
        x = Q[front];
    }
    return x;
}

void Queue::display()
{
    for (int i = front + 1; i <= rear; i++)
    {
        cout << Q[i] << flush;
        if (i < rear)
        {
            cout << " -> " << flush;
        }
    }
    cout << endl;
}

int main()
{

    cout << "Enter the length of the queue\n";
    int n;
    cin >> n;
    Queue q(n);
    cout << "Enter the elements of the queue\n";
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        q.enqueue(num);
    }
    cout << "Queue is -> \n";
    q.display();

    cout << "Want to dequeue?(y/n) \n";
    char ch;
    cin >> ch;
    while (ch == 'y')
    {
        int ele = q.dequeue();
        if (ele != -1)
        {
            cout << "Element popped -> " << ele << '\n';
            cout << "Want to dequeue more ?(y/n) \n";
            cin >> ch;
        }
        else
        {
            break;
        }
    }
    cout << "Queue Empty: " << q.isEmpty() << '\n';
}