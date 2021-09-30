#include <iostream>
using namespace std;

class Stack
{
private:
    int size;
    int top;
    int *S;

public:
    Stack(int size);
    ~Stack();
    void push(int x);
    int pop();
    int peek();
    int isFull();
    int isEmpty();
    void display();
};

Stack::Stack(int size)
{
    this->size = size;
    top = -1;
    S = new int[size];
}

Stack::~Stack()
{
    delete[] S;
}

void Stack::push(int x)
{
    if (isFull())
    {
        cout << "Stack Overflow!" << endl;
    }
    else
    {
        top++;
        S[top] = x;
    }
}

int Stack::pop()
{
    int x = -1;
    if (isEmpty())
    {
        cout << "Stack Underflow!" << endl;
    }
    else
    {
        x = S[top];
        top--;
    }
    return x;
}

int Stack::peek()
{
    if (top == -1)
    {
        cout << "Empty stack\n";
    }
    return S[top];
}

int Stack::isFull()
{
    if (top == size - 1)
    {
        return 1;
    }
    return 0;
}

int Stack::isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}

void Stack::display()
{
    for (int i = top; i >= 0; i--)
    {
        cout << S[i] << " -> ";
    }
    cout << '\n';
}

int main()
{

    cout << "Enter the length of the Stack\n";
    int n;
    cin >> n;
    Stack stk(n);
    cout << "Enter the elements of the stack\n";
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        stk.push(num);
    }

    cout << "Stack full: " << stk.isFull() << endl;

    cout << "Stack: " << '\n';
    stk.display();

    cout << "Peek at Stack: " << stk.peek() << endl;

    cout << "Want to pop elements?(y/n) \n";
    char ch;
    cin >> ch;
    while (ch == 'y')
    {
        int popped = stk.pop();
        if (popped != -1)
        {
            cout << "Element popped -> " << popped << '\n';
            cout << "Want to pop more elements?(y/n) \n";
            cin >> ch;
        }
        else
        {
            break;
        }
    }

    cout << "Stack empty: " << stk.isEmpty() << '\n';

    return 0;
}