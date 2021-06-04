#include <bits/stdc++.h>
#define JB_MAX 213456789
using namespace std;

int n;
int w[16][16];
int d[1 << 16][16];

int recur(int start, int visit)
{
	//방문 처리
	visit |= (1 << start);

	if (visit == (1 << n) - 1)
	{
		if (w[start][0] > 0)
		{
			return w[start][0];
		}
		else return JB_MAX;
	}

	if (d[visit][start] > 0)
		return d[visit][start];

	d[visit][start] = JB_MAX;
	for (int i = 0; i < n; ++i)
	{
		if (i != start && ((1 << i)& visit) == 0 && w[start][i] > 0)
		{
			int cost = recur(i, visit) + w[start][i];
			d[visit][start] = min(d[visit][start], cost);
		}
	}
	return d[visit][start];
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> w[i][j];
		}
	}
	const int ans = recur(0, 0);
	if (ans == JB_MAX) cout << -1;
	else cout << ans;

	return 0;
}