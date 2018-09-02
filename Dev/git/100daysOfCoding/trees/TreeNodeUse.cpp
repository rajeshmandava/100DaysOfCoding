#include"TreeNode.h"

#include<iostream>
#include<queue>
using namespace std;

TreeNode<int>* takeInput()
{
	int data;
	cin>>data;
	TreeNode<int>* root = new TreeNode<int>(data); 

	int n;
	cout<<"Enter num of children of rootData :"<<data;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		TreeNode<int>* child = takeInput();
		root->children.push_back(child);
	}
	return root;
}

TreeNode<int>* takeInputLevelWise()
{
	int rootData;
	cout<<"Enter root data"<<endl;
	cin>>rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	queue<TreeNode<int>*> pendingNodes;

	pendingNodes.push(root);
	while(pendingNodes.size()!=0)
	{
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout<<"Enter number of children of "<<front->data<<endl;
		int numChild;
		cin>>numChild;
		for(int i=0;i<numChild;i++)
		{
			int childData;
			cin>>childData;
			cout<<"Enter "<<i<<" the child of "<<front->data<<endl;
			int numChild;
			cin>>numChild;
			TreeNode<int>* child = new TreeNode<int>(numChild);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}

}

void printTree(TreeNode<int>* root)
{
	if(root == NULL)
	{
		return;
	}

	for(int i=0;i<root->children.size();i++)
	{
		cout<<root->children[i]->data<<",";
	}
	cout<<endl;
	for(int i=0;i<root->children.size();i++)
	{
		printTree(root->children[i]);
	}


}


int main()
{
	TreeNode<int>* root = takeInputLevelWise();
	printTree(root);

	return 0;
}
