

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
			p->next = *head;
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


void yuesefu(ListNode *head,int m)
{
	ListNode *p = head;
	vector<int> result;

	while (p != p->next)  //说明得比较
	{
		for (int i = 1; i < m - 1; i++)
		{
			p = p->next;   //这时p指向m-1
		}
		result.push_back(p->next->val);
		p->next = p->next->next;  //删除m节点
		p = p->next;  //指向右边
	}
	result.push_back(p->val);

	for (int i = 0; i < result.size(); i++)
		cout << result[i]<<" ";
}

void main()
{
	ListNode *head=NULL;  //得需要一个头结点
	printf("%p ",head);
	Build_Circle_List(&head);

	int m = 6;
	yuesefu(head,m);

	while (1);

}
