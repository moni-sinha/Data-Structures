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

void palindrome(Node* head)
{
	if(!head || !head->next)
	{
		cout<<"palindrome";
		return;
	}
	int len=sizeLinkedList(head);
	int i=0;
	Node* temp1=head;
	while(i<(len/2-1))
	{
		temp1=temp1->next;
		i++;
	}
	Node* temp2=reverse_print(temp1->next);
	Node* temp3=head;
	while(temp2->next)
	{
		if(temp2->data!=temp3->data)
		{
			cout<<"not plaindrome";
			return;
		}
		temp3=temp3->next;
		temp2=temp2->next;
	}
	cout<<"palindrome";
	return;
}

int main()
{
	Node* head=NULL;
	Node* newNode=new Node(6);
	head=newNode;
	
	head=insertNode(head, 0, 4);
	head=insertNode(head, 0, 5);
	head=insertNode(head, 0, 1);
	head=insertNode(head, 0, 5);
	head=insertNode(head, 0, 4);
	head=insertNode(head, 0, 6);
	
	print(head);
	cout<<endl;
	cout<<"size : "<<sizeLinkedList(head);
	cout<<endl<<endl;
	
	head=reverse_print(head);
	print(head);
	cout<<endl;
	cout<<"size : "<<sizeLinkedList(head);
	cout<<endl<<endl;
	
	palindrome(head);
	cout<<endl<<endl;
	
	/*
1 0 7 8 5 4 6
size : 7

6 4 5 8 7 0 1
size : 7
	*/
	return 0;
}
