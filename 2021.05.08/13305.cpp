#include <bits/stdc++.h>
using namespace std;
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>dist(n, 0);
	vector<int>arr(n, 0);
	for (int i = 0; i < n-1; ++i)
	{
		cin >> dist[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	long long int ans = 0;
	long long int cost = 1000000001;
	long long int d = 0;
	for (int i = 0; i < n; i++)
	{
		if (cost > arr[i])
		{
			//현재 위치에서 저기 나보다 작은곳까지 가면됨
			ans += cost * d;
			cost = arr[i];
			d = 0;
		}
		d += dist[i];
		

		if(i==n-1 && d>0)
		{
			ans += cost * d;
		}
	}
	cout << ans;
	return 0;
}