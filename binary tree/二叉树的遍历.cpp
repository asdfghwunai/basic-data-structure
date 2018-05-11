#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<queue>
using namespace std;

class TreeNode
{
public:
	int data;
	int tag;
	TreeNode *left;
	TreeNode *right;
	TreeNode *parent;
	TreeNode(int num) :data(num), left(NULL), right(NULL), parent(NULL), tag(0)
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

//前序遍历
void Digui_pre_traverse(TreeNode *cur)
{
	if (cur == NULL)   //终止条件
		return;   
	else
	{
		cout << cur->data << " ";
		Digui_pre_traverse(cur->left);
		Digui_pre_traverse(cur->right);
	}
}

void Digui_in_traverse(TreeNode *cur)
{
	if (cur == NULL)   //终止条件
		return;
	else
	{	
		Digui_in_traverse(cur->left);
		cout << cur->data << " ";
		Digui_in_traverse(cur->right);
	}
}

void Digui_hou_traverse(TreeNode *cur)
{
	if (cur == NULL)   //终止条件
		return;
	else
	{
		Digui_hou_traverse(cur->left);
		Digui_hou_traverse(cur->right);
		cout << cur->data << " ";
	}
}

void Diedai_pre_traverse(TreeNode *cur)  //方法就是先输出，然后输出过程中把右孩子压入栈
{
	TreeNode *p = cur;
	stack<TreeNode *> s;

	while (p!=NULL||!s.empty())    //p!=NULL是让首次进入循环
	{
		
		while (p != NULL)
		{
			cout << p->data << " ";   //先访问本节点
			if (p->right!=NULL)
			    s.push(p->right);   //s里存的是还没访问的右孩子
			p = p->left;
		}

		if (!s.empty())
		{
			p = s.top();
			s.pop();
			
		}
	}

}

void Diedai_in_traverse(TreeNode *cur)   //方法就是先压左孩子，然后出栈后输出，然后指针指向右孩子看下次循环能压左孩子多少
{
	TreeNode *p = cur;
	stack<TreeNode *> s;

	while (p != NULL || !s.empty())  //p!=NULL只是第一次进
	{
		while (p)
		{
			s.push(p);   //存放左孩子
			p = p->left;
		}

		if (!s.empty())
		{
			p = s.top();
			s.pop();
			cout << p->data << " ";
			p = p->right;    //下次循环访问右子树

		}
	}
}

void  Diedai_hou_traverse(TreeNode *cur)  //方法--先存放左孩子，出栈时没有右孩子就直接输出，有右孩子，就指向右孩子看下次能压左孩子多少(还要记录一下已经访问过右孩子了)
{
	TreeNode *p = cur;
	stack<TreeNode *> s;
	while (p != NULL || !s.empty())  //p!=NULL是第一次进
	{
		while (p)
		{
			s.push(p);   //还是存放左孩子
			p = p->left;
		}
		if (!s.empty())
		{
			p = s.top();
			if (p->right != NULL)   
			{
				//TreeNode *temp=p;   //一种处理方式。。。切断联系,破坏了二叉树
				//p = p->right;
				//temp->right = NULL;
				if (p->tag == 0)
				{
					p->tag = 1;   //说明已经处理过孩子了
					p = p->right;
				}
				else
				{
					p->tag = 0;  //都出栈了，标志可以复原
					s.pop();
					cout << p->data << " ";
					p = NULL;  //这里一定要置0，不然下次又要把这个数压栈
				}
				
			}
			else   //无右孩子直接输出
			{
				s.pop();
				cout << p->data<<" ";
				p = NULL;  //这里一定要置0，不然下次又要把这个数压栈
			}
		}
	}
}


vector<vector <int >> Diedai_ceng_traverse(TreeNode *cur)   //方法----BFS法原则是先访问再入队，先别急着入队，本层访问完再入队
{
	queue<TreeNode *> q,q_temp;
	vector<vector <int >> result;
	vector<int> temp;
	TreeNode *p = NULL;

	if (cur == NULL)
		return result;
	q.push(cur);
	temp.push_back(cur->data);  //当访问了
	result.push_back(temp);

	temp.clear();
	while (!q.empty())
	{
		
		p = q.front();
		q.pop();
		if (p->left != NULL)
		{
			temp.push_back(p->left->data);
			q_temp.push(p->left);
		}
		if (p->right != NULL)
		{
			temp.push_back(p->right->data);
			q_temp.push(p->right);
		}

		if (q.empty())
		{
			q = q_temp;
			while (!q_temp.empty())   //清空栈
				q_temp.pop();

			if (!temp.empty())    //这次没进入新东西就不要再赋值了，不然会压入[]
			{
				result.push_back(temp);
				temp.clear();
			}
			
		}
	}
	return result;
}



void main()
{

	int data[] = {1,0,2,3};
	TreeNode *root=Create_Tree(data,4);

	cout << "前序遍历递归法---";
	Digui_pre_traverse(root);
	cout << endl;
	cout << "中序遍历递归法---";
	Digui_in_traverse(root);
	cout << endl;
	cout << "后序遍历递归法---";
	Digui_hou_traverse(root);
	cout << endl;

	
	cout << "前序遍历递归法---";
	Diedai_pre_traverse(root);
	cout << endl;
	
	cout << "中序遍历递归法---";
	Diedai_in_traverse(root);
	cout << endl;
	
	cout << "后序遍历递归法---";
 	Diedai_hou_traverse(root);
	cout << endl;
	
	cout << "层序遍历递归法---";
	vector<vector<int>> result=Diedai_ceng_traverse(root);
	cout << endl;

	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}

	while (1);
}

