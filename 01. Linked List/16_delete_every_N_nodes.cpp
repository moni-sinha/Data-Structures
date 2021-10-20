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

Node* delete_every_N_nodes(Node* head, int m, int n)
{
	if(!head || !head->next)
		return head;
		
	Node* temp1=head;
	
	while(temp1)
	{
		int count1=1, count2=1;
		while(count1!=m && temp1)
		{
			temp1=temp1->next;
			count1++;
		}
		
		if(!temp1)
			return head;
			
		Node* temp2=temp1->next;
		while(count2!=(n+1) && temp2)
		{
			Node* t2=temp2;
			temp2=temp2->next;
			delete t2;
			count2++;
		}
		//Node* t2=temp2;
		//temp2=temp2->next;
		//delete t2;
		temp1->next=temp2;
		temp1=temp2;
	}
	return head;
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
	
	head=delete_every_N_nodes(head, 2, 3);
	print(head);
	cout<<endl;
	cout<<"size : "<<sizeLinkedList(head);
	cout<<endl<<endl;
	
	
	/*
1 0 7 8 5 4 6
size : 7

1 0 4 6
size : 4
	*/
	return 0;
}
