#include<iostream>

using namespace std;

int sum(int a[],int n)
{
	if (n == 0)
		return a[0];       //此return是最后一层返回给上一层的
	return sum(a, n - 1) + a[n];   //此return是一般返回
}

int main()
{
	int a[4] = {1,2,3,4};
	cout << sum(a,3);

	while (1);
	return 0;
}

