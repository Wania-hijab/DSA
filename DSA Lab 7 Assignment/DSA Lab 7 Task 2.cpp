#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;  
    Node* next;
};

// Helper function to search for an employee
bool searchEmployee(Node* head, string name) {
    if (head == NULL) return false;
    Node* temp = head;
    do {
        if (temp->data == name) return true;
        temp = temp->next;
    } while (temp != head);
    return false;
}

// Insert at end (used for adding employees)
void insertAtEnd(Node*& head, string value) {
    Node* newNode = new Node();
    newNode->data = value;
    
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }
    
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;  
}

// Add employee (checks for uniqueness and adds at end)
void addEmployee(Node*& head, string name) {
    if (searchEmployee(head, name)) {
        cout << "Employee already exists!" << endl;
        return;
    }
    insertAtEnd(head, name);
    cout << "Added successfully" << endl;
}

// Delete employee by name
void deleteEmployee(Node*& head, string name) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    
    if (head->data == name) {  // If the head node has the name
        if (head->next == head) {  // Only one node
            delete head;
            head = NULL;
            cout << "Deleted successfully" << endl;
            return;
        }
        
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        
        Node* temp = head;
        head = head->next;
        last->next = head;
        delete temp;
        cout << "Deleted successfully" << endl;
        return;
    }
    
    Node* current = head;
    while (current->next != head) {
        if (current->next->data == name) {
            Node* del = current->next;
            current->next = del->next;
            delete del;
            cout << "Deleted successfully" << endl;
            return;
        }
        current = current->next;
    }
    
    cout << "Employee not found!" << endl;
}

// Update employee by name
void updateEmployee(Node*& head, string oldName, string newName) {
    if (!searchEmployee(head, oldName)) {
        cout << "Employee not found!" << endl;
        return;
    }
    
    if (searchEmployee(head, newName)) {
        cout << "New name already exists!" << endl;
        return;
    }
    
    Node* temp = head;
    do {
        if (temp->data == oldName) {
            temp->data = newName;
            cout << "Updated successfully" << endl;
            return;
        }
        temp = temp->next;
    } while (temp != head);
}

// Search for an employee
void searchForEmployee(Node* head, string name) {
    if (searchEmployee(head, name)) {
        cout << "Found successfully" << endl;
    } else {
        cout << "Not found!" << endl;
    }
}

// Display the list
void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    
    Node* temp = head;
    do {
        cout << temp->data << " ";  // Display strings
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    cout << "----DATA SET FOR EMPLOYEES----" << endl << endl;
    Node* head = NULL;
    int choice;
    string name, oldName, newName;
    
    cout << "Enter number of initial employees: ";
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cout << "Enter name for employee " << i + 1 << ": ";
        cin >> name;  // Assuming single-word names for simplicity
        addEmployee(head, name);
    }
    
    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Delete Employee" << endl;
        cout << "3. Update Employee" << endl;
        cout << "4. Search Employee" << endl;
        cout << "5. Display All Employees" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter name: ";
                cin >> name;
                addEmployee(head, name);
                break;
            case 2:
                cout << "Enter name to delete: ";
                cin >> name;
                deleteEmployee(head, name);
                break;
            case 3:
                cout << "Enter old name: ";
                cin >> oldName;
                cout << "Enter new name: ";
                cin >> newName;
                updateEmployee(head, oldName, newName);
                break;
            case 4:
                cout << "Enter name to search: ";
                cin >> name;
                searchForEmployee(head, name);
                break;
            case 5:
                display(head);
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);
    
    return 0;
}

