#include <iostream>
using namespace std;
struct queue
{
    int front;
    int rear;
    int size;
    int elements[20];
};
void enque(struct queue &q, int x)
{
    if (q.rear + 1 % q.size == q.front)
        cout << "overflow";
    else if (q.front == -1 && q.rear == -1)
    {
        q.front = 0;
        q.rear = 0;
        q.elements[q.rear] = x;
        q.rear = (q.rear + 1) % q.size;
    }
    else
    {
        q.elements[q.rear] = x;
        q.rear = (q.rear + 1) % q.size;
    }
}
int deque(struct queue &q)
{
    if (q.front == -1)
        return -1;
    else
    {
        int t;
        if (q.front == q.rear)
        {
            t = q.elements[q.front];
            q.rear = -1;
            q.front = -1;
        }
        else
        {
            t = q.elements[q.front];
            ;
            q.front = (q.front + 1) % q.size;
        }

        return t;
    }
}
int count(struct queue q)
{
    int k = deque(q);
    int counter = 0;
    while (k != -1)
    {
        counter++;
        k = deque(q);
    }
    return counter - 1;
}
struct stack
{
    int size;
    int top; //DIAGRAM
    int elements[20];
};

void push(struct stack &s, int x)
{
    if (s.top == s.size - 1)
        cerr << "stack overflow ";
    else
        s.elements[++s.top] = x;
}
int pop(struct stack &s)
{
    if (s.top == -1)
        return -1;
    else
        return s.elements[s.top--];
}
int peek(struct stack &s)
{
    if (s.top == -1)
        return -1;
    else
        return s.elements[s.top];
}

int main()
{
    struct stack s;
    s.size = 10;
    s.top = -1;

    struct queue q;
    q.front = -1;
    q.rear = -1;
    q.size = 10;

    enque(q, 1);
    enque(q, 2);
    enque(q, 3);
    enque(q, 4);
    enque(q, 5);
    enque(q, 6);
    enque(q, 7);
    enque(q, 8);

    int k;
    int len = q.front - q.rear;
    len = len > 0 ? len + q.size : -len;
    int i = 0;
    while (i < len/2)
    {
        k = deque(q);
        push(s, k);
        i++;
    }
    i = 0;
    while (i <len)
    {
        if (i % 2 != 0)
        {
            k = deque(q);
            enque(q, k);
        }
        else
        {
            enque(q, pop(s));
        }
        i++;
    }
    cout << deque(q);
    cout << deque(q);
    cout << deque(q);
    cout << deque(q);
    cout << deque(q);
    cout << deque(q);
    cout << deque(q);
    cout << deque(q);


}