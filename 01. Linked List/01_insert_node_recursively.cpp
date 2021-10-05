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

void print(Node* head)
{
	Node* temp=head;
	while(temp)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
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
	
	/*
	5 0 9 7 3 1 4
	*/
	return 0;
}
