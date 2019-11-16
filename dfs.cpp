#include<bits/stdc++.h>
using namespace std;
int v,E;
vector<vector < int > > g; // adjacency list
vector <int> vis; // stores visit status
int dfs(int cur)
{
	int p =cur;
	for(int j=0;j<g[cur].size();j++)
	{
		int k =g[cur][j];
		if(vis[k]==0)
		{
			vis[k]=1;
			dfs(k);

		}
	}
	cout << cur <<" ";
	return 0;
}
int call_dfs()
{
	for(int i=1;i<=v;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			dfs(i);

		}
	}
}
int main()
{
	cin >> v >> E;
	g.resize(v+1);
	vis.resize(v+1);
	for(int i=1;i<=v;i++)
	{
		vis[i]=0;
	}
	for(int i=0;i<E;i++)
	{
		int v1,v2;
		cin >> v1 >> v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);		
	}
	call_dfs();
}
