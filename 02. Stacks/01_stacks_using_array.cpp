#include<bits/stdc++.h>
using namespace std;

class stackUsingArray{
	int* data;
	int nextIndex;
	int capacity;
	public:
		stackUsingArray(int totalSize)
		{
			data=new int[totalSize];
			capacity=totalSize;
			nextIndex=0;
		}
		int stackSize()
		{
			return nextIndex;
		}
		bool isEmpty()
		{
			
			return nextIndex == 0;
		}
		//insert
		void push(int element)
		{
			if(nextIndex == capacity)
			{
				cout<<"stack full"<<endl;
				return;
			}
			data[nextIndex]=element;
			nextIndex++;
		}
		//delete
		int pop()
		{
			if(isEmpty())
			{
				cout<<"stack empty"<<endl;
				return INT_MIN;
			}
			nextIndex--;
			return data[nextIndex];
		}
		//topmost element
		int top()
		{
			if(isEmpty())
			{ 
				cout<<"stack empty"<<endl;
				return INT_MIN;
			}
			return data[nextIndex-1];
		}
};

int main()
{
	stackUsingArray s(4);
	s.push(40);
	s.push(20);
	s.push(10);
	s.push(60);
	s.push(50);
	
	cout<<s.top()<<endl;
	
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	
	cout<<s.stackSize()<<endl;
	
	cout<<s.isEmpty()<<endl;
	/*
	*/
	return 0;
}
