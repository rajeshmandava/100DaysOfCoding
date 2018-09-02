class node{
public:
	int data;
	node *next;


	node(int data)
	{
		next=NULL;
		this->data = data;
	}
};


class Node{
public:
	int data;
	node *next;
};

Node* newNode();