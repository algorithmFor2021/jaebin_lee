#include<bits/stdc++.h>
using namespace std;
int n, m;
int visited[1001];
int d[1001];
vector<vector<int>>v_ref;

int recur(int s)
{
	if (visited[s] == 1)
		return d[s];
	visited[s] = 1;
	for(auto &it:v_ref[s])
	{
		d[s] = max(d[s],recur(it)+1);
	}
	return d[s];
}

int main()
{
	cin >> n >> m;
	v_ref = vector<vector<int>>(n + 1);
	
	for(int i=0;i<m;++i)
	{
		int prior, post;
		cin >> prior>>post;
		v_ref[post].push_back(prior);
	}
	for (int i = 1; i <= n; ++i)
	{
		if (v_ref[i].empty())
			d[i] = 1;
	}
	
	for(int i=1;i<=n;++i)
		recur(i);
	for(int i=1;i<=n;++i)
	{
		cout << d[i]<< " ";
	}
	return 0;
}