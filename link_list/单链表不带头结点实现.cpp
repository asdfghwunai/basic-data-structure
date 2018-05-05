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
	ListNode *p = *head;   //不能用p替代head进行操作,p和*head都是0，但是p的内存地址不是*head的内存地址
	
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

void main()
{
	ListNode *head=NULL;  //得需要一个头结点
	printf("%p ",head);
	Build_List(&head);

	bianli(head);

	while (1);

}
