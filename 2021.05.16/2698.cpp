#include <bits/stdc++.h>
using namespace std;

int arr[101][101][2]; //n개중 k개가 연속된 수일 때 끝자리가 0인 수열의 개수

void init()
{
	arr[2][0][0] = 2;
	arr[2][0][1] = 1;
	arr[2][1][0] = 0;
	arr[2][1][1] = 1;

	/*arr[3][0][0] = 3;
	arr[3][0][1] = 2;
	arr[3][1][0] = 1;
	arr[3][1][1] = 1;
	arr[3][2][0] = 0;
	arr[3][2][1] = 1;*/

	for (int i = 3; i < 101; ++i)
	{
		arr[i][0][0] = arr[i - 1][0][1] + arr[i - 1][0][0];
		arr[i][0][1] = arr[i - 1][0][0];

		for (int j = 1; j < i - 1; ++j)
		{
			arr[i][j][0] = arr[i - 1][j][0] + arr[i - 1][j][1];
			arr[i][j][1] = arr[i - 1][j - 1][1]+arr[i-1][j][0];
		}
		arr[i][i - 1][0] = 0;
		arr[i][i - 1][1] = 1;
	}
}
int main()
{
	init();
	int t;

	cin >> t;

	while (t--)
	{
		int n, k;
		cin >> n >> k;
		cout << arr[n][k][0] + arr[n][k][1] << "\n";
	}
	return 0;
}