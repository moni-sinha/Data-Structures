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

Node* deleteDuplicates(Node* head)
{
	if(!head || !head->next)
		return head;
	Node* t1=head;
	Node* t2=head->next;
	while(t2)
	{
		if(t1->data!=t2->data)
		{
			t1=t1->next;
			t2=t2->next;
		}
		else
		{
			Node* t3=t2;
			t2=t2->next;
			t3->next=NULL;
			delete t3;
			t1->next=t2;
		}
	}
	return head;
}

int main()
{
	Node* head=NULL;
	Node* newNode=new Node(6);
	head=newNode;
	
	head=insertNode(head, 0, 6);
	head=insertNode(head, 0, 5);
	head=insertNode(head, 0, 4);
	head=insertNode(head, 0, 4);
	head=insertNode(head, 0, 4);
	head=insertNode(head, 0, 3);
	head=insertNode(head, 0, 2);
	head=insertNode(head, 0, 1);
	head=insertNode(head, 0, 1);
	
	print(head);
	cout<<endl;
	cout<<"size : "<<sizeLinkedList(head);
	cout<<endl<<endl;
	
	head=deleteDuplicates(head);
	print(head);
	cout<<endl;
	cout<<"size : "<<sizeLinkedList(head);
	cout<<endl<<endl;
	
	
	/*
	1 1 2 3 4 4 4 5 6 6
	size : 10
	
	1 2 3 4 5 6
	size : 6
	*/
	return 0;
}
