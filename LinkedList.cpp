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
void printIthNode(node *head,int i)
{
	if(head == NULL)
	{
		return;
	}
	int count=0;
	while(head!=NULL)
	{
		if(count == i)
		{
			cout<<head->data<<endl;
			return;
		}
		else
		{
			head = head->next;
			count++;
		}
	}
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
	printIthNode(head,2);
	return 0;
}
