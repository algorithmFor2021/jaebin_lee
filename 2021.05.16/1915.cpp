#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int d[1001][1001];
int arr[1001][1001];
int main()
{
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			scanf("%1d", &arr[i][j]);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		d[i][0] = arr[i][0];
		ans = max(ans, d[i][0]);
		d[0][i] = arr[0][i];
		ans = max(d[0][i], ans);
	}
	
	for(int i=1;i<n;++i)
	{
		for(int j=1;j<m;++j)
		{
			if(arr[i][j]==0)
			{
				d[i][j] = 0;
			}
			else
			{
				int diagonal = d[i - 1][j - 1];
				int up = d[i - 1][j];
				int left = d[i][j - 1];
				if (diagonal == up && up == left)
				{
					d[i][j] = up + 1;
				}
				else if (diagonal == 0 || up == 0 || left == 0)
				{
					d[i][j] = 1;
				}
				else
				{
					d[i][j] = min(min(diagonal, left), up) + 1;
				}
			}
			ans = max(ans, d[i][j]);
		}
	}
	cout << ans*ans;
	return 0;
}