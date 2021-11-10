#include <iostream>

/*
    Реализовать структуру данных SetofStacks имитирующую реальную ситуацию.
    Структура должна состоять из нескольких стеков, новый стек создается, как только предыдущий достигент порогового значения.
    Методы SetofStacks.push() и SetofStacks.pop() должны работать как и при работе со одним большим стеком.
*/
using namespace std;

template <typename T>
class Stack
{
public:
    Stack();
    ~Stack();

    T pop();
    void push(const T& x);
    bool isEmpty() const;
    const T& GetTop() const;

private:
    struct Node
    {
        T data;
        Node* next;
    };
    Node* root;
};

template<typename T>
Stack<T>::Stack()
{
    root = nullptr;
}

template<typename T>
Stack<T>::~Stack()
{
    while (!isEmpty())
        pop();
}

template<typename T>
T Stack<T>::pop()
{
    if (isEmpty())
    {
        throw length_error("stack is isEmpty");
    }
    Node* deleting = root;
    T tmp = deleting->data;
    root = deleting->next;
    delete deleting;
    return tmp;
}

template<typename T>
void Stack<T>::push(const T& data)
{
    Node* newnode = new Node;
    newnode->data = data;
    newnode->next = root;
    root = newnode;
}

template<typename T>
bool Stack<T>::isEmpty() const
{
    return root == nullptr;
}

template<typename T>
const T& Stack<T>::GetTop() const
{
    if (isEmpty())
    {
        throw length_error("stack is empty");
    }
    return root->data;
}

int main()
{
    Stack<int> s;
    s.push(1);
    s.pop();

    return 0;
}
