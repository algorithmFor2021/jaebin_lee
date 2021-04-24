#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>>taste;
int ans = 1'000'000'001;
void calc(vector<int>&visited)
{
    int s = 1, b = 0;
    for(int i = 0; i < n; ++i)
    {
        if(visited[i] == 1)
        {
            s *= taste[i].first;
            b += taste[i].second;
        }
    }
    ans = min(ans, abs(s - b));
}

void func(int step, vector<int>&visited)
{
    if(step > n)
        return;
    
    calc(visited);
    
    for(int i = step; i < n; ++i)
    {
        if(visited[i] == 1) continue;
        visited[i] = 1;
        func(i, visited);
        visited[i] = 0;
    }
}
int main()
{
    cin >> n;
    vector<int>visited(n,0);
    for(int i = 0; i < n; ++i)
    {
        int s, b;
        cin >> s >> b;
        taste.push_back(make_pair(s, b));
    }
    for(int i = 0; i < n; ++i)
    {
        visited[i] = 1;
        func(1, visited);
        visited[i] = 0;
    }
    
    cout << ans;
    return 0;
}
