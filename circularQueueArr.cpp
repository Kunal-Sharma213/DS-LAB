#include <iostream>

using namespace std;

class CircularQueue
{
private:
    int size;
    int front;
    int rear;
    int *Q;

public:
    CircularQueue(int size);
    ~CircularQueue();
    bool isFull();
    bool isEmpty();
    void enqueue(int x);
    int dequeue();
    void display();
};

CircularQueue::CircularQueue(int size)
{
    this->size = size;
    front = 0;
    rear = 0;
    Q = new int[size];
}

CircularQueue::~CircularQueue()
{
    delete[] Q;
}

bool CircularQueue::isEmpty()
{
    if (front == rear)
    {
        return true;
    }
    return false;
}

bool CircularQueue::isFull()
{
    if ((rear + 1) % size == front)
    {
        return true;
    }
    return false;
}

void CircularQueue::enqueue(int x)
{
    if (isFull())
    {
        cout << "Queue Overflow" << endl;
    }
    else
    {
        rear = (rear + 1) % size;
        Q[rear] = x;
    }
}

int CircularQueue::dequeue()
{
    int x = -1;
    if (isEmpty())
    {
        cout << "Queue Underflow" << endl;
    }
    else
    {
        front = (front + 1) % size;
        x = Q[front];
    }
    return x;
}

void CircularQueue::display()
{
    if (!isEmpty())
    {
        int i = front + 1;
        do
        {
            cout << Q[i] << " -> ";
            i = (i + 1) % size;
        } while (i != (rear + 1) % size);
    }
}

int main()
{
    cout << "Enter the length of the circular queue\n";
    int n;
    cin >> n;
    CircularQueue cq(n + 1);
    char ch = 'y';
    while (ch == 'y')
    {
        cout << "1 -> enqueue\n2 -> dequeue\n";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter an element\n";
            int num;
            cin >> num;
            cq.enqueue(num);
            cq.display();
            cout << '\n';
        }
        break;
        case 2:
        {
            int ele = cq.dequeue();
            if (ele != -1)
            {
                cout << "Element dequeued -> " << ele << '\n';
                cq.display();
                cout << '\n';
            }
        }
        break;
        default:
            cout << "Invalid input\n";
        }
        cout << "Want to continue?(y/n)\n";
        cin >> ch;
    }

    // Display
    cq.display();
    cout << '\n';
}