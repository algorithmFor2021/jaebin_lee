#include <bits/stdc++.h>
using namespace std;
set<int>primenumber;

void findPrimeNumber()
{
	for (int i = 3; i <= 1000; i += 2)
	{
		bool bPrime = true;

		for (int j = 2; j*j <= i; j++)
		{
			if (i%j == 0)
			{
				bPrime = false;
				break;
			}
		}
		if (bPrime)
			primenumber.emplace(i);
	}
}
struct Node
{
	int x1, x2, x3;
};
int main()
{
	int t = 0;
	cin >> t;
	primenumber.emplace(2);
	findPrimeNumber();
	map<int, Node>sum;
	for (auto &i : primenumber)
	{
		for (auto &j : primenumber)
		{
			for (auto &k : primenumber)
			{
				int sumOfThree = k + j + i;
				if (sumOfThree >= 1000)
					break;
				Node n = { k,j,i };
				sum[sumOfThree] = n;
			}
		}
	}
	while (t--)
	{
		int k;
		cin >> k;
		auto it = sum.find(k);
		if (it != sum.end())
		{
			Node &n = it->second;
			cout << n.x1 << " " << n.x2 << " " << n.x3 << "\n";
		}
		else
		{
			cout << 0 << "\n";
		}

	}
	return 0;
}