#include <iostream>
class Node {
   public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
using namespace std;
Node *reverseLinkedList(Node *head) {
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL; // Can't be head->next bcuz if head is NULL i.e -1 then head->next is not possible
    while (current != NULL) {
        next = current->next; // Store next        
        current->next = prev;  // Reverse current node's pointer
        prev = current; // Move pointers one position ahead.
        current = next;
    }
    return prev;
}
Node *takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1) {
        Node *newnode = new Node(data);
        if (head == NULL) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}
void print(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        Node *head = takeinput();
        head = reverseLinkedList(head);
        print(head);
    }
    return 0;
}