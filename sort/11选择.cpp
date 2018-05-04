#include<iostream>
#include<vector>
#include<string>
using namespace std;

void selection_sort(int array[],int n)
{
	int temp;
	int pos;
	for (int i = 0; i <= n - 2; i++)   //比较到倒数第二个数即可
	{
		temp = array[i];
		pos = i;
		for (int j = i+1; j<=n-1; j++)   //冒泡是反着来，选择是正着来
		{
			if (temp < array[j])   //挑出更大的数，所以是从大到小排序
			{
				temp = array[j];
				pos = j;
			}
		}
		if (pos!=i)
		   swap(array[i],array[pos]);
	}

	for (int i = 0; i <= n - 1; i++)
		cout <<array[i]<< " ";
}

void main()
{
	int a[5] = {3,1,4,5,7};
	selection_sort(a,5);

	while (1);

}
