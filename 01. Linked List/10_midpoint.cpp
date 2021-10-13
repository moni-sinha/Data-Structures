#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
	Node(int data)
	{
		this->data=data;
		next=NULL;
	}
};

Node* insertNode(Node* head, int i, int data)
{
	if(head==NULL)
		return head;
	if(i==0)
	{
		Node* newNode=new Node(data);
		newNode->next=head;
		head=newNode;
		return head;
	}
	Node* x=insertNode(head->next,i-1,data);
	head->next=x;
}

Node* deleteNode(Node* head, int i)
{
	if(head==NULL)
		return head;
	if(i==0)
	{
		Node* temp=head;
		head=head->next;
		delete temp;
		return head;
	}
	Node* x=deleteNode(head->next, i-1);
	head->next=x;
}

void print(Node* head)
{
	Node* temp=head;
	if(!temp)
		cout<<"empty linked list";
	while(temp)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

int sizeLinkedList(Node* head)
{
	Node* temp=head;
	int count=0;
	while(temp)
	{
		temp=temp->next;
		count++;
	}
	return count;
}

Node* reverse_print(Node* head)
{
	if(!head || !head->next)
		return head;
	
	Node* x=reverse_print(head->next);
	head->next->next=head;
	head->next=NULL;
	return x;
}

int midpointLL(Node* head)
{
	if(!head)
		return -1;
	else if(!head->next)
		return head->data;
	Node* slow=head;
	Node* fast=head->next;
	while(fast->next && fast->next->next)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	if(fast->next)
		slow=slow->next;
	return slow->data;
}

int main()
{
	Node* head=NULL;
	Node* newNode=new Node(6);
	head=newNode;
	
	head=insertNode(head, 0, 4);
	head=insertNode(head, 0, 5);
	head=insertNode(head, 0, 7);
	head=insertNode(head, 0, 9);
	head=insertNode(head, 0, 0);
	head=insertNode(head, 0, 1);
	
	print(head);
	cout<<endl;
	cout<<"size : "<<sizeLinkedList(head);
	cout<<endl<<endl;
	
	cout<<"middle node has value : "<<midpointLL(head);
	cout<<endl<<endl;
	
	/*
1 0 9 7 5 4 6
size : 7

middle node has value : 7

0 9 7 5 4 6
size : 6

middle node has value : 7
	*/
	return 0;
}
