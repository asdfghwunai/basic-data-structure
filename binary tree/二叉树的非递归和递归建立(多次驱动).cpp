#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class TreeNode
{
public:
	int data;
	TreeNode *left;
	TreeNode *right;
	TreeNode *parent;
	TreeNode(int num) :data(num), left(NULL), right(NULL), parent(NULL)
	{
	}
	~TreeNode()
	{
		cout << "调用析构函数\n" << endl;
	}
};

void Digui_insert_node(TreeNode *parent,int data)    //递归只看本次能不能成功，不成功就交给下次
{
	TreeNode *cur = new TreeNode(data);
	//不用判断parent为不为空,因为压根到不了parent为空的地方parent->left == NULL或parent->right == NULL就插入了
	if (data < parent->data)
	{ 
		if (parent->left == NULL)   //终止条件,可以插入
		{
			parent->left = cur;
			cur->parent = parent;
			return;
		}
		else
		{
			Digui_insert_node(parent->left, data);
		}
	}
	else if (data > parent->data)
	{
		if (parent->right == NULL)   //终止条件,可以插入
		{
			parent->right = cur;
			cur->parent = parent;
			return;
		}
		else
		{
			Digui_insert_node(parent->right, data);
		}
	}
	else   //相等就不插入直接返回
	{
		delete cur;
		return;
	}


}

void Diedai_insert_node(TreeNode *parent, int data)   //迭代要保证这次成功
{
	TreeNode *p = parent;
	TreeNode *par = NULL;
	TreeNode *cur = new TreeNode(data);
	while (1)
	{
		par = p;   //par是保存的父亲节点,p是孩子
		if (data < p->data)
		{
			p = p->left;
			if (p == NULL)  //找到NULL了,插入
			{
				par->left = cur;
				cur->parent = par;
				break;
			}
		}
			
	
		else if (data>p->data)
		{
			p = p->right;
			if (p == NULL)  //找到NULL了
			{
				par->right = cur;
				cur->parent = par;
				break;
			}		
		}
			
		else
		{
			delete cur;
			return;
		}
			
		
	}

}

TreeNode * Create_Tree(int data[],int len)
{
	TreeNode *root = new TreeNode(data[0]);
	for (int i = 1; i < len; i++)
		//Digui_insert_node(root,data[i]);
		Diedai_insert_node(root, data[i]);
	return root;
}

TreeNode * Search_tree(TreeNode *root,int data)
{
	if (root == NULL)           //终止条件1
	{
		cout << "没有找到" << endl;
		return NULL;
	}
	if (data == root->data)      //终止条件2
	{
		cout << "找到了节点，地址为" << root << endl;
		return root;
	}
		
	else if (data < root->data)
	{
		return Search_tree(root->left, data);   //得加上return,不然只是有转移到下一层，但本层没return
	}
		
	else
		return Search_tree(root->right,data);
	
}

void Delete_tree(TreeNode *root)  //看来想删除得有父节点辅助啊
{
	if (root->left != NULL)   //刚开始先转移，就是先删别人
		Delete_tree(root->left);
	if (root->right != NULL)
		Delete_tree(root->right);
	//开始删除自己了,终止条件

	if (root->parent == NULL)  //如果删除的是树的根节点，就直接删除完事，不用管父节点
	{

	}
	else
	{
		if (root->data < root->parent->data)   //说明是左子树
		{
			root->parent->left = NULL;
			root->parent = NULL;   //切断联系
		}

		else
		{
			root->parent->right = NULL;
			root->parent = NULL;   //切断联系
		}
	}
	
	
	delete root;

}

void Delete_node(TreeNode *root, int data)  //先查找再删除
{
	TreeNode *p=Search_tree(root,data);
	if (p == NULL)
	{
		cout <<"无法找到所以不能删除" << endl;
	}
	else
	{
		Delete_tree(p);
	}
}



void main()
{

	int data[] = {1,2,2,3};
	TreeNode *root=Create_Tree(data,4);

	Search_tree(root,3);
	Search_tree(root,4);


	Delete_node(root,1);


	while (1);
}
