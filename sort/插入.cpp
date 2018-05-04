#include<iostream>
#include<vector>
#include<string>
using namespace std;


void insection_sort(int array[],int n)
{
	for (int i = 1; i < n; i++)   //待插入牌数
	{
		int temp = array[i];
		int j;
		for (j = i; j > 0;j--)
		{
			if (temp > array[j - 1])   //想把大牌插入，所以是从大到小排序
				array[j] = array[j - 1];
			else
				break;
		}
		if (j!=i)  //j=i说明刚开始就比前面更小
		  array[j] = temp;
	}

	for (int i = 0; i <= n - 1; i++)
		cout <<array[i]<< " ";
}

void main()
{
	int a[6] = {3,1,4,5,7,8};
	insection_sort(a,6);

	while (1);

}
