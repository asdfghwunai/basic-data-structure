#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


class ListNode{
public:
	int val;
	ListNode *next;

	ListNode(int x) :val(x), next(NULL)
	{}
};

void Build_List(ListNode **head)
{
	int data;
	int i = 0;
	ListNode *p = *head;   //不能用p替代head进行操作,p和*head都是0，只是p暂时指向了head的指向,但是p的内存地址不是*head的内存地址
	
	printf("%p %p",*head,p);
	while (1)
	{
		i++;
		cin >> data;
		if (data == 0)  //输入是0跳出
			break;
		if (i == 1)    //第一个数
		{
			*head = new ListNode(data);  //重定向*head的指向
			p = *head;
		}
		else
		{
			ListNode *q = new ListNode(data);
			p->next = q;
			p = q;
		}	
	}
}

void Build_Circle_List(ListNode **head)
{
	int data;
	int i = 0;
	ListNode *p = *head;   //不能用p替代head进行操作,p和*head都是0，但是p的内存地址不是*head的内存地址
	
	printf("%p %p",*head,p);
	while (1)
	{
		i++;
		cin >> data;
		if (data == 0)  //输入是0跳出
		{
			p->next = *head;   //和上面的区别在这里。就是最后一个节点不指向NULL了
			break;
		}
			
		if (i == 1)
		{
			*head = new ListNode(data);  //重定向*head的指向
			p = *head;
		}
		else
		{
			ListNode *q = new ListNode(data);
			p->next = q;
			p = q;
		}	
	}
}

void bianli(ListNode *p)
{
	if (p == NULL)
		cout << "链表为空"<<endl;
	else
	{
		cout << "链表数据为:\n";
		while (p)
		{
			cout <<p->val<< " ";
			p = p->next;
		}
		cout << endl<<"遍历结束！";
	}
}

void reverse(ListNode *p)   //照leetcode上的方法
{
	if (p == NULL)
	{
		cout << "链表为空无法反转" << endl;
		return;  //得return一下，不然ListNode *cur = pre->next;会出异常
	}	

		
	ListNode *dummy = new ListNode(-1);
	dummy->next = p;

	ListNode *pre = dummy->next;
	ListNode *cur = pre->next;

	while (cur)
	{
		pre->next = cur->next;  //pre保持不变
		cur->next = dummy->next;  //后一个与前一个连起来
		dummy->next = cur;

		cur = pre->next;
	}

	cout << "反转后遍历:\n";
	bianli(dummy->next);
}

int Return_mid(ListNode *head)
{
	ListNode *cur = head;
	ListNode *mid = head;
	int i = 0;
	int j = 0;

	while (cur)
	{
		if (i / 2 > j)  //0,1,2时当i为2时 j由0变1
		{
			j++;
			mid = mid->next;
		}
	
		i++;
		cur = cur->next;
	}
	return mid->val;
}

void main()
{
	ListNode *head=NULL;  //得需要一个头结点
	printf("%p ",head);
	Build_List(&head);

	bianli(head);
	reverse(head);

	while (1);

}
