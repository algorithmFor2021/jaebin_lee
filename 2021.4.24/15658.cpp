#include<bits/stdc++.h>
using namespace std;
int n;
int arr[11];
int oper[4];
int ansMin=1'000'000'001,ansMax= -1'000'000'001;
void func(int step,vector<int>&remain_operation,vector<int>&idx)
{
	if(step>=n-1)
	{
		int ans=arr[0];
		int numidx = 1;
		for(int i=0;i<idx.size();++i)
		{
			switch(idx[i])
			{
			case 0: 
				ans+= arr[numidx];
				break;
			case 1:
				ans -= arr[numidx];
				break;
			case 2:
				ans *= arr[numidx];
				break;
			case 3:
				ans /= arr[numidx];
				break;
			}
			numidx++;
		}
		
		ansMin = min(ansMin, ans);
		ansMax = max(ansMax, ans);
		return;
	}

	for(int i=0;i<4;++i)
	{
		if (remain_operation[i] <= 0) continue;
		remain_operation[i]--;
		idx.push_back(i);
		
		func(step + 1, remain_operation, idx);

		remain_operation[i]++;
		idx.pop_back();
	}
}

int main()
{
	cin >> n;
	vector<int>remain, idx;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	for(int i=0;i<4;++i)
	{
		cin >> oper[i];
		remain.push_back(oper[i]);
	}
	
	func(0, remain, idx);
	cout << ansMax << "\n" << ansMin;
	return 0;
}