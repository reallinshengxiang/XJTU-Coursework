#include<bits/stdc++.h>
using namespace std;
struct customer{
	char fullname[35];
	double payment;
};
typedef customer Item;
class Stack{
	public:
		Stack() {top=0;}
		bool isempty() const;
		bool isfull() const;
		bool push(const Item &item);
		bool pop(Item &item);
	private:
		enum {MAX=10};
		Item items[MAX];
		int top;
};
bool Stack::isempty() const
{
	return top==0;
}
bool Stack::isfull() const
{
	return top==MAX;
}
bool Stack::push(const Item &item)
{
	if(top<MAX)
	{
		items[top++]=item;
		return 1;
	}
	else return 0;
}
bool Stack::pop(Item &item)
{
	if(top>0)
	{
		item=items[top--];
		return 1;
	}
	else return 0;
}
int main()
{
    Stack stack;
    customer cu;
    char ch;
    cout << "Press a to add a customer, P to process an order, and Q to exit." << endl;
    while (cin >> ch && toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
        {
            continue;
        }
        if (!isalpha(ch))
        {
            cout << '\a';
            continue;
        }
        switch (ch)
        {
        case 'a':
        case 'A':
            if (stack.isfull())
            {
                cout << "The order of 10 customers has been filled. Please process the existing order first !" << endl;
            }
            else
            {
                cout << "Add customer name : ";
                cin.getline(cu.fullname, 35);
                cout << "Add the customer's consumption amount : ";
                cin >> cu.payment;
                cout << "dsssd : " << stack.push(cu);
            }
            break;
        case 'p':
        case 'P':
            if (stack.isempty())
            {
                cout << " There are currently no unprocessed orders." << endl;
            }
            else
            {
                stack.pop(cu);
            }
            break;
        default:
            cout << " Input error！！！" << endl;
            break;
        }
        cout << "Press a to add a customer, P to process an order, and Q to exit." << endl;
    }
    return 0;
}
