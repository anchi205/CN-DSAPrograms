// C++ implementation of De-queue using circular array
#include<iostream>
using namespace std;
//#include "Solution.h"
class Deque
{
    int  arr[10];
    int  front;
    int  rear;
    int  size;
    public :
    Deque (int size)
    {
        front = -1;
        rear = 0;
        this->size = size;
    }
    
    bool isFull(){
        return ((front == 0 && rear == size-1)||front == rear+1);
        // OR return (front == (rear+1)%size);
    }
    
    bool isEmpty (){                       
        return (front == -1);
    }
    
    void insertFront(int input){            
        if (isFull()){
            cout << -1 << endl;
            return;
        }
        else if (front == -1){                         // If queue is initially empty
            front = 0;
            rear = 0;
        }
        else if (front == 0)                           // front is at first position of queue
            front = size - 1 ;
        else                                           // decrement front end by '1'
            front = front - 1;
        arr[front] = input ;                           // insert current element into Deque
    }
    
    void insertRear(int input){
        if (isFull()){
            cout << -1 << endl;
            return;
        }   
        else if (front == -1){                         // If queue is initially empty
            front = 0;
            rear = 0;
        }    
        else if (rear == size-1)                       // rear is at last position of queue
            rear = 0;
        else
            rear = rear+1;
            arr[rear] = input ;                        // insert current element into Deque
    }
  
    void deleteFront(){
        if (isEmpty()){
            cout << -1 << endl;;
            return ;
        }
        else if (front == rear){                    // Deque has only one element
            front = -1;
            rear = -1;
            cout << -1 << endl;
            return;
        }
        else                                       // back to initial position
           if (front == size -1)
               front = 0;
           else                                    // increment front by '1' to remove current front value from Deque
               front = front+1;
    }
    
    void deleteRear(){
        if (isEmpty()){
            return;
        }
        if (front == rear){                        // Deque has only one element
            front = -1;
            rear = -1;
            cout << -1 << endl;
            return;
        }
        else if (rear == 0)
            rear = size-1;
        else
            rear = rear-1;
    }
  
    int getFront(){                               // Returns front element of Deque
        if (isEmpty()){
            return -1 ;
        }
        return arr[front];
    }

    int getRear(){                                // function return rear element of Deque
        if(isEmpty() || rear < 0){
            return -1 ;
        }
        return arr[rear];
    }
};
// Driver program to test above function
int main()
{
    Deque dq(10);
    int choice,input;
    while(true) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                dq.insertFront(input);
                break;
            case 2:
                cin >> input;
                dq.insertRear(input);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                cout << dq.getFront() << "\n";
                break;
            case 6:
                cout << dq.getRear() << "\n";
                break;
            default:
                return 0;
        }
    }
    return 0;
}
