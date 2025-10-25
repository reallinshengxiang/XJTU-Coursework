#include<iostream>
#include<string>

using namespace std;
string str = "";
int WPL = 0;
struct node
{
	int weight;
	node* left = NULL;
	node* right = NULL;	
	int* code;
	int layer;
};
node* leaves[100];
int nowleaves = 0;
void makeheap(node** heap, node** list, int n)
{
	heap[0] = list[0];
	for (int j = 1; j < n; j++)
	{
		int i = j;
		heap[j] = list[j];
		while(heap[i]->weight < heap[i/2]->weight)
		{
			node* tmp = heap[i];
			heap[i] = heap[i/2];
			heap[i/2] = tmp;
		}
	}
}

node* popheap(node** heap, int n)
{
	node* a = heap[0];
	int i = 0;
	while(i < n)
	{
		if (2*i+2 < n)
		{
			if(heap[2*i+1]->weight < heap[2*i+2]->weight)
			{
				heap[i] = heap[2*i+1];
				i = 2*i+1;
			}
			else
			{
				heap[i] = heap[2*i+2];
				i = 2*i+1;
			}
		}
		else if (2*i+1 < n)
		{
			heap[i] = heap[2*i+1];
			i = 2*i+1;
		}
		else
		{
			break;
		}
	}
	if(i == n-1)
	{
		heap[n-2] = heap[n-1];
	}
	return a;
}

void pushheap(node** heap, node* a, int n)
{
	heap[n] = a;
	int i = n;
	while(heap[i]->weight < heap[i/2]->weight)
		{
			node* tmp = heap[i];
			heap[i] = heap[i/2];
			heap[i/2] = tmp;
		}
}

string int_to_string(int a)
{
	string str = "";
	int len = 0;
	char c[100];
	while (a)
	{
		int tmp = a % 10;
		c[len] = char(tmp+48);
		len++;
		a = a/10;
	}
	for (int i = len-1; i >= 0; i--)
	{
		str += c[i];
	}
	return str;
}

void bfs(node* head)
{
	str += int_to_string(head->weight);
	if(head->left == NULL)
	{
		leaves[nowleaves] = head;
		nowleaves++;
		return;
	}
	else
	{
		WPL += head->weight;
		head->left->layer = head->layer+1;
		for(int i = 0; i < head->layer; i++)
		head->left->code[i] = head->code[i];
		head->left->code[head->layer] = 0;
		str += "(";
		bfs(head->left);
		str += ",";
		head->right->layer = head->layer+1;
		for(int i = 0; i < head->layer; i++)
		head->right->code[i] = head->code[i];
		head->right->code[head->layer] = 1;
		bfs(head->right);
		str += ")";
	}
}

int main()
{
	int n;
	cin >> n;
	node** list = new node*[n];
	node** heap = new node*[n];
	for (int i = 0; i < n; i++)
	{
		node* tmp = new node;
		list[i] = tmp;
		cin >> list[i]->weight;
	}
	makeheap(heap, list, n);
	while(n != 1)
	{
		node* a = popheap(heap, n);
		node* b = popheap(heap, n-1);
		node* c = new node;
		c->left = a;
		c->right = b;
		c->weight = a->weight+b->weight;
		pushheap(heap, c, n-2);
		n--;
	}
	node* head = popheap(heap, 1);
	head->layer = 0;
	head->code[head->layer] = 0;
	bfs(head);
	str+='\0';
	cout << WPL << endl;
	cout << str << endl;
	for (int i = 0; i < n; i++)
	{
		for(int j = 0; j <= leaves[i]->layer; j++)
		{
			cout << leaves[i]->code[j];
		}
	}
	return 0;
}

