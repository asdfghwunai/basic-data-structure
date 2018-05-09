#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


class ListNode{
public:
	int val;
	ListNode *left,*right;

	ListNode(int x) :val(x), left(NULL), right(NULL)
	{}
};


void Build_shuangxiang_List(ListNode **head)
{
	int data = 0;
	int i = 1;
	ListNode *p = NULL,*q=NULL;

	while (1)
	{
		cin >> data;
		if (data == 0)
			break;
		if (i == 1)   //第一次
		{
			*head = new ListNode(data);
			p = *head;
		}
		else
		{
			q = new ListNode(data);
			q->left = p;
			p->right = q;
			p = q;
		}
		i++;

	}
}

void bianli(ListNode *head)
{
	if (head == NULL)
	{
		cout << "双向链表为空无法遍历" << endl;
		return;
	}
		
	ListNode *p=head;
	ListNode *q = NULL;
	cout << "从左向右遍历---" << endl;
	while (p)
	{
		cout <<p->val<< " ";
		if (p->right == NULL)
			q = p;
		p = p->right;
		
	}
	cout << endl;

	cout << "从右向左遍历---" << endl;
	while (q)
	{
		cout << q->val << " ";
		q = q->left;
	}
	cout << endl;
	
}



void main()
{
	
	ListNode *head=NULL;  //得需要一个头结点
	printf("%p ",head);
	Build_shuangxiang_List(&head);


	bianli(head);
	while (1);

}
