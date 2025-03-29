#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

void DeleteNode(Node*& head, int data) {
    Node* p = head;
    Node* prev = nullptr;
    while (p) {
        if (p->data == data) {
            if (p == head) {
                head = p->next;
            }
            else {
                prev->next = p->next;
            }
            delete p;
            return; // Exit after deleting the node
        }
        prev = p;
        p = p->next;
    }
}

void Xoacacphantutrungcua2head(Node*& head1, Node*& head2) {
    Node* p = head1;
    while (p) {
        Node* q = head2;
        bool found = false;
        while (q) {
            if (p->data == q->data) {
                DeleteNode(head2, q->data);
                found = true; // Mark that a duplicate was found
                break;
            }
            q = q->next;
        }
        if (found) {
            DeleteNode(head1, p->data);
            p = head1; // Reset to head to avoid skipping nodes
        }
        else {
            p = p->next;
        }
    }
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head1 = new Node(3);
    head1->next = new Node(5);
    head1->next->next = new Node(4);
    head1->next->next->next = new Node(7);

    Node* head2 = new Node(1);
    head2->next = new Node(3);
    head2->next->next = new Node(5);

    cout << "Original list 1: ";
    printList(head1);

    cout << "Original list 2: ";
    printList(head2);

    Xoacacphantutrungcua2head(head1, head2);

    cout << "Modified list 1: ";
    printList(head1);

    cout << "Modified list 2: ";
    printList(head2);

    return 0;
}
