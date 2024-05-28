#include <iostream>
using namespace std;
class Node {
public:
    int Data;
    Node* Next;
};

class myqueue
{
public:

    Node* Head= NULL, * Tail= NULL;

    bool is_empty(){
        if (Head == NULL && Tail == NULL)
            return true;
        else
            return false;

    }

    void enqueue(int item) {

    Node* newnode = new Node();
    newnode->Data = item;
    newnode->Next = NULL;


    if (is_empty()) {
        Head = newnode;
        Tail = newnode;
    }
    else {
        Tail->Next = newnode;
        Tail = newnode;
    }

}


    int get_front()
    {
        return Head->Data;
    }

    int get_tail()
    {
        return Tail->Data;
    }

   void dequeue() {
    if (is_empty()) {
        cout << "Your Queue is empty" << endl;
    }
    else {
        if (Head == Tail) {
            Head = Tail = NULL;
        }
        else {
            Head = Head->Next;
        }
    }
}


    void display()
    {
        Node* temp = Head;
        while (temp != NULL)
        {
            cout << temp->Data << " ";
            temp = temp->Next;
        }
    }
};

int main()
{
    myqueue queue;

    // Enqueue elements
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    // Display the queue
    cout << "Queue: ";
    queue.display(); // Output: 1 2 3
    cout << endl;

    // Dequeue an element
    queue.dequeue();

    // Display the queue after dequeue
    cout << "Queue after dequeue: ";
    queue.display(); // Output: 2 3
    cout << endl;

    // Get the front and tail elements
    cout << "Front element: " << queue.get_front() << endl; // Output: 2
    cout << "Tail element: " << queue.get_tail() << endl;   // Output: 3

    return 0;


}
