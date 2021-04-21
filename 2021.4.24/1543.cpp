#include <bits/stdc++.h>
using namespace std;
int ans = 0;
string s, findString;
int sz, fsz;

int main()
{
	getline(cin, s);
	getline(cin, findString);

	sz = s.size();
	fsz = findString.size();
	
	
	for(int i=0;i<=sz-fsz;++i)
	{
		int num = 0;
		for(int j=0;j<fsz;++j)
		{
			if(s[i+j]==findString[j])
			{
				num++;
			}
			else
			{
				break;
			}
		}

		if(num==fsz)
		{
			ans++;
			i += fsz-1;
		}
	}
	cout << ans;
	return 0;
}
