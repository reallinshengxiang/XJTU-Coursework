#include<bits/stdc++.h>
using namespace std;
typedef unsigned long Item;
class Stack
{
	private:
		enum {MAX = 10}; // constant specific to class
		Item * pitems; // holds stack items
		int size; // number of elements in stack
		int top; // index for top stack item
	public:
		Stack(int n = MAX); // creates stack with n elements
		Stack(const Stack & st);
		~Stack();
		bool isempty() const;
		bool isfull() const;
		// push() returns false if stack already is full, true otherwise
	        bool push(const Item & item); // add item to stack
		// // pop() returns false if stack already is empty, true otherwise
		bool pop(Item & item); // pop top into item
		Stack & operator=(const Stack & st);
		friend ostream & operator<<(ostream &os,const Stack &st);
};
Stack::Stack(int n)
{
	size=MAX;
	top=0;
	pitems=new Item[size];
	for(int i=0;i<=size-1;i++) pitems[i]=0;
}
Stack::Stack(const Stack & st)
{
	size=st.size;
	top=st.top;
	pitems=new Item[size];
	for(int i=0;i<=size-1;i++)  pitems[i]=st.pitems[i];
}
Stack::~Stack()
{
	delete []pitems; 
}
bool Stack::isempty() const
{
	return (top==0);
}
bool Stack::isfull() const
{
	return (top==MAX);
}
bool Stack::push(const Item & item)
{
	if(top<MAX)
	{
		top++;
		pitems[top]=item;
		return true;
	}
	return false;
}
bool Stack::pop(Item & item)
{
	if(top>0)
	{
		item=pitems[top];
		top--;
                return true;
	}
	return false;
}
Stack& Stack::operator=(const Stack& st)
{
	if(this==&st) return *this;
	delete [] pitems;
        size=st.size;
	top=st.top;
        pitems=new Item[size];
        for(int i=0;i<=size-1;i++)  pitems[i]=st.pitems[i];
	return *this;
}
ostream & operator<<(ostream &os,const Stack &st)
{
	for(int i=0;i<=st.top;i++) os<<st.pitems[i]<<endl;
	return os;
}
int main()
{
	Stack st;
	char ch;
	unsigned long x;
	cout<<"Please enter A to add a purchase order."<<endl<<"P to process a PO, or Q to quit."<<endl;
	while (cin>>ch&&toupper(ch)!='Q')
	{
		if(!isalpha(ch)) 
		{
		      	cout << '\a';
			continue;
	        }
		else
		{
			if(toupper(ch)=='A')
			{
				cout<<"Enter a PO number to add:"<<endl;
				cin>>x;
                                if(st.isfull()) cout<<"stack already empty"<<endl;
				else 	st.push(x);
			}
			else if(toupper(ch)=='P')
			{
				if(st.isempty()) cout<<"stack already empty"<<endl;
				else
				{
					st.pop(x);
					cout<<"PO #"<<x<<" popped"<<endl;
				}
			}
			cout<<"Please enter A to add a purchase order."<<endl<<"P to process a PO, or Q to quit."<<endl;
		}
	}
	//Stack st1;
	//st1=st;
	//cout<<"stack2 = stack is:"<<st1;
	cout<<"Bye"<<endl;
}
