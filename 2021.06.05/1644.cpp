#include <bits/stdc++.h>
using namespace std;
int number[4'000'001];
vector<int>prime;
int ans = 0;
int n=4'000'000;
void getPrime()
{
	for(int i=2;i<=n;++i)
	{
		if (number[i] == 0) continue;
		
		for(int j=i+i;j<=n;j+=i)
		{
			if (number[j] == 0) continue;
			else number[j] = 0;
		}
		if(number[i])
		{
			prime.emplace_back(i);
		}
	}
}
int main()
{
	for(int i=0;i<=n;++i)
	{
		number[i] = i;
	}
	cin >> n;
	if(n==1)
	{
		cout << 0;
		return 0;
	}
	getPrime();
	const int target = n;
	int start = 0, end = 0;
	int sum = 2;
	while (start <= end)
	{
		
		if (sum > target)
		{
			sum -= prime[start];
			start++;
		}
		else if(sum==target)
		{
			ans++;
			end++;
			if (end >= prime.size())
				break;
			sum += prime[end];
		}
		else
		{
			end++;
			if (end >= prime.size())
				break;
			sum += prime[end];
		}
	}
	cout << ans;
	return 0;
}