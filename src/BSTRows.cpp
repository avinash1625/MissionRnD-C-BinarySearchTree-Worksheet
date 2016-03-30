/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};


int height(struct node *root){
	if (root == NULL)
		return 0;
	else
	{
		int left_height = height(root->left);
		int right_height = height(root->right);
		if (left_height > right_height)
			return left_height + 1;
		else

			return right_height + 1;
	}

}

void Level_Traversal(struct node* root, int level, int ltr,int *arr,int *i)
{
	if (root == NULL)
		return;
	if (level == 1)
	{
		arr[*i] = root->data;
		(*i)++;
	}
	else if (level > 1)
	{
		if (ltr)
		{
			Level_Traversal(root->left, level - 1, ltr,arr,i);
			Level_Traversal(root->right, level - 1, ltr,arr,i);
		}
		else
		{
			Level_Traversal(root->right, level - 1, ltr,arr,i);
			Level_Traversal(root->left, level - 1, ltr,arr,i);
		}
	}
}

int* BSTRighttoLeftRows(struct node* root)
{
	int a[20] = { 0 }, j = 0;
	if (root == NULL)
		return NULL;
	int h = height(root);
	int i;
	bool flag = true;
	for (i = 1; i <= h; i++)
	{
		Level_Traversal(root, i, flag,a,&j);
		flag = !flag;
	}
	return a;
}

