#include <iostream>
class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};
using namespace std;
Node *evenAfterOdd(Node *head)
{
    Node *OddH = NULL;
    Node *OddT = NULL;
    Node *EvenH = NULL;
    Node *EvenT = NULL;
    while(head!=NULL){
        if(head->data%2==0){
            if(EvenH==NULL){
                EvenH=head;
                EvenT=head;
            }
            else{
                EvenT->next=head;
                EvenT=head;
            }
        }
        else{
            if(OddH==NULL){
                OddH=head;
                OddT=head;
            }
            else{
                OddT->next=head;
                OddT=head;
            }
        }
        head=head->next;
    }
    if(OddH==NULL){   // No Odd LL
        return EvenH;
    }
    if(OddH!=NULL && EvenH!=NULL){ // Both odd and even elements are there
        OddT->next=EvenH;
        EvenT->next=NULL;
    }
    // If only odd elements existed, the last element -> next of the orig LL was already NULL
    return OddH;
}
Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}
void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		head = evenAfterOdd(head);
		print(head);
	}
	return 0;
}
