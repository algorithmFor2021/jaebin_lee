#include<bits/stdc++.h>
using namespace std;

class Trie
{
public:
	map<string, Trie*>mp;
	bool isTerminal;
	Trie()
	{
		isTerminal = false;
	}
	~Trie()
	{

	}

	void insert(vector<string> &s, int cnt)
	{
		if (s.size() == cnt)
		{
			isTerminal = true;
		}
		else {

			auto str = mp.find(s[cnt]);
			Trie *tr;
			if (str == mp.end())
			{
				tr = new Trie();
			}
			else
			{
				tr = str->second;
			}
			mp[s[cnt]] = tr;
			tr->insert(s, cnt + 1);
		}
	}

	void print(int cnt)
	{
		if (mp.empty())
		{
			return;
		}
		int loop = 0;
		for(auto &it:mp)
		{
			if(loop!=0 || cnt!=0)
				cout << "\n";
			int count = cnt;
			while(count--)
			{
				cout << "--";
			}
			cout << it.first;
			it.second->print(cnt +1);
			loop++;
		}
	}
};

int main()
{
	int n;
	cin >> n;
	Trie *root = new Trie();
	for (int i = 0; i < n; ++i)
	{
		int m;
		cin >> m;
		vector<string>s;
		for (int j = 0; j < m; ++j)
		{
			string ss;
			cin >> ss;
			s.push_back(ss);
		}
		root->insert(s, 0);
	}
	root->print(0);

	return 0;
}