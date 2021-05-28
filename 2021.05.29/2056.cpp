#include <bits/stdc++.h>
using namespace std;
int d[10001];
int work_time[10001];
int visited[10001];
vector<vector<int>>work_list;
int n;
int func(int i)
{
	if (visited[i]) return d[i];
	visited[i] = 1;
	d[i] += work_time[i];
	int num = 0;
	for (auto &it : work_list[i])
	{
		num=max(num,func(it));
	}
	return d[i]+=num;
}
int main()
{

	cin >> n;
	work_list = vector<vector<int>>(n + 1); //이전 작업 넣어둠
	for (int i = 0; i < n; ++i)
	{
		int work_count;
		cin >> work_time[i + 1];
		cin >> work_count;
		for (int j = 0; j < work_count; ++j)
		{
			int pre_work;
			cin >> pre_work;
			work_list[i + 1].push_back(pre_work);
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		func(i);
	}
	int ans = d[1];
	for (int i = 2; i <= n; ++i)
	{
		ans = max(ans, d[i]);
	}
	cout << ans;

	return 0;
}