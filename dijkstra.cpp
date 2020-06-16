//DIJKSTRA - No -ve weights, works for cycles O(V+E)logV
// To find min distance from a source to all other vertices
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli v, E;
struct nodes
{
	lli ver, wt;
};
vector<vector<struct nodes>> g;
set<pair<lli, lli>> findmin;
int val[100000];
int main()
{
	cin >> v >> E;
	lli infi = 100000;
	g.resize(v + 1); //stores all the edges corresponding to the vertex
	for (lli i = 0; i < E; i++)
	{
		lli v1, v2;
		struct nodes a;
		cin >> v1 >> a.ver >> a.wt;
		g[v1].push_back(a);
	}
	for (lli i = 1; i <= v; i++)
	{
		val[i] = infi; //initialise the distance to all the vertices as infinity
	}
	lli s;
	cin >> s;
	val[s] = 0; //initialise distance of source as 0;
	findmin.insert(make_pair(0, s));
	while (findmin.empty() != 1)
	{
		pair<int, int> p = *(findmin.begin());
		lli v0 = p.second;
		for (lli i = 0; i < g[v0].size(); i++)
		{
			lli k = g[v0][i].ver;
			lli w = g[v0][i].wt;
			if (val[k] > val[v0] + w)
			{
				if (val[k] != infi)
				{
					findmin.erase(findmin.find(make_pair(val[k], k)));
				}
				val[k] = val[v0] + w;
				findmin.insert(make_pair(val[k], k));
			}
		}
		findmin.erase(findmin.find(make_pair(val[v0], v0)));
	}
	for (lli i = 1; i <= v; i++)
	{
		cout << val[i] << " ";
	}
	cout << endl;
	return 0;
}
