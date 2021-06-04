#include <bits/stdc++.h>
using namespace std;

int parent[201];
int n, m;

int myFind(int x)
{
	if (parent[x] != x)
	{
		parent[x] = myFind(parent[x]);
	}
	return parent[x];
}
void myUnion(int x, int y) {
	x = myFind(x);
	y = myFind(y);

	if (x == y)
		return;
	if (y > x)
		parent[y] = x;
	else
		parent[x] = y;
}
int main()
{
	cin >> n >> m;
	for(int i=1;i<=n;++i)
	{
		parent[i] = i;
	}
	for (auto i = 1; i <= n; ++i)
	{
		int b;
		for (auto j = 1; j <= n; ++j)
		{
			cin >> b;
			if (b == 1)
			{
				myUnion(i, j);
			}
		}
	}
	
	int arrival = 0;
	for (int i = 1; i <= m; ++i)
	{
		int a;
		cin >> a;
		if (i == 1)
			arrival = myFind(a);
		if (arrival != myFind(a))
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";

	return 0;
}