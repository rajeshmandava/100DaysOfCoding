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
//Finding the length of linked list recursively
int length_Rec(node* head)
{
	if(head == NULL)
	{
		return 0;
	}
	int ans=length_Rec(head->next);
	return ans+1;

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
//Deleting node recursively
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

//finding an element in linked list

bool search_Rec(node* head, int n)
{
	if(head == NULL)
	{
		return false;
	}
	
	if(head->data == n)
	{
		return true;
	}
	bool ans = search_Rec(head->next,n);
	return ans;
}

//Print nth node from the end of linked list
void printNthFromLast(node* head,int n)
{	
	if(head == NULL)
		return;
	node* temp = head;
	int len=0;
	while(temp!=NULL)
	{
		temp=temp->next;
		len++;
	}
	if(len<n)
		return;
	temp=head;
	for(int i=1;i<len-n+1;i++)
	{
		temp=temp->next;
	}
	cout<<temp->data<<endl;

}
//Print middle of the linked list
void printMiddle(node *head)
{
	if(head == NULL)
		return;
	node* fast=head;
	node* slow=head;
	while(fast!=NULL && fast->next!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	cout<<slow->data<<endl;
}

//finding occurences of a key in linked list
int count(node* head, int key)
{
	if(head == NULL)
	{
		return 0;
	}
	int ans = count(head->next,key);
	if(head->data == key)
		return ans+1;
	else
		return ans;
}

//function to remove duplicates in unsorted linked list

Node* newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->next = NULL;
	return NULL;
}

void printNode(Node *head)
{
	if(head == NULL)
	{
		return;
	}
	while(head != NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

Node* removeDuplicates(Node* head)
{
	if(head == NULL)
	{
		return;
	}
	Node* ptr1,ptr2,dup;
	ptr1=head;
	while(ptr1!=NULL && ptr1->next!=NULL)
	{
		ptr2=ptr1;
		while(ptr2->next!=NULL)
		{
			if(ptr1->data == ptr2->next->data)
			{
				dup = ptr2->next;
				ptr2->next = ptr2->next->next;
				delete(dup);
			}
			else
			{
				ptr2=ptr2->next;
			}
		}
		ptr1=ptr1->next;
	}
}

int main()
{
	node* head = takeInput();
	head = eliminate_duplicate(head);
	print(head);



	/*cout<<count(head,2)<<endl;
    /*printMiddle(head);
	/*printNthFromLast(head,2);

	/*cout<<"  "<<search_Rec(head,2)<<endl;


/*
	cout<<length_Rec(head)<<endl;
	print_reverse(head);
	cout<<"checking is linked list has cycle "<<has_cycle(head)<<endl;
	print(head);
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
