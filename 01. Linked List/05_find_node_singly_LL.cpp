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

int findNode(Node* head, int data)
{
	int count=0;
	Node* temp=head;
	if(head==NULL)
		return 0;
	while(temp)
	{
		if(data==temp->data)
			return count;
		count++;
		temp=temp->next;
	}
	return -1;
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
	
	cout<<"3 is present at index : "<<findNode(head, 3);
	cout<<endl<<endl;
	
	cout<<"4 is present at index : "<<findNode(head, 4);
	cout<<endl<<endl;
	
	cout<<"0 is present at index : "<<findNode(head, 0);
	cout<<endl<<endl;
	
	cout<<"8 is present at index : "<<findNode(head, 8);
	cout<<endl<<endl;
	/*
	5 0 9 7 3 1 4
	size : 7
	
	0 9 7 3 1 4
	size : 6
	
	3 is present at index : 3
	
	4 is present at index : 5
	
	0 is present at index : 0
	
	8 is present at index : -1
	*/
	return 0;
}
