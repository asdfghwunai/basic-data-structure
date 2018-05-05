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
	ListNode *p = *head;   //一定传二级指针，不然head只是副本的地址
	
	printf("%p %p",*head,p);
	while (1)
	{
		i++;
		cin >> data;
		if (data == 0)  //输入是0跳出
			break;
		
		ListNode *q = new ListNode(data);
		p->next = q;
		p=q;
		
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
	ListNode *dummy=new ListNode(-1);  //得需要一个头结点
	printf("%p ",dummy);
	Build_List(&dummy);

	bianli(dummy->next);

	while (1);

}
