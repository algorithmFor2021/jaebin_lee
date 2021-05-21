#include <bits/stdc++.h>
using namespace std;
char operatorPriority[128];


bool isOperator(string &s)
{
	if (s == "-" || s == "+" || s == "*" || s == "/")
		return true;
	return false;
}
long long int getOperation(long long int first, long long int second, char operation)
{
	switch (operation) {
	case  '-':
		return first - second;
	case '+':
		return first + second;
	case '*':
		return first * second;

	case '/':
		return first / second;
	}

}
vector<string> ret;
void getPost(deque<string> &s)
{

	stack<string>st;
	size_t cnt = 0;
	while (s.size() > cnt)
	{
		if (isOperator(s[cnt]))
		{
			if (st.empty())
			{
				st.push(s[cnt]);
			}
			else
			{
				while (!st.empty() && operatorPriority[st.top()[0]] >= operatorPriority[s[cnt][0]])
				{
					string ss = st.top();
					st.pop();
					ret.push_back(ss);
					
				}
				st.push(s[cnt]);
			}
		}
		else
		{
			ret.push_back(to_string(stoll(s[cnt])));
		}
		cnt++;
	}
	while(!st.empty())
	{
		ret.push_back(st.top());
		st.pop();
	}
}

void calculate(vector<string>&post)
{
	stack<long long>st;
	
	for (size_t i = 0; i < post.size(); ++i)
	{
		if (isOperator(post[i]))
		{
			long long int first = st.top();
			st.pop();
			long long int second = st.top();
			st.pop();
			st.push(getOperation(second, first, post[i][0]));
		}
		else
		{
			st.push(stoll(post[i]));
		}
	}
	cout << st.top();
}

int main()
{
	int a1, a2, a3, a4;
	cin >> a1 >> a2 >> a3 >> a4;
	operatorPriority['+'] = a1;
	operatorPriority['-'] = a2;
	operatorPriority['*'] = a3;
	operatorPriority['/'] = a4;

	string s;
	cin >> s;
	string cal = "";
	string tmp = "";

	deque<string>statement;
	for (size_t i = 0; i < s.size(); ++i)
	{
		string t;
		t.push_back(s[i]);
		if (isOperator(t))
		{
			statement.push_front(tmp);
			statement.push_front(t);
			tmp.clear();
		}
		else
		{
			tmp += s[i];
			if (i == s.size() - 1)
			{
				statement.push_front(tmp);
			}
		}
	}
	getPost(statement);
	calculate(ret);
	return 0;
}