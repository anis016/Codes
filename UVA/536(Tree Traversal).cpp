#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
int preIndex;
struct node
{
  char data;
  struct node* left;
  struct node* right;
};

/* UTILITY FUNCTIONS */
/* Function to find index of value in arr[start...end]
   The function assumes that value is present in in[] */
int search(char arr[], int strt, int end, char value)
{
  int i;
  for(i = strt; i <= end; i++)
  {
    if(arr[i] == value)
      return i;
  }
}
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */

struct node* newNode(char data)
{
  struct node* node = (struct node*)malloc(sizeof(struct node));

  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}

/*

Algorithm: buildTree()
1) Pick an element from Preorder. Increment a Preorder Index Variable (preIndex in below code) to pick next element in next recursive call.
2) Create a new tree node tNode with the data as picked element.
3) Find the picked element’s index in Inorder. Let the index be inIndex.
4) Call buildTree for elements before inIndex and make the built tree as left subtree of tNode.
5) Call buildTree for elements after inIndex and make the built tree as right subtree of tNode.
6) return tNode.

Recursive function to construct binary of size len from
Inorder traversal in[] and Preorder traversal pre[].  
Initial values of inStrt and inEnd should be 0 and len -1.
The function doesn't do any error checking for cases where inorder and preorder do not form a tree

*/

struct node* buildTree(char in[], char pre[], int inStrt, int inEnd)
{
  if(inStrt > inEnd)
     return NULL;
 
  /* Pick current node from Preorder traversal using preIndex
    and increment preIndex */
  struct node *tNode = newNode(pre[preIndex++]);
 
  /* If this node has no children then return */
  if(inStrt == inEnd)
    return tNode;
 
  /* Else find the index of this node in Inorder traversal */
  int inIndex = search(in, inStrt, inEnd, tNode->data);
 
  /* Using index in Inorder traversal, construct left and
     right subtress */
  tNode->left = buildTree(in, pre, inStrt, inIndex-1);
  tNode->right = buildTree(in, pre, inIndex+1, inEnd);
 
  return tNode;
}

void Postorder(struct node* node)
{
  if (node == NULL)
     return;
 
  /* first recur on left child */
  Postorder(node->left);

  /* now recur on right child */
  Postorder(node->right);
 
  /* then print the data of node */
  printf("%c", node->data);
}

int main()
{
	char in[100], pre[100];

	while(scanf("%s %s", pre, in)==2)
	{
		preIndex = 0;
		int len = strlen(in);
		struct node *root = buildTree(in, pre, 0, len - 1);

		Postorder(root);
		printf("\n");
	}
	return 0;
}