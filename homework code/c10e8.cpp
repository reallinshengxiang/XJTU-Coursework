#include<bits/stdc++.h>
using namespace std;
typedef int Item;
static const int MAX = 10;
class List
{
      private:
              Item ITEM[MAX];
              int COUNT;
      public:
             List();
             bool isfull();
             bool isempty();
             bool addItem(Item it);
             Item *item();
             int count();
             void visit(void (*pf)(Item &));
};
List::List()
{
    COUNT = 0;
}
bool List::isfull()
{
    return COUNT == MAX;
}
bool List::isempty()
{
    return COUNT == 0;
}
bool List::addItem(Item it)
{
    if (isfull())
    {
        cout << "full already, add fail. "<<endl;
        return false;
    }
    else
    {
        ITEM[COUNT++]=it;
        return true;
    }
}
Item *List::item()
{
    return ITEM;
}
int List::count()
{
    return COUNT;
}
void List::visit(void (*pf)(Item &))
{
    for (int i=0;i<COUNT;i++)
    {
        (*pf)(ITEM[i]);
    }
}
void intadd2(int &n)
{
	n=n+2;
}
int main()
{
    List l;
    int a[3];
    for (int i=0;i<3;i++) 
    {
	    cin>>a[i];
	    l.addItem(a[i]);
    }
    for (int i=0;i<3;i++)
    {
        cout<<l.item()[i]<<std::endl;
    }
    l.visit(intadd2);
    for (int i=0;i<3;i++)
    {
        cout<<l.item()[i]<<std::endl;
    }
    return 0;
}
