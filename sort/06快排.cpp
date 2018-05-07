#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int Partition(int a[],int low,int high)
{
	int budong = a[low];  //别写成a[0]，因为a是不变的
	while (low < high)
	{
		while (low < high&&a[high] >= budong)
			high--;
		swap(a[low],a[high]);  //此时a[low]是小于budong的数,a[high]是budong,之间的不确定
		while (low < high&&a[low] <= budong)
			low++;
		swap(a[low],a[high]); //此时a[low]是budong,a[high]是大于budong的数,之间不确定
	}
	return low;
}

void Quick_sort(int a[],int low,int high)  //这个才是递归的
{
	if (low < high)  //low<high才能分段
	{
		int budong = Partition(a, low, high);
		Quick_sort(a, low, budong - 1);
		Quick_sort(a, budong + 1, high);
	}
	
}



void main()
{
	int a[] = { 4, 3, 6, 8, 1 };
	Quick_sort(a,0,4);
	
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
		cout << a[i]<<" ";


	while (1);

}
