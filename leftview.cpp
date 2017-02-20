#include <iostream>
#include <queue>
using namespace std;

struct tree
{
	int data;
	tree* left;
	tree* right;
	tree* parent;
};

tree* CreateNewNode(int data, tree* left=NULL, tree* right=NULL,tree* parent=NULL)
{
	tree* NewNode=new tree;
	NewNode->data=data;
	NewNode->left=left;
	NewNode->right=right;
	NewNode->parent=parent;
	return NewNode;
}

void InsertNode(int data, tree** rootRef,tree* parent=NULL)
{
	if(*rootRef==NULL)
	{
		*rootRef=CreateNewNode(data,NULL,NULL,parent);
		return;
	}
	if((*rootRef)->data >data)
	{
		InsertNode(data,&((*rootRef)->left),*rootRef);
	}
	else
		InsertNode(data,&((*rootRef)->right),*rootRef);
}


void AuxRightView(tree* root,int level,int *maxlevel)
{
	if(root==NULL)
		return;
	if(level>*maxlevel)
	{
		cout<<root->data<<" ";
		*maxlevel=level;
	}
	AuxRightView(root->right,level+1,maxlevel);
	AuxRightView(root->left,level+1,maxlevel);
}

void RightView(tree* root)
{
	int maxlevel=0;
	AuxRightView(root,1,&maxlevel);
}



void Print(tree* root)
{
	if(root==NULL)
		return;
	Print(root->left);
	cout<<(root->data)<<" ";
	Print(root->right);
}

int main()
{
	tree* root=NULL;
	InsertNode(25,&root);
	InsertNode(16,&root);
	InsertNode(36,&root);
	InsertNode(12,&root);
	InsertNode(18,&root);
	InsertNode(30,&root);
	InsertNode(40,&root);
	Print(root);
	cout<<endl;
	// LeftView(root);
	// cout<<endl;
	RightView(root);
}