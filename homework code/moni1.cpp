#include <iostream>
using namespace std;
#define nullptr NULL
#define ll long long
struct Node {
	int data;
	Node* next;
	Node() : data(0), next(nullptr) {}
	Node(int data_) : data(data_), next(nullptr) {}
}; 
class LinkedList {
	private:
		Node* head;
	public:
		LinkedList() {head = new Node;}
		int AddNode(Node* node);
		int DeleteNodeByData(int data);
		void PrintList();
};
int LinkedList::AddNode(Node* node)
{
	Node *cur = this->head->next,*p=this->head;
	if(p->next==nullptr) 
	{
		p->next=node;
		return 1;
	}
	while(cur!=nullptr)
	{
		if(cur->data==node->data) return 0;
		if((p->data<node->data)&&(cur->data>node->data))
		{
			p->next=node;
			node->next=cur;
         		return 1;
		}
		cur=cur->next;
		p=p->next;
	}
	cur=node;
	p->next=node;
	return 1;
}
int LinkedList::DeleteNodeByData(int data)
{
	Node* cur = this->head->next,*p=this->head;
	ll flag=1;
        while(cur!=nullptr&&flag)
	{
		if(cur->data==data)
		{
			flag=0;
			break;
		}
		cur=cur->next;
		p=p->next;
	}
	if(flag) return 0;
	if(cur==nullptr) 
	{
		p->next=nullptr;
		return 1;
	}
	p->next=cur->next;
	return 1;
}
void LinkedList::PrintList()
{
	Node* cur = this->head->next;
	while (cur != nullptr) {
		cout << cur->data << endl;
		cur = cur->next;
	}
}

int main(int argc, char const *argv[])
{
	LinkedList list;
	int n, d;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> d;
		Node* node = new Node(d);
		list.AddNode(node);
	}
	list.PrintList();
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> d;
		list.DeleteNodeByData(d);
	}
	list.PrintList();
	return 0;
}
