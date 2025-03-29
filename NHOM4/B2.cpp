#include <iostream>
#include <cmath>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

bool Prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void Chenso_1_truocnodelasonguyento(Node*& head) {
    Node* p = head;
    while (p) {
        if (p == head && Prime(p->data)) {
            Node* q = new Node(1);
            q->next = p;
            head = q;
            p = p->next; // Move forward
        }
        else if (Prime(p->data) && p != head) {
            Node* prev = head;
            while (prev->next != p) {
                prev = prev->next;
            }
            Node* q = new Node(1);
            prev->next = q;
            q->next = p;
            p = p->next; // Move forward
        }
        else {
            p = p->next; // Move forward
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
    Node* head = new Node(3);
    head->next = new Node(5);
    head->next->next = new Node(4);
    head->next->next->next = new Node(7);

    cout << "Original list: ";
    printList(head);

    Chenso_1_truocnodelasonguyento(head);

    cout << "Modified list: ";
    printList(head);

    return 0;
}
