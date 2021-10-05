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
	if(head==NULL)
		return 0;
	return 1+sizeLinkedList(head->next);
}

int main()
{
	Node* head=NULL;
	Node* newNode=new Node(4);
	head=newNode;
	
	head=insertNode(head, 0, 0);
	head=insertNode(head, 1, 3);
	head=insertNode(head, 0, 5);
	head=insertNode(head, 2, 9);
	head=insertNode(head, 3, 7);
	head=insertNode(head, 5, 1);
	
	print(head);
	cout<<endl;
	cout<<"size : "<<sizeLinkedList(head);
	cout<<endl<<endl;
	
	head=deleteNode(head, 0);
	print(head);
	cout<<endl;
	cout<<"size : "<<sizeLinkedList(head);
	cout<<endl<<endl;
	
	/*
	5 0 9 7 3 1 4
	size : 7
	
	0 9 7 3 1 4
	size : 6
	*/
	return 0;
}
