#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//方法就是迭代一下即可----首先构建一个大顶堆，然后替换---调整---替换----调整
void Heap_adjust(int a[],int first,int last)
{
	int temp = a[first];
	for (int j = 2 * first + 1; j <= last; j++)
	{
		if (j<last&&a[j + 1]>a[j])   //j<last是为了有j+1
			j++;      //找到孩子中最大的
		if (temp > a[j])   //构建成大顶推
			break;
		swap(a[first],a[j]);
		first = j;    //迁移到孩子
	}
}

void  Heap_sort(int a[],int first,int last)
{
	for (int i = (last - first + 1) / 2 - 1; i >= 0; i--)  //自下向上,自右向左调整
		Heap_adjust(a,i,last);

	for (int i = last; i > 0; i--)
	{
		swap(a[0], a[i]);  //与最后一个交换
		Heap_adjust(a, 0, i-1);  //其余的调整一下
	}
}

void main()
{
	int a[] = {4,3,7,2,9,0,-1};
	Heap_sort(a,0,6);

	for (int i = 0;i<sizeof(a)/sizeof(int);i++)
	{
		cout <<a[i] <<" " ;
	}
	

	while (1);
}
