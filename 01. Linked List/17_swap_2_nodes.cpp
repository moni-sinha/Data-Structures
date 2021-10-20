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

Node* swap_2_nodes(Node* head, int pos1, int pos2)
{
	int len=sizeLinkedList(head);
	
	if((pos1>=len || pos1<0) || (pos2>=len || pos2<0))
		return NULL;
		
	if(!head || !head->next)
		return head;
		
	if(pos1 == pos2)
		return head;
	else if(pos1==0 && pos2==1)
	{
		Node* t1=head;
		Node* t2=t1->next;
		Node* t3=t2->next;
		t1->next=t3;
		t2->next=t1;
		head=t2;
	}
	else if(pos1==0)
	{
		Node* t1=head;
		Node* t2=head;
		Node* p2=NULL;
		Node* t3=t1->next;
		int count=0;
		while(count<pos2)
		{
			p2=t2;
			t2=t2->next;
			count++;
		}
		t1->next=t2->next;
		p2->next=t1;
		t2->next=t3;
		head=t2;
	}
	else if(abs(pos1-pos2) == 1)
	{
		Node* t1=head;
		Node* t2=head;
		Node* p1=NULL;
		int count=0;
		while(count<pos1)
		{
			p1=t1;
			t1=t1->next;
			count++;
		}
		count=0;
		while(count<pos2)
		{
			t2=t2->next;
			count++;
		}
		p1->next=t2;
		t1->next=t2->next;
		t2->next=t1;
	}
	else
	{
		Node* t1=head;
		Node* t2=head;
		Node* p1=NULL;
		Node* p2=NULL;
		int count=0;
		while(count<pos1)
		{
			p1=t1;
			t1=t1->next;
			count++;
		}
		count=0;
		while(count<pos2)
		{
			p2=t2;
			t2=t2->next;
			count++;
		}
		Node* t3=t1->next;
		p1->next=t2;
		p2->next=t1;
		t1->next=t2->next;
		t2->next=t3;
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
	
	int pos1, pos2;
	cout<<"enter positions to be swapped : ";
	cin>>pos1>>pos2;
	head=swap_2_nodes(head, pos1, pos2);
	print(head);
	cout<<endl;
	cout<<"size : "<<sizeLinkedList(head);
	if(!head)
		cout<<endl<<"enter correct positions"<<endl;
	cout<<endl<<endl;
	
	
	/*
1 0 7 8 5 4 6
size : 7

enter positions to be swapped : 0 1
0 1 7 8 5 4 6
size : 7
************************
1 0 7 8 5 4 6
size : 7

enter positions to be swapped : 2 5
1 0 4 8 5 7 6
size : 7	
	*/
	return 0;
}
