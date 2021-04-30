#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int>v;
	int ans = 1;
	for(int i=0;i<n;++i)
	{
		int a;
		cin >> a;
		if (v.empty())
		{
			v.push_back(a);
			continue;
		}
		if(v.back()<a)
		{
			v.push_back(a);
			ans++;
		}
		else
		{
			auto it=lower_bound(v.begin(), v.end(),a);
			*it = a;
		}
		
	}

	cout << ans;
	return 0;
}