#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Stack {
private:
    T* items;
    int capacity;
    int top;

public:
    explicit Stack(int cap) {
        capacity = (cap > 0) ? cap : 1;
        top = 0;
        items = new T[capacity];
    }

    ~Stack() {
        delete[] items;
        items = nullptr;
    }

    bool isEmpty() const {
        return top == 0;
    }

    bool isFull() const {
        return top == capacity;
    }

    int size() const {
        return top;
    }

    void push(T value) {
        if (isFull()) {
            cout << "Stack is full, cannot push " << value << endl;
            return;
        }
        items[top] = value;
        top++;
    }

    T pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return T();
        }
        top--;
        return items[top];
    }

    T peek() const {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return T();
        }
        return items[top - 1];
    }
};

int main() {
    Stack<int> intStack(3);
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    intStack.push(40); 

    cout << "Popping: ";
    while (!intStack.isEmpty()) {
        cout << intStack.pop();
        if (!intStack.isEmpty()) {
            cout << " ";
        }
    }
    cout << endl;

    string word = "LAHORE";
    Stack<char> charStack(static_cast<int>(word.length()));
    for (char ch : word) {
        charStack.push(ch);
    }

    cout << "LAHORE reversed: ";
    while (!charStack.isEmpty()) {
        cout << charStack.pop();
    }
    cout << endl;

    Stack<string> history(10);
    history.push("github.com");
    history.push("example.com");
    history.push("gutech.edu.pk");

    cout << "Current page: " << history.peek() << endl;
    history.pop();
    cout << "After Back: " << history.peek() << endl;

    return 0;
}