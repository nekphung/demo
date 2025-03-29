#include <iostream>
#include <cmath>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

void Swap(Node*& head1, int pos1, int pos2) {
    Node* A = head1;
    Node* B = head1;
    Node* prevA = nullptr;
    Node* prevB = nullptr;
    for (int i = 1; i < pos1; i++) {
        prevA = A;
        A = A->next;
    }
    for (int j = 1; j < pos2; j++) {
        prevB = B;
        B = B->next;
    }
    if (pos1 == pos2) return;
    else if (abs(pos1 - pos2) == 1) {
        if (prevA != nullptr) {
            prevA->next = B;
            A->next = B->next;
            B->next = A;
        }
    }
    else {
        Node* nextA = A->next;
        Node* nextB = B->next;
        if (prevA != nullptr) {
            prevA->next = B;
            A->next = nextB;
        }
        if (prevB != nullptr) {
            prevB->next = A;
            B->next = nextA;
        }
    }
}

Node* Reserve(Node* head1) {
    Node* cur = head1;
    Node* prev = nullptr;
    Node* next = nullptr;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
void merge(Node*& head1, Node*& head2) {
    Node* cur1 = head1;
    Node* cur2 = head2;
    Node* head = nullptr;
    Node* tail = nullptr;

    while (cur1 && cur2) {
        if (cur1->data < cur2->data) {
            if (head == nullptr) {
                head = tail = cur1;
            }
            else {
                tail->next = cur1;
                tail = cur1;
            }
            cur1 = cur1->next;
        }
        else {
            if (head == nullptr) {
                head = tail = cur2;
            }
            else {
                tail->next = cur2;
                tail = cur2;
            }
            cur2 = cur2->next;
        }
    }

    if (cur1 != nullptr) {
        if (head == nullptr) {
            head = cur1;
        }
        else {
            tail->next = cur1;
        }
    }

    if (cur2 != nullptr) {
        if (head == nullptr) {
            head = cur2;
        }
        else {
            tail->next = cur2;
        }
    }

    head2 = nullptr;
    head1 = head;
}

void DeleteNode_x(Node*& head1, int data) {
    Node* prev = nullptr;
    Node* p = head1;
    while (p) {
        if (p->data == data) {
            Node* tmp = p;
            p = p->next;
            if (tmp == head1) {
                head1 = p;
            }
            if (prev != nullptr) {
                prev->next = p;
            }
            delete tmp;
        }
        else {
            prev = p;
            p = p->next;
        }
    }
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
    Node* head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(5);

    Node* head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);

    std::cout << "Danh sách liên kết thứ nhất: ";
    printList(head1);

    std::cout << "Danh sách liên kết thứ hai: ";
    printList(head2);

    merge(head1, head2);

    std::cout << "Danh sách liên kết sau khi hợp nhất: ";
    printList(head1);

    Swap(head1, 2, 3);
    printList(head1);

    DeleteNode_x(head1, 3);
    printList(head1); 

    Node* tmp = Reserve(head1);
    printList(tmp);

    return 0;
}
