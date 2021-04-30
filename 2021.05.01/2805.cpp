#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int start = 0, end = 0;
	int n, m;
	cin >> n >> m;
	vector<int>v(n, 0);
	for (auto &it : v)
	{
		cin >> it;
	}

	start = 0;
	end = 1'000'000'000;

	int midHeight;
	while (start <= end)
	{
		midHeight = (start + end) / 2;
		long long int sum = 0;
		for (auto &it : v)
		{
			if (midHeight < it)
			{
				sum += it - midHeight;
			}
		}

		if (sum == m)
		{
			cout << midHeight;
			return 0;
		}
		else if (sum < m)
		{
			end = midHeight - 1;
		}

		else
			start = midHeight + 1;
	}
    midHeight=(start+end)/2;
	cout << midHeight;
	return 0;

}