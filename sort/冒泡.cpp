void bubble_sort(int array[],int n)
{
	for (int i = 0; i <= n - 2; i++)   //比较到倒数第二个数即可
	{
		for (int j = n - 1; j >= i + 1; j--)
		{
			if (array[j] > array[j - 1])
				swap(array[j],array[j-1]);
		}
	}

	for (int i = 0; i <= n - 1; i++)
		cout <<array[i]<< " ";
}

void main()
{
	int a[5] = {3,1,4,5,7};
	bubble_sort(a,5);

	while (1);

}
