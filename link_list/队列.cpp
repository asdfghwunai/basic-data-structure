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

//方法---入队当成尾插法，出队当成头删法
void Enqueue(ListNode **head,int data)
{
	if (*head == NULL)
	{
		*head = new ListNode(data);
		return;
	}
	ListNode *p = *head;
	ListNode *q = NULL;
	while (p->next)  //找到最后一个节点，可不是NULL啊,其实就是尾插法
	{
		p = p->next;
		
	}

	q = new ListNode(data);
	p->next = q;
}

void Dequeue(ListNode **head)   //因为里面要改head,所以用二级指针 
{
	if (*head == NULL)
	{
		cout << "队列为空不能删除\n";
		return;
	}

	ListNode *temp = *head;
	*head = (*head)->next;

	temp->next = NULL;     //这里要注意一定要切断与后面节点的联系，不然会调用3次析构函数，印证了delete和delete[]对普通类型是相同的
	delete temp;
		
}

void bianli(ListNode *head)
{
	if (head == NULL)
	{
		cout << "队列为空无法遍历" << endl;
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
	Enqueue(&head,1);

	Enqueue(&head, 2);
	Enqueue(&head, 3);
	bianli(head);
	Dequeue(&head);

	bianli(head);
	while (1);

}
