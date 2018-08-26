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

//delete node at ith position
node* deleteNode(node* head, int i)
{
	if(i==0)
	{
		node *temp = head;
		temp->next = NULL;
		head=head->next;
		delete temp;
		return head;
	}
	int count = 0;
	node *temp = head;
	while(temp!=NULL && count<i-1)
	{
		temp=temp->next;
		count++;
	}
	if(temp->next!=NULL)
	{
		node *a = temp->next;
		node *b = a->next;
		temp->next = b;
		delete a;
	}
	return head;
}

node* insertNode(node* head, int i, int data)
{
	node *newNode = new node(data);
	int count = 0;
	node *temp = head;
	if(i == 0)
	{
		newNode->next = head;
		head = newNode;
		return head;
	}
	while(temp!=NULL && count<i-1)
	{
		temp = temp->next;
		count++;
	}
	if(temp!=NULL)
	{
		node *a = temp->next;
		temp->next = newNode;
		newNode->next =a;
	}
	return head;
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

node* deleteNodeRec(node* head, int i)
{
	if(head == NULL)
	{
		return NULL;
	}

	if(i == 0)
	{
		node* a=head;
		head = head->next;
		delete a;
		return head;
	}
	node *x = deleteNodeRec(head->next,i-1);
	head->next = x;
	return head;
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
	head=insertNode(head,0,10);
	print(head);
	head = deleteNode(head,2);
	print(head);
	head = deleteNodeRec(head,2);
	print(head);
	return 0;
}
