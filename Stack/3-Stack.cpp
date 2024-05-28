#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int Data;
    Node* Next;
};

// Node* top= NULL;
//=================================//
class Stack
{
public:

    Node* top = NULL;

    bool empty(){
        if (top == NULL)
            return true;
        else
            return false;
    }

   void push(int v) {

    Node* new_node = new Node();
    new_node->Data = v;
    new_node->Next = top;
    top = new_node;
}


    int pop() {
    if (empty()) {
        cout << "Stack Underflow" << endl;
        return -1; // Assuming -1 represents an error or empty stack
    }
    int v = top->Data;
    top = top->Next;
    return v;
}


   int Upper() {
    if (top != NULL) {
        return top->Data;
    } else {
        cout << "Stack Underflow" << endl;
        return -1;
        }
    }

    void display(){
        Node* temp = top;

        while (temp != NULL){

            cout << temp->Data << " ";
            temp = temp->Next; // temp++
        }
    }
};
//================================//
int main()
{
     Stack stack;

    // Push elements into the stack
    stack.push(1);
    stack.push(2);
    stack.push(3);

    // Display the stack
    cout << "Stack: ";
    stack.display(); // Output: 3 2 1
    cout << endl;

    // Pop elements from the stack
    cout << "Popped element: " << stack.pop() << endl; // Output: 3
    cout << "Popped element: " << stack.pop() << endl; // Output: 2

    // Display the stack after popping
    cout << "Stack after popping: ";
    stack.display(); // Output: 1
    cout << endl;

    // Push again into the stack
    stack.push(5);
    stack.push(7);
    // Get the top element of the stack
    cout << "Top element of the stack: " << stack.Upper() << endl; // Output: 7

    return 0;
}
