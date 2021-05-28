//못품
#include <bits/stdc++.h>
#define JB_MAX 123456789
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>>adj(n + 1, vector<int>(n + 1, JB_MAX));
	vector<vector<vector<int>>>list(n + 1, vector<vector<int>>(n + 1));
	//i->j로 가는데 가장 빠르게 갔을 때 지나간 번호
	for (int i = 0; i < m; ++i)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		adj[a][b] =min(adj[a][b], cost);
		list[a][b].push_back(b);
	}
	int start, last;
	cin >> start >> last;

	//dijkstra
	vector<int>d(n + 1);
	vector<bool>visited(n + 1, false);
	for (int i = 1; i <= n; ++i)
	{
		adj[i][i] = 0;
		d[i] = adj[start][i];
	}
	visited[start] = true;

	for (int i = 1; i < n; ++i)
	{
		int idx = 1;
		int tmp = JB_MAX;
		for (int j = 1; j <= n; ++j)
		{
			if (d[j] < tmp && !visited[j])
			{
				tmp = d[j];
				idx = j;
			}
		}

		visited[idx] = true;
		for (int j = 1; j <= n; ++j)
		{
			if (visited[j]) continue;
			if (d[idx] + adj[idx][j] < d[j])
			{
				list[start][j].clear();
				list[start][j] = list[start][idx];
				list[start][j].insert(list[start][j].end(), list[idx][j].begin(), list[idx][j].end());
				d[j] = d[idx] + adj[idx][j];
			}
		}
	}
	cout << d[last] << "\n";
	cout << list[start][last].size() + 1 << "\n";
	cout << start << " ";
	for (auto i=0;i< list[start][last].size()-1;++i)
	{
		cout << list[start][last][i] << " ";
	}
	cout << list[start][last][list[start][last].size() - 1];
	return 0;
}