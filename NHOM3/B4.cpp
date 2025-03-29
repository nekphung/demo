#include <iostream>
#include <cmath>

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= std::sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

Node* CreateLinkedlist(Node* head) {
    Node* newhead = nullptr;
    Node* tail = nullptr;
    while (head) {
        if (isPrime(head->data)) {
            Node* newNode = new Node(head->data);
            if (newhead == nullptr) {
                newhead = tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        head = head->next;
    }
    return newhead;
}

Node* CreatesumLinkedList(Node* head) {
    Node* newhead = nullptr;
    Node* tail = nullptr;
    while (head) {
        if (isPrime(head->data)) {
            int sum = 0;
            while (head && isPrime(head->data)) {
                sum += head->data;
                head = head->next;
            }
            Node* newNode = new Node(sum);
            if (newhead == nullptr) {
                newhead = tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        else {
            Node* newNode = new Node(head->data);
            if (newhead == nullptr) {
                newhead = tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
            head = head->next;
        }
    }
    return newhead;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(5);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(7);

    std::cout << "Danh sách liên kết ban đầu: ";
    printList(head);

    Node* primeList = CreateLinkedlist(head);

    std::cout << "Danh sách liên kết các số nguyên tố: ";
    printList(primeList);
    
    Node* sumprimelist = CreatesumLinkedList(head);

    std::cout << "Danh sách liên kết các số nguyên tố: ";
    printList(sumprimelist);

    return 0;
}
