#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	unordered_set<int> st;
	string nn, mm;
	getline(cin, nn);
	string a;
	getline(cin, a);
	istringstream ss(a);
	string strBuffer;
	while(getline(ss,strBuffer,' '))
	{
		int a = stoi(strBuffer);
		st.insert(a);
	}
	
	
	cin >> m;
	getline(cin, mm);
	getline(cin, a);
	ss = istringstream(a);
	while (getline(ss, strBuffer, ' '))
	{
		int b = stoi(strBuffer);
		if (st.find(b) != st.end())
		{
			cout << 1 << " ";
		}
		else
			cout << 0 << " ";
	}
	
	return 0;
}