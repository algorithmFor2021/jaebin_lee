#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>>v;
int n;
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		v.emplace_back(make_pair(a, b));
	}
	sort(v.begin(), v.end());
	
	priority_queue<int, vector<int>, greater<>>q;
	q.push(v[0].second);
	for (int i = 1; i < n; ++i)
	{
		if (q.top() > v[i].first)
		{
			q.push(v[i].second);
		}
		else
		{
			q.pop();
			q.push(v[i].second);
		}
	}

	cout << q.size();
	return 0;
}