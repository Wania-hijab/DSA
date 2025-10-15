#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node();   // create new node
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;   // points to itself
    } else {
        Node* temp = head;
        // find last node
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;   // last node points to new node
        newNode->next = head;   // new node points to old head
        head = newNode;         // update head
    }
}

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    // Empty list
    if (head == NULL) {
        head = newNode;
        newNode->next = head; 
        return;
    }
    //  traverse to last node
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head; // maintain circular link
}

void deleteAtPosition(Node*& head, int pos) {
    if (head == NULL) {
        cout << "List is empty, nothing to delete!" << endl;
        return;
    }

    if (pos == 1) {
        if (head->next == head) {
            cout << "Deleted: " << head->data << endl;
            delete head;
            head = NULL;
            return;
        }
        Node* last = head;
        while (last->next != head) {  // find last node
            last = last->next;
        }
        Node* del = head;
        head = head->next;   
        last->next = head;   
        cout << "Deleted: " << del->data << endl;
        delete del;
        return;
    }
    Node* current = head;
    int count = 1;
    while (count < pos - 1 && current->next != head) {
        current = current->next;
        count++;
    }
    if (current->next == head) {
        cout << "Invalid position!" << endl;
        return;
    }
    Node* del = current->next;        
    current->next = del->next;       
    cout << "Deleted: " << del->data << endl;
    delete del;
}

void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    cout << "----OPERATIONS ON CIRCULAR LINKED LIST----" << endl << endl;
    Node* head = NULL;
    int choice, value, pos;

    cout << "Enter number of initial nodes: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        insertAtEnd(head, value);
    }

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Delete at Specific Position" << endl;
        cout << "4. Display List" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtBeginning(head, value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(head, value);
                break;
            case 3:
                cout << "Enter position: ";
                cin >> pos;
                deleteAtPosition(head, pos);
                break;
            case 4:
                display(head);
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);
    
    return 0;
}
