#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void merge(int a[],int m,int b[],int n,int c[])
{
	int k = 0;

	int i = 0,j=0;
	while (i < m&&j < n)  //方法   双指针
	{
		if (a[i] <= b[j])
		{
			c[k++] = a[i++];
		}
		else
			c[k++] = b[j++];
	}
	for (; i < m; )
		c[k++] = a[i++];
	for (; j < n; )
		c[k++] = b[j++];

	for (int i = 0; i < m + n; i++)    //转移值
		a[i] = c[i];

	/*
	for (int i = 0; i < m + n;i++)
	{
		cout <<a[i] <<" ";
	}
	*/
		
}

void merge_sort(int a[],int n,int c[])
{
	cout << "--进入递归函数----" << endl;
	if (n == 1)
		return;
	
	merge_sort(a,n/2,c);   //排左半边
	merge_sort(a+n/2, n-n / 2, c);  //排右半边
	merge(a,n/2,a+n/2,n-n/2,c);   //融合
}

void main()
{
	int a[] = { 1, 6, 8, 2, 3, 9 };
	int *c = (int *)malloc(sizeof(a));
	merge_sort(a,6,c);

	for (int i = 0; i < sizeof(a) / sizeof(int);i++)
	{
		cout << a[i] << " ";
	}
	


	while (1);

}
