#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int>crane(n, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> crane[i];
	}
	sort(crane.begin(), crane.end(), greater<>());

	int m;
	cin >> m;
	vector<int>load;

	for (int i = 0; i < m; ++i)
	{
		int tmp;
		cin >> tmp;
		if (tmp > *crane.begin())
		{
			cout << -1;
			return 0;
		}
		load.push_back(tmp);
	}
	sort(load.begin(), load.end(), greater<>());
	
	int ans = 0;
	while (1)
	{
		if (load.empty())
		{
			cout << ans;
			break;
		}
		ans++;
		int index = 0;

		for(auto l=load.begin();l!=load.end();)
		{
			if(index==crane.size())
			{
				break;
			}
			if (crane[index] >= *l)
			{
				index++;
				l = load.erase(l);
			}
			else
				++l;
		}
	}
	return 0;
}