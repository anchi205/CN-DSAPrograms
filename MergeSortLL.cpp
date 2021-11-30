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
Node* Merge(Node *head1, Node *head2){
    Node* finalHead = NULL;
    Node* finalTail = NULL;
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    if(head1->data<=head2->data){
        finalHead=head1;
        finalTail=head1;
        head1=head1->next;
    }
    else{
        finalHead=head2;
        finalTail=head2;
        head2=head2->next;
    }
    while(head1!=NULL && head2!=NULL){
        if(head1->data<=head2->data){
            finalTail->next=head1;
            finalTail=head1;
            head1=head1->next; 
        }
        else{
            finalTail->next=head2;
            finalTail=head2;
            head2=head2->next;
        }
    }
    while(head1!=NULL){
        finalTail->next=head1;
        finalTail=head1;
        head1=head1->next;
    }
    while(head2!=NULL){
        finalTail->next=head2;
        finalTail=head2;
        head2=head2->next;
    }
    return finalHead;
}
Node *mergeSort(Node *head)
{
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* part1H=head;
    Node* part2H=slow->next;
    slow->next=NULL;
    Node* newH1 = mergeSort(part1H);
    Node* newH2 = mergeSort(part2H);
    Node* fHead = Merge(newH1,newH2);
    return fHead;
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
		head = mergeSort(head);
		print(head);
	}

	return 0;
}
