/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};

void inorder_wrapper(struct node *root, int *arr, int *i)
{
	if (root == NULL || arr == NULL)
		return;
	inorder_wrapper(root->left, arr, i);
	arr[*i] = root->data;
	(*i)++;
	inorder_wrapper(root->right, arr, i);

}
void inorder(struct node *root, int *arr){
	int k = 0;
	return inorder_wrapper(root, arr, &k);
}
void preorder_wrapper(struct node *root, int *arr, int *i)
{
	if (root == NULL || arr == NULL)
		return;
	arr[*i] = root->data;
	(*i)++;
	preorder_wrapper(root->left, arr, i);
	preorder_wrapper(root->right, arr, i);

}
void preorder(struct node *root, int *arr)
{
	int k = 0;
	preorder_wrapper(root, arr, &k);
}

void postorder_wrapper(struct node *root, int *arr, int *i){
	if (root == NULL || arr == NULL)
		return;
	postorder_wrapper(root->left, arr, i);
	postorder_wrapper(root->right, arr, i);
	arr[*i] = root->data;
	(*i)++;
}
void postorder(struct node *root, int *arr)
{
	int k = 0;
	return postorder_wrapper(root, arr, &k);
}


