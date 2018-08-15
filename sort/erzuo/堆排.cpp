#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;



void heap_adjust(int a[], int first, int last)
{
	if (first == last)
		return;

	int temp = a[first];
	for (int j = 2*first+1; j <= last; j++)   //把一条道上清除就行
	{
		if (j<last&&a[j + 1]>a[j])
			j++;
		if (temp > a[j])
			break;
		swap(a[first],a[j]);
		first = j;

	}

}

void heap_sort(int a[],int first,int last)
{

	//for (int i = (last - first) / 2 - 1; i >= 0; i--)   //从下到上，从右到左的进行构建

	//----多路调整------
	for (int i = (last - first+1) / 2 - 1; i >= 0; i--)   //这地方很有讲究，考虑奇数个和偶数个
		heap_adjust(a,i,last);

	//-----单路调整-------
	for (int i = last; i >= 1; i--)
	{
		//swap(a[0],a[last]);     //a[0]保存极值，与最后一个元素进行交换
		swap(a[0], a[i]);              //写错了
		heap_adjust(a, 0, i-1);
	}


}

int main()
{
	/*
	int a [3]= {3,2,1};

	heap_sort(a,0,2);
	*/

	int a[2] = { 3, 2 };

	heap_sort(a, 0, 1);


	for (auto aa : a)
		cout << aa << " ";
	cout << endl;
	while (1);

	return 0;
}
