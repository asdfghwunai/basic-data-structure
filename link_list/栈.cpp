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
	~ListNode()
	{
		delete next;
		next = NULL;
		cout <<"调用析构函数"<< endl;
	}
};

//方法---其实就是头插法和头删法
void Push(ListNode **head,int data)
{
	if (*head == NULL)
	{
		*head = new ListNode(data);
		return;
	}
	ListNode *q = NULL;
	

	q = new ListNode(data);   //其实就是头插法
	q->next = *head;
	*head = q;   
}

void Pop(ListNode **head)   //因为里面要改head,所以用二级指针 
{
	if (*head == NULL)
	{
		cout << "队列为空不能删除\n";
		return;
	}

	ListNode *temp = *head;
	*head = (*head)->next;

	temp->next = NULL;     //这里要注意一定要切断与后面节点的联系，不然会调用3次析构函数
	delete temp;
		
}

void bianli(ListNode *head)
{
	if (head == NULL)
	{
		cout << "双向链表为空无法遍历" << endl;
		return;
	}
	cout <<"遍历结果\n" ;
	ListNode *p = head;
	while (p)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}



void main()
{
	ListNode *head = NULL;
	Push(&head,1);
	Push(&head, 2);
	Push(&head, 3);
	bianli(head);

	Pop(&head);
	Pop(&head);

	bianli(head);
	while (1);

}
