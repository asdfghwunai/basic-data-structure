#include<iostream>

using namespace std;

typedef struct Node
{
	int data;
	Node *left, *right;

	Node():data(-1),left(nullptr),right(nullptr){}

}BiNode,*BiTree;

BiNode* Create()
{
	
	int x;
	cin >> x;    //递归的输入
	if (x == -1)
		return nullptr;
	BiNode *root = new BiNode;
	root->data = x;
	root->left = Create();     //当成前序遍历
	root->right = Create();

	return root;
}

void Pre_traverse(BiNode *root)
{
	if (root == NULL)
		return;
	cout << root->data<<endl;
	Pre_traverse(root->left);
	Pre_traverse(root->right);
}

int main()
{
	BiNode *p = Create();
	Pre_traverse(p);

	while (1);

	return 0;
}
