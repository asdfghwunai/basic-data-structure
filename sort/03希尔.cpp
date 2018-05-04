#include<iostream>
#include<vector>
#include<string>
using namespace std;

//突破了O(n2)

void insection_sort(int array[],int n)
{
	int increment = n;
	do   //和插入排序区别就是多种increment，最后一次increment为1,等于1不进去了，就是少了1这次
	{
		increment = increment / 3 + 1;

		for (int i = increment; i < n; i = i + increment)   //待插入牌数
		{
			int temp = array[i];
			int j;
			for (j = i; j > 0; j=j-increment)
			{
				if (temp > array[j - increment])   //想把大牌插入，所以是从大到小排序
					array[j] = array[j -increment];
				else
					break; 
			}
			if (j != i)  //j=i说明刚开始就比前面更小
				array[j] = temp;
		}

	} while (increment>1);


	

	for (int i = 0; i <= n - 1; i++)
		cout <<array[i]<< " ";
}

void main()
{
	int a[7] = {3,1,4,0,5,7,8};
	insection_sort(a,7);

	while (1);

}
