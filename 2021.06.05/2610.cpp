#include <bits/stdc++.h>
#define JB_MAX 123456789
using namespace std;

vector<int> ans;
int n, m;
int v[101][101];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			v[i][j] = JB_MAX;
		}
		v[i][i] = 0;
	}
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		v[a][b] = 1;
		v[b][a] = 1; //거리
	}

	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			if (i == k)continue;

			for (int j = 1; j <= n; ++j)
			{
				if (i == j) continue;

				if (v[i][j] > v[i][k] + v[k][j])
				{
					v[i][j] = v[i][k] + v[k][j];
					v[j][i] = v[i][j];
				}
			}
		}
	}

	//그룹탐색
	vector<vector<int>>group;
	vector<int>visited(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		if (visited[i]) continue;
		visited[i] = 1;
		vector<int>gr;
		gr.emplace_back(i);
		for (int j = i + 1; j <= n; ++j)
		{
			if (visited[j]) continue;
			if (v[i][j] >= JB_MAX) continue;
			visited[j] = 1;
			gr.emplace_back(j);
		}
		group.emplace_back(gr);
	}


	for (auto &gr : group)
	{

		int globalMinVal = JB_MAX;
		int globalMinIdx = 0;
		for (auto &i : gr)
		{
			int minVal = 0;
			
			for (int j = 1; j <= n; ++j)
			{
				if (v[i][j] >= JB_MAX) continue;
				if (minVal < v[i][j])
				{
					minVal = v[i][j];
				}
			}
			if (globalMinVal > minVal)
			{
				globalMinVal = minVal;
				globalMinIdx = i;
			}
		}

		if (globalMinIdx == 0)
		{
			ans.push_back(*gr.begin());
		}
		else
			ans.push_back(globalMinIdx);
	}

	cout << group.size() << endl;
	sort(ans.begin(), ans.end());
	for (auto &it : ans)
	{
		cout << it << "\n";
	}

	return 0;
}