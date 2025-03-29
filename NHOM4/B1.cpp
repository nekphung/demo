#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Hoanvi2node function
void Hoanvi2node(Node*& head, Node*& p, Node*& q) {
    if (p == head) {
        head = q;
    }
    else {
        Node* prev = head;
        while (prev->next != p) {
            prev = prev->next;
        }
        prev->next = q;
    }
    p->next = q->next;
    q->next = p;
}

// Sapxepdanhsachlienket function
void Sapxepdanhsachlienket(Node*& head) {
    Node* p = head;
    while (p != nullptr && p->next != nullptr) {
        Node* q = p->next;
        if (p->data > q->data) {
            Hoanvi2node(head, p, q);
            // Update p and q pointers after swapping
            Node* temp = p;
            p = q;
            q = temp;
        }
        else {
            p = p->next;
        }
    }
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Function to push a new node at the end of the list
void push(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int main() {
    Node* head = nullptr;

    // Example: 1 2 3 5 4 3 6 9 8
    push(head, 1);
    push(head, 2);
    push(head, 3);
    push(head, 5);
    push(head, 4);
    push(head, 3);
    push(head, 6);
    push(head, 9);
    push(head, 8);

    std::cout << "Original list: ";
    printList(head);

    Sapxepdanhsachlienket(head);

    std::cout << "Sorted list: ";
    printList(head);

    return 0;
}
