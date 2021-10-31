#include<bits/stdc++.h>
using namespace std;

class dynamic_stack{
	int* data;
	int nextIndex;
	int capacity;
	public:
		dynamic_stack()
		{
			capacity=2;
			nextIndex=0;
			data=new int[4];
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
				int* newData=new int[2*capacity];
				for(int i=0; i<capacity; i++)
				{
					newData[i]=data[i];
				}
				capacity=2*capacity;
				delete [] data;
				data=newData;
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
	dynamic_stack s;
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
