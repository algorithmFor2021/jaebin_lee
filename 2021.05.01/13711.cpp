#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int>v(n, 0);
	vector<int>arr;
	for(int i=0;i<n;++i)
	{
		cin >> v[i];
	}
	map<int, int>mp;
	for(int i=0;i<n;++i)
	{
		int s;
		cin >> s;
		mp[s] = i;
	}
	for(int i=0;i<n;++i)
	{
		arr.push_back(mp.find(v[i])->second);
	}
	
	int ans = 1;
	vector<int>as;
	for(int i=0;i<n;++i)
	{
		if (as.empty())
		{
			as.push_back(arr[i]);
			continue;
		}
		if(as.back()<arr[i])
		{
			as.push_back(arr[i]);
			ans++;
		}
		else
		{
			auto it=lower_bound(as.begin(), as.end(),arr[i]);
			*it = arr[i];
		}
		
	}

	cout << ans;
	return 0;
}