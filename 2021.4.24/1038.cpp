#include <bits/stdc++.h>
using namespace std;
set<string>ans;

class myclass
{
public:
	myclass(const string &_s) :s(_s) { }
	string s;
	bool operator<(myclass &a)
	{
		if (this->s.size() == a.s.size())
		{
			return s < a.s;
		}
		else
			return this->s.size() < a.s.size();
	}
};
vector<myclass>v;

string solve(int n)
{
	int step = 2; //자릿수
	while (ans.size() < 1023)
	{
		vector<string>tmp;

		for (int i = 1; i < 10; ++i)
		{
			for (auto &it : ans)
			{
				string s = to_string(i);

				if (s > it && step >= it.size())
				{
					s += it;
					tmp.emplace_back(s);
				}
			}
		}
		step++;
		for (auto &it : tmp)
		{
			ans.emplace(it);
		}
	}

	for (auto &it : ans)
	{
		myclass asd(it);
		v.emplace_back(asd);
	}
	sort(v.begin(), v.end());
	return v[n].s;
}

int main()
{
	int n = 1000;
	cin >> n;
	if (n >= 1023)
	{
		cout << -1;
		return 0;
	}
	for (int i = 0; i < 10; ++i)
	{
		ans.emplace(to_string(i));
	}
	cout << solve(n);

	return 0;
}