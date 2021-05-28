#include <bits/stdc++.h>
using namespace std;
int arr[101][101];
int visited[101][101];
int d[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int n, m, k;

bool isRange(int x,int y)
{
	return (x > 0 && y > 0 && x <= n && y <= m);
}
int ans;
int func(int x,int y)
{
	if (visited[x][y])
		return 0;
	visited[x][y] = 1;
	int _cnt = 1;
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + d[i][0];
		int ny = y + d[i][1];
		if (isRange(nx, ny)) {

			if (arr[nx][ny])
				_cnt+=func(nx, ny);
		}
	}
	ans = max(ans, _cnt);
	return _cnt;
}

int main()
{
	
	cin >> n >> m >> k;

	queue<pair<int,int>>q;
	for(int i=0;i<k;++i)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		q.push({a,b });
	}
	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		ans=max(ans,func(x, y));
		
	}
	cout << ans;
	return 0;
}