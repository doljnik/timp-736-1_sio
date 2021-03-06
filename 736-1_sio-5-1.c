#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	int value;
	int key;
	struct node *left;
	struct node *right;
	struct node *parent;
} node;

node *init()
{
	node *root = malloc(sizeof(node));
	root->value=-1;
	root->key=-1;
	root->left=NULL;
	root->right=NULL;
	root->parent=NULL;
	return root;
}

void add (node *root, int key, int value)
{

	for(;;)
	{
		if (root->key==-1)
		{
			root->key=key;
			root->value=value;
			break;
		}
		
		if (root->key==key)
		{
			root->value=value;
			break;
		}	
	
	
		if (key>root->key)
		{
			if (root->right==NULL)
			{
				node *tmp = init();
				root->right = tmp;
				tmp->key=key;
				tmp->value=value;
				tmp->parent=root;
				break;
			}
			else
			{
				root=root->right;
				continue;
			}
		}
	
	
		if (key<root->key)
		{
			if (root->left==NULL)
			{
				node *tmp = init();
				root->left = tmp;
				tmp->key=key;
				tmp->value=value;
				tmp->parent=root;
				break;
			}
			else
			{
				root=root->left;
				continue;
			}
		}
	}
	
}


void key_get_out(node *root, int key)
{
	int i = 0;
	 
	for(;;)
	{	
		if (key==root->key)
		{
			printf ("%d ", i);
			printf ("%d", root->value);
			break;
		}
		
		if (key>root->key)
		{
			if (root->right==NULL)
			{
				printf ("-1");
				break;
			}
			else
			{
				root=root->right;
				i++;
				continue;
			}
		}
		
		if (key<root->key)
		{
			if (root->left==NULL)
			{
				printf ("-1");
				break;
			}
			else
			{
				root=root->left;
				i++;
				continue;
			}
		}	
	}		
	printf ("\n");
}

void destroy(node *root)
{
	node *tmp=NULL;
	for(;;)
	{
		if (root->left!=NULL)
		{
			root=root->left;
			continue;
		}
		if (root->right!=NULL)
		{
			root=root->right;
			continue;
		}
		
		tmp=root->parent;
		if (tmp!=NULL)
		{
			if (tmp->key>root->key)
				tmp->left=NULL;
			else
				tmp->right=NULL;
				
			free(root);
			root=tmp;
		}
		else
		{
			free(root);
			break;
		}
	}
}

int main()
{
	int n=0,key=0,value=0;
	
	node *root=init();
	
	scanf("%d",&n);
	
	for (int i=0;i<n;i++) 
	{ 
		scanf ("%d", &key);
		scanf ("%d", &value);
		add(root, key, value); 
	}
	
	for (int i=0;i<3;i++) 
	{
		scanf ("%d", &key);
		key_get_out(root, key);
	}
	
	destroy(root);
	
	return 0;
}

