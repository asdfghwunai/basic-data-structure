void Get_primer(long n,vector<long> &primer)
{
	for (int i = 2; i <= n; i++)   //大循环，要判断的数
	{ 
		bool isP = 1;
		for (int j = 2; j < i; j++)
		{
			if (i%j == 0)
			{
				isP = 0;
				break;
			}	
		}
		if (isP)
			primer.push_back(i);
	}

	for (int i = 0; i < primer.size(); i++)
		cout << primer[i]<< " ";
}
