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

int length(node *head)
{
	if(head == NULL)
	{
		return 0;
	}	
	int count = 0;
	while(head != NULL)
	{
		count++;
		head=head->next;
	}
	return count;
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
	cout<<"Length of the list is"<<length(head)<<endl;
	return 0;
}
