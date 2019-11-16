#include<bits/stdc++.h>
using namespace std;
int main ()
{
	vector <vector <int> > g;
	int v,E;
	g.resize(v+1);
	cin >> v >> E;
	for(int i=0 ; i<E;i++)
	{
		int v1,v2;
		cin >> v1 >> v2;
			g[v1].push_back(v2);
			g[v2].push_back(v1);
	}
	for(int i=1 ;i <=v ; i++)
	{
		cout << i << ":";
		for(int j=0 ; j< g[i].size() ; j++)
		cout << g[i][j] << "";

	cout << endl;

	}

}
