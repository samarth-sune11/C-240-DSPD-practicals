
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*right;
	struct node*left;
};

struct node*create()
{
	int data;
	struct node*newnode;
	printf("enter data(0 for no node):");
	scanf("%d",&data);
	if(data==0)
	{
		return NULL;
	}
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	printf("enter left child of %d:\n",data);
	newnode->left=create();
	printf("enter right child of %d:\n",data);
	newnode->right=create();
	return newnode;	
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
int search(struct node*root,int k)
{
	if(root==NULL)
	{
		return 0;
	}
	if(root->data==k)
	{
		
		return 1;
	}
	else{
		if(search(root->left,k)||search(root->right,k))
		{
			return 1;
		}
		else{
			return 0;
		}
	}
}
int main()
{
	struct node*root=NULL;
	int i,k;
	root = create();	
	printf("\n inorder traversal:");
	inorder(root);
	printf("\n preorder traversal:");
	preorder(root);
	printf("\n postorder traversal:");
	postorder(root);
	printf("\n enter element to search:");
	scanf("%d",&k);
	search(root,k);
	if(search(root,k))
	{
		printf("element %d found in tree\n",k);
	}
	else{
		printf("element %d not found in tree\n",k);
	}
	return 0;
}
