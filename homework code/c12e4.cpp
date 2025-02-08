#include<bits/stdc++.h>
using namespace std;
typedef unsigned long Item;
class Stack{
           private:
                  enum{MAX = 10};  // constant specific to class
                  Item* pitems;       // holds stack items
                  int size;           // number of elements in stack
                  int top;            // index for top stack item
           public:
                  Stack(int n = MAX);  // creates stack with n elements
                  Stack(const Stack& st);
                  ~Stack();
                  bool isempty() const;
                  bool isfull() const;
                  // push() returns false if stack already is full, true otherwise
                  bool push(const Item& item);  // add item to stack
                  // pop() returns false if stack already is empty, true otherwise
                  bool pop(Item& item);  // pop top into item
                  Stack& operator=(const Stack& st);
                  friend ostream& operator<<(ostream& os, const Stack& st);
};
Stack::Stack(int n)
{
	size=n;
	top=0;
	pitems=new Item[size];
	for(int i=0;i<=size-1;i++) pitems[i]=0;
}
Stack::Stack(const Stack& st)
{
	delete []pitems;
	size=st.size;
	top=st.top;
	pitems=new Item[size];
	for(int i=0;i<=size-1;i++) pitems[i]=st.pitems[i];
}
Stack::~Stack()
{
	delete []pitems;
}
bool Stack::isempty() const
{
	return top==0;
}
bool Stack::isfull() const
{
	return top==MAX;
}
bool Stack::push(const Item& item)
{
	if(top<MAX)  
	{
		pitems[top++]=item;
		return 1;
	}
	else
		return 0;
}
bool Stack::pop(Item& item)
{
	if(top>0)
	{
		top--;
		item=pitems[top];
		return 1;
	}
	else
		return 0;
}
Stack& Stack::operator=(const Stack& st)
{
        if(this==&st) return *this;
        delete []pitems;
        size=st.size;
        top=st.top;
        pitems=new Item[size];
        for(int i=0;i<=size-1;i++) pitems[i]=st.pitems[i];
        return *this;
}
ostream& operator<<(ostream& os, const Stack& st)
{
	for(int i=0;i<st.top;i++) os<<st.pitems[i]<<endl;
	return os;
}
int main() 
{
  using namespace std;
  Stack st;  // create an empty stack
  char ch;
  unsigned long po;
  cout << "Please enter A to add a purchase order,\n"
       << "P to process a PO, or Q to quit.\n";
  while (cin >> ch && toupper(ch) != 'Q') {
    while (cin.get() != '\n') continue;
    if (!isalpha(ch)) {
      cout << '\a';
      continue;
    }
    switch (ch) {
      case 'A':
      case 'a':
        cout << "Enter a PO number to add: ";
        cin >> po;
        if (st.isfull())
          cout << "stack already full\n";
        else
          st.push(po);
        break;
      case 'P':
      case 'p':
        if (st.isempty())
          cout << "stack already empty\n";
        else {
          st.pop(po);
          cout << "PO #" << po << " popped\n";
        }
        break;
    }
    cout << "Please enter A to add a purchase order,\n"
         << "P to process a PO, or Q to quit.\n";
  }
  Stack st2;
  st2 = st;
  cout << "stack2 = stack is:\n" << st2;

  cout << "Bye\n";
  return 0;
}
