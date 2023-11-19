#include<stdio.h>
#include<stdlib.h>
int num;
struct node
{
	int data;
	struct node *left, *right;
};
struct node* Newnode(int data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->right=NULL;
	temp->left=NULL;
	temp->data=num;
}
struct node* insert(struct node *node, int data)
{
	if(node==NULL)
		return Newnode(data);
	if(data < node->data)
		node->left=insert(node->left, data);
	else
		node->right=insert(node->right, data);
}
struct node*minvalue(struct node* node)
{
	struct node* current = node;
	while(current && current->data != NULL)
		current = current->left;
	return current;
}
struct node* Deletenode(struct node* root, int data)
{
	if(root==NULL)
		return root;
	if(data < root->data )
		root->left=Deletenode(root->left, data);
	if(data > root->data )	
		root->right=Deletenode(root->right, data);	
	else
	{
		if (root->left == NULL) 
		{
      		struct node *temp = root->right;
      		free(root);
     		return temp;	
		}
		else if(root->right==NULL)
		{
			struct node *temp = root->left;
      		free(root);
     		return temp;		
		}
		struct node* temp = minvalue(root->right);
		root->data=temp=data;
		root->right=Deletenode(root->right, temp->data);
	}
	return root;
}
void inorder(struct node *root)
{
  if (root != NULL) 
  {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}
void preorder(struct node *root)
{
  if (root != NULL) 
  {
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}
void postorder(struct node *root)
{
  if (root != NULL) 
  {
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
  }
}
int main()
{
	int choice;
	struct node* root=(struct node*)malloc(sizeof(struct node));
	root=NULL;
	printf("1-insert\t\t 2-delete\t\t 3-inorder\t\t 4-preorder\t\t 5-postorder\n");
	while(1)
	{
		printf("\nEnter the operation: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter the number to be inserted: ");
				scanf("%d", &num);
				root=insert(root,num);
				break;
			case 2:
				printf("Enter the number to be deleted: ");
				scanf("%d", &num);
				root=Deletenode(root,num);
				break;
			case 3:
				printf("INORDER TRAVERSAL: ");
				inorder(root);
				break;
			case 4:
				printf("PREORDER TRAVERSAL: ");
				preorder(root);
				break;
			case 5:
				printf("POSTORDER TRAVERSAL: ");
				postorder(root);
				break;
			default:
				break;
	
		}
	}
}
