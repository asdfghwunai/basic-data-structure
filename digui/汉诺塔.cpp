void hannuo(int n, char a, char b, char c)
{
	if (n == 1)
		cout << n << "----" << a << "to" << c << endl;
	else
	{
		hannuo(n-1,a,c,b);
		cout << n << "----" << a << "to" << c << endl;
		hannuo(n-1,b,a,c);
	}
}
