#include <bits/stdc++.h>
using namespace std;
int v, E, cur;
vector<vector<int>> g;
vector<vector<int>> h;
int no;
stack<int> s;
stack<int> s1;
vector<int> vis(300000, 0);
vector<int> ans(300000, 0);
int count1;
int dfs()
{
    int p = cur;
    if (no == 0)
    {
        for (int j = 0; j < g[cur].size(); j++)
        {
            int k = g[cur][j];
            if (vis[k] == 0)
            {
                s.push(cur);
                cur = k;
                vis[k] = 1;
                dfs();
            }
        }
    }
    else if (no == 1)
    {
        for (int j = 0; j < h[cur].size(); j++)
        {
            int k = h[cur][j];
            if (vis[k] == 0)
            {
                s.push(cur);
                cur = k;
                vis[k] = 1;
                count1++;
                ans[cur] = 1;
                dfs();
            }
        }
    }

    if (cur == p)
    {
        if (s.empty() == 1)
        {
            return 0;
        }
        else
        {
            if (no == 1)
                cout << cur << " ";
            vis[cur] = 2;
            s1.push(cur);
            int t = s.top();
            s.pop();
            cur = t;
            dfs();
        }
    }
}
int call_dfs()
{
    for (int i = 1; i <= v; i++)
    {
        if (vis[i] == 0)
        {
            //cout << "for" << i << " ";
            cur = i;
            vis[i] = 1;
            no = 0;
            dfs();
            //cout << i << " ";
            vis[cur] = 2;
            s1.push(cur);
        }
    }
}
int call_scp()
{
    while (!s.empty())
    {
        s.pop();
    }
    for (int i = 1; i <= v; i++)
    {
        vis[i] = 0;
    }
    while (!s1.empty())
    {
        int r = s1.top();
        if (vis[r] == 0)
        {
            count1 = 0;
            //cout << "for" << r <<" ";
            cur = r;
            vis[r] = 1;
            count1++;
            ans[cur] = 1;
            no = 1;
            dfs();
            cout << r << " ";
            if (count1 == 1)
            {
                ans[cur] = 0;
            }
            vis[cur] = 2;
        }
        s1.pop();
    }
}
int main()
{
    cin >> v >> E;
    g.resize(v + 1);
    h.resize(v + 1);
    vis.resize(v + 1);
    ans.resize(v + 1);
    for (int i = 0; i < E; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        h[v2].push_back(v1);
    }
    call_dfs();
    //cout << endl ;
    //cout << s1.top();
    //cout << endl;
    call_scp();
    cout << endl;
    // for(int i=1;i<=v;i++)
    // {
    // 	cout << ans[i] << " ";
    // }
    // cout << endl;
}
