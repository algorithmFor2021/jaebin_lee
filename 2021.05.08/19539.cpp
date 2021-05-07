//미통과
#include <bits/stdc++.h>
using namespace std;
int numberCount[5];
int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int height;
		cin >> height;
		if (height >= 4)
		{
			int num = height % 3;
			if (num == 1)
			{
				numberCount[4]++;
			}
			else if (num == 2)
			{
				numberCount[2]++;
			}
		}
		else if (height == 2)
		{
			numberCount[2]++;
		}
		else if (height == 1)
		{
			numberCount[1]++;
		}
	}
	bool bOneNumberCountIsMoreThanTwo = false;
	if (numberCount[1] > numberCount[2])
	{
		numberCount[1] = numberCount[1] - numberCount[2];
		numberCount[2] = 0;
		bOneNumberCountIsMoreThanTwo = true;
	}
	else
	{
		numberCount[2] = numberCount[2] - numberCount[1];
		numberCount[1] = 0;
	}

	if ((numberCount[1] + numberCount[2] * 2 + numberCount[4] * 4) % 3 != 0)
	{
		goto NO;
	}

	if (bOneNumberCountIsMoreThanTwo) //1과 4만 남음
	{
		int num = numberCount[1] / 2;
		if (num >= numberCount[4])
		{
			numberCount[1] -= numberCount[4] * 2;
			numberCount[4] = 0;
			if (numberCount[1] != 0)
				goto NO;
		}
		else
		{
			while (numberCount[1] >= 2 && numberCount[4] > 0)
			{
				numberCount[1] -= 2;
				numberCount[4]--;
			}
			if ((numberCount[1] + numberCount[4] * 4) % 3 != 0)
			{
				goto NO;
			}
		}
	}
	else //2와 4만 남은 상황
	{
		int num = min(numberCount[2], numberCount[4]);
		numberCount[2] -= num;
		numberCount[4] -= num;
		if ((numberCount[2] * 2 + numberCount[4] * 4) % 3 != 0)
		{
			goto NO;
		}
	}
	cout << "YES";
	return 0;
NO:
	cout << "NO";
	return 0;
}