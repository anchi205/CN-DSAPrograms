#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

// #include "solution.h"
class Queue {
// Define the data members
    Node *head;
    Node *tail;
    int size=0;
    public:
    Queue() {
	head = NULL;
        tail = NULL;
        size = 0;
	}
	
    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
	return size;
	}

    bool isEmpty() {
	return size==0;
	}

    void enqueue(int data) {
	Node *newNode = new Node(data);
        if(head==NULL){
            head = newNode;
            tail = newNode;
        }
        tail->next = newNode;
        tail = newNode;
        size++;
	}

    int dequeue() {
        if(isEmpty()){
            return -1;
        }
        int ans = head -> data;
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
        return ans;
        }

    int front() {
        if(isEmpty()){
            return -1;
        }
        return head -> data;
    }
};

int main() {
    Queue q;

    int t;
    cin >> t;

    while (t--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                q.enqueue(input);
                break;
            case 2:
                cout << q.dequeue() << "\n";
                break;
            case 3:
                cout << q.front() << "\n";
                break;
            case 4:
                cout << q.getSize() << "\n";
                break;
            default:
                cout << ((q.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}
