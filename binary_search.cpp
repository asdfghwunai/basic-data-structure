#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


int binary_search(int A[],int n,int target)
{
	int first = 0;
	int last = n - 1;
	int mid;
	while (first<=last)
	{
		mid = (first + last) / 2;
		if (A[mid] == target)
			return mid+1;
		else if (A[mid] > target)  
			last=mid-1;   //一下子舍弃了一半
		else
			first=mid+1;
	}
	return 0;
}


void main()
{
	int A[] = { 1, 2,3,4,5,5,7 };
	
	cout<<binary_search(A, 7,5);


	while (1);

}
