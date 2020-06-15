#include <bits/stdc++.h>
using namespace std;
int v, E;
vector<vector<int>> g;
queue<int> q;
vector<int> vis;
int bfs()
{
	if (q.empty())
	{
		return 0;
	}

	int curr = q.front();
	cout << curr << " ";
	//q.pop();
	for (int i = 0; i < g[curr].size(); i++)
	{
		int k = g[curr][i];
		if (vis[k] == 0)
		{
			q.push(k);
			vis[k] = 1;
		}
	}
	q.pop();
	//vis[curr]=2;
	//cout << curr << " ";
	return bfs();
}
int main()
{
	cin >> v >> E;
	g.resize(v + 1);
	vis.resize(v + 1);
	for (int i = 0; i < E; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	for (int i = 1; i <= v; i++)
	{
		vis[v] = 0;
	}
	for (int i = 1; i <= v; i++)
	{
		if (vis[i] == 0)
		{
			q.push(i);
			vis[i] = 1;
			bfs();
		}
	}
}
