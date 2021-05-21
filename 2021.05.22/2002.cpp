#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, cnt=0;
	cin >> n;
	unordered_map<string, int>first;
	unordered_map<string, int>second;

	for(int i=0;i<n;++i)
	{
		string s;
		cin >> s;
		first[s] = cnt++;
	}

	cnt = 0;

	
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		second[s] = cnt++;
		
	}

	int ans = 0;
	vector<int>order(n,0);
	vector<int>outOrder(n, 0);
	for (auto &it : first)
	{
		int f = it.second;
		int s = second.find(it.first)->second;
		order[s] = f;
		outOrder[f] = s;
	}

	vector<int>visited(n, 0);
	for(int i=n-1;i>=0;--i)
	{
		for(int j=order[i]+1;j<n;++j)
		{
			if(visited[j]==0 && outOrder[j]<i )
			{
				visited[j] = 1;
				ans++;
			}
		}
	}
	
	cout << ans;
	return 0;
}