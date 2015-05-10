#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
	int Element;
	struct TreeNode* Left;
	struct TreeNode* Right;
};

struct TreeNode* MakeEmpty(struct TreeNode* root)
{
	if(root != NULL)
	{
		MakeEmpty(root->Left);
		MakeEmpty(root->Right);
		free(root);	
	}

	return NULL;
}

struct TreeNode* Insert(struct TreeNode* root, int newNodeElement)
{
	if( root == NULL )
	{
		root = malloc(sizeof(struct TreeNode));
		if(root == NULL)
		{
			
		}
		else
		{
			root->Element = newNodeElement;
			root->Left = NULL;
			root->Right = NULL;
		}
	}
	else
	{
		if(newNodeElement < root->Element)
		{
			root->Left = Insert(root->Left, newNodeElement);
		}
		else if(newNodeElement > root->Element)
		{
			root->Right = Insert(root->Right, newNodeElement);
		}
	}
	return root;
}

struct TreeNode* Delete(struct TreeNode* root, struct TreeNode* deleteNode)
{
	return NULL;
}

struct TreeNode* Find(struct TreeNode* root, struct TreeNode* findNode)
{
	return NULL;
}

void FirstOrder(struct TreeNode* root)
{
	printf("%d\n", root->Element);
	if(root->Left != NULL){
		FirstOrder(root->Left);
	}

	if(root->Right != NULL){
		FirstOrder(root->Right);
	}
}

void MiddleOrder(struct TreeNode* root)
{
	if(root->Left != NULL)
	{
		MiddleOrder(root->Left);
	}

	printf("%d\n", root->Element);

	if(root->Right != NULL)
	{
		MiddleOrder(root->Right);
	}
}

int main(int argc, char** argv)
{
	struct TreeNode* root = Insert(NULL, 10);
	root = Insert(root, 3);
	root = Insert(root, 12);
	
	printf("FirstOrder:\n");
	FirstOrder(root);
	printf("MiddleOrder:\n");
	MiddleOrder(root);
	return 0;
}
