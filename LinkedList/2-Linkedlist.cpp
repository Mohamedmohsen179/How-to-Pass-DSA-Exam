#include <iostream>
using namespace std;


class Node{
public:
    int Data;
    Node* Next;
};

                // => This Code By : Mohamed Mohsen <=//

class LinkedList {
public:


    Node* Head = NULL;

    bool is_empty(){
        return (Head == NULL);
    }

    void insert_end(int item) {

        Node* new_node = new Node();
        new_node->Data = item;
        new_node->Next = NULL;


        if (is_empty()) {
            Head = new_node;
        }
        else {

            Node* current = Head;

            while (current->Next != NULL) {
                current = current->Next;
            }
            // Insert the new node after the last node
            current->Next = new_node;
        }
}


    void display(){

        Node* temp = Head;

        while (temp != NULL)
        {
            cout << temp->Data << " ";
            temp = temp->Next;
        }
        cout << endl;
    }

    int search(int key){


        Node* temp = Head;

        int index = 1;

        while (temp != NULL)
        {
            if (temp->Data == key)
                return index;

            else{
                temp = temp->Next;
                index++;
            }

        }
        return -1;
    }

    void Delete(int item) {
    if (is_empty()) {
        cout << "Your Linked List is Empty\n";
        return;
    }



    Node* temp = Head;
    Node* prev = NULL;

    // Search for the item
    while (temp != NULL && temp->Data != item) {
        prev = temp;
        temp = temp->Next;
    }

    if (temp == NULL) {
        cout << "Item Not found\n";
        return;
    }

    // Item found, now delete it
    if (prev == NULL) {
        // If the item is at the head
        Head = Head->Next;
    }
    else {
        prev->Next = temp->Next;
    }

    delete temp;
}

};

int main(){
      LinkedList list;

    // Inserting elements
    list.insert_end(1);
    list.insert_end(3);
    list.insert_end(5);

    // Displaying the list
    cout << "List: ";
    list.display(); // Output: 1 3 5

    // Searching for an element
    int key = 3;
    int index = list.search(key);
    if (index != -1)
        cout << key << " found at index " << index << endl;
    else
        cout << key << " not found in the list" << endl;

    // Deleting an element
    int item_to_delete = 3;
    cout << "Deleting " << item_to_delete << " from the list" << endl;
    list.Delete(item_to_delete);

    // Displaying the list after Deleting
    cout << "the list after Delete list: ";
    list.display(); // Output: 1 5

    return 0;

}
