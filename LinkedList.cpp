#include<iostream>
using namespace std;
#include"node.cpp"


void print(node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

node* takeInput()
{
	int data;
	cin>>data;
	node* head = NULL;
	node* tail = NULL;
	while(data!=-1)
	{
		node* newNode = new node(data);
		if(head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = tail->next;
		}
		cin>>data;
	}
	return head;
}


int main()
{
	node* head = takeInput();
	print(head);
	
	return 0;
}
