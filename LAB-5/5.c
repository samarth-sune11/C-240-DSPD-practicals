#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*right;
	struct node*left;
};

struct node*create(int data)
{
	struct node*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
	
}
struct node*insert(struct node*root,int data)
{
	if(root==NULL)
	{
		return create(data);
	}
	if(data<root->data)
	{
		root->left=insert(root->left,data);
	}
	else
	{
		root->right=insert(root->right,data);
	}
	return root;
	
}

void inorder(struct node*root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
	
}

void preorder(struct node*root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct node*root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}

void search(struct node*root,int k)
{
	if(root==NULL)
	{
		printf("NULL\n");
		return;
	}
	if(root->data==k)
	{
		printf("found\n");
		return;
	}
	else if(k<root->data)
	{
		search(root->left,k);
	}
	else
	{
		search(root->right,k);
	}
}
int main()
{
	struct node*root=NULL;
	int i,k,data,n;
	printf("enter number of nodes: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n enter value of %d node:",i+1);
		scanf("%d",&data);
		
		root=insert(root,data);
	}
	printf("\n inorder traversal:");
	inorder(root);
	printf("\n preorder traversal:");
	preorder(root);
	printf("\n postorder traversal:");
	postorder(root);
	printf("\n enter element to search:");
	scanf("%d",&k);
	search(root,k);
	return 0;
}
