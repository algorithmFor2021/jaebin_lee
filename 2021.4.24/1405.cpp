#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>v(50,vector<int>(50,0));
int n;
double ans=0;
int dir[4][2] = {
	{0,1},
	{0,-1},
	{1,0},
	{-1,0}
};
double probability[4];
struct Node
{
	int curx, cury;
	vector<int>idx;
};
void solve(vector<vector<int>>&v,Node *node)
{
	if(node->idx.size()>=n)
	{
		
		{
			double pro = 1.;
			for(auto &it:node->idx)
			{
				pro *= probability[it];
			}
			ans += pro;
		}
		return; 
	}

	//4방향 가기
	for(int i=0;i<4;++i)
	{
		//들린지 체크
		int tmpx = node->curx, tmpy = node->cury;
		
		int nx = node->curx + dir[i][0];
		int ny = node->cury + dir[i][1];
		

		if(v[nx][ny] >=1)
		{
			continue;
		}
		//등록
		node->idx.push_back(i);
		v[nx][ny]++;
		node->curx = nx;
		node->cury = ny;
		solve(v, node);
		
		v[nx][ny]--;
		node->curx = tmpx, node->cury = tmpy;
		node->idx.pop_back();
	}
}
int main()
{
	cin >> n;
	for(int i=0;i<4;++i)
	{
		cin>> probability[i];
		probability[i] /= 100.;
	}
	vector<int>idx;
	Node node{ 25,25,idx };
	v[25][25] = 1;

	solve(v, &node);
	cout.precision(10);
	cout << ans;
	return 0;
}