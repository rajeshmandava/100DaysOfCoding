#include<iostream>
using namespace std;
#include"node.cpp"
#include<set>

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

//Given a linked list and an integer n you need to find and return index where n is present in the LL. Do this iteratively.

int indexOfNIter(node* head, int n)
{
	int count = 0;
	while(head!=NULL)
	{
		if(head->data == n)
			return count;
		count++;
		head=head->next;
	}
	return -1;
}


//Given a linked list and an integer n, append the last n elements of the LL to front.

node* append_LinkedList(node*head, int n)
{
	node* temp=head, *t=head;
	int i=-n;
	while(temp->next!=NULL)
	{
		if(i>=0)
		   t=t->next;
		temp=temp->next;
		i++;	
	}
	temp->next = head;
	head=t->next;
	t->next = NULL;
	return head;
}

//Given a sorted linked list (elements are sorted in ascending order). Eliminate duplicates from the given LL, such that output LL contains only unique elements.

node* eliminate_duplicate(node* head)
{
	node* temp = head->next;
	node* prev= head;
	while(temp!=NULL)
	{
		if(prev->data == temp->data)
		{
			node* x= temp;
			temp=temp->next;
			prev->next = temp;	
			delete x;
		}
		else
		{
			temp=temp->next;
			prev=prev->next;
		}
	}
	return head;
}
void print_reverse(node* head)
{
	if(head == NULL)
	{
		return;
	}
	print_reverse(head->next);
	cout<<head->data<<" ";
}


//Detecting a cycle in linked list
bool has_cycle(node* head)
{
	set<node*> ans;
	while(head!=NULL)
	{
		if(ans.find(head)!=ans.end())
		{
			return true;
		}
		ans.insert(head);
		head=head->next;
	}
	return false;
}
int main()
{
	node* head = takeInput();
	print_reverse(head);
	cout<<"checking is linked list has cycle "<<has_cycle(head)<<endl;
/*	print(head);
	cout<<"Length of the list is"<<length(head)<<endl;
	printIthNode(head,2);
	head=insertNode(head,0,10);
	print(head);
	head = deleteNode(head,2);
	print(head);
	head = deleteNodeRec(head,2);
	print(head);
	cout<<indexOfNIter(head,5)<<endl;
	head = append_LinkedList(head,2);
	print(head);
*/	return 0;
}
