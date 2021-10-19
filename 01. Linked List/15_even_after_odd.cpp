#include<bits/stdc++.h>
using namespace std;

//**********   *************

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

Node* even_after_odd(Node* head)
{
	if(!head || !head->next)
		return head;
	Node* oddHead=NULL;
	Node* oddTail=NULL;
	Node* evenHead=NULL;
	Node* evenTail=NULL;
	Node* temp=head;
	while(temp)
	{
		if(temp->data%2 == 0)
		{
			if(evenHead == NULL)
			{
				evenHead=temp;
				evenTail=temp;
			}
			else
			{
				evenTail->next=temp;
				evenTail=temp;
			}
		}
		else
		{
			if(oddHead == NULL)
			{
				oddHead=temp;
				oddTail=temp;
			}
			else
			{
				oddTail->next=temp;
				oddTail=temp;
			}
		}
		temp=temp->next;
	}
	oddTail->next=evenHead;
	return oddHead;
}

int main()
{
	Node* head=NULL;
	Node* newNode=new Node(6);
	head=newNode;
	
	head=insertNode(head, 0, 4);
	head=insertNode(head, 0, 5);
	head=insertNode(head, 0, 8);
	head=insertNode(head, 0, 7);
	head=insertNode(head, 0, 0);
	head=insertNode(head, 0, 1);
	
	print(head);
	cout<<endl;
	cout<<"size : "<<sizeLinkedList(head);
	cout<<endl<<endl;
	
	head=even_after_odd(head);
	print(head);
	cout<<endl;
	cout<<"size : "<<sizeLinkedList(head);
	cout<<endl<<endl;
	
	
	/*
1 0 7 8 5 4 6
size : 7

6 4 5 8 7 0 1
size : 7
	*/
	return 0;
}
