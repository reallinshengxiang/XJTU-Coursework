#include<bits/stdc++.h>
using namespace std;
const int MAX = 10;
class List
{
      public:
             List();
             bool isfull();
             bool isempty();
             bool addItem(int it);
             int *item();
             int count();
             void visit(void (*pf)(int &));
      private:
              int ITEM[MAX];
              int COUNT;
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
bool List::addItem(int it)
{
    if(isfull())
    {
        cout<<"full already, add fail. \n";
        return 0;
    }
    ITEM[COUNT]=it;
    COUNT++;
    return 1;
}
int *List::item()
{
    return ITEM;
}
int List::count()
{
    return COUNT;
}
void List::visit(void (*pf)(int &))
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
