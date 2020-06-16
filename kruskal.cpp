#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
struct edg
{
    lli src;
    lli des;
    lli wt;
};
vector<struct edg> ed;
vector<lli> king;
vector<lli> rankk;

bool cmp(struct edg a, struct edg b)
{
    return a.wt < b.wt;
}

lli check(lli e)
{
    if (king[e] != e)
    {
        king[e] = check(king[e]);
        return king[e];
    }
    else
    {
        return e;
    }
}

lli merge(lli a, lli b)
{
    if (rankk[a] > rankk[b])
    {
        king[b] = king[a];
        rankk[a] += rankk[b];
    }
    else
    {
        rankk[b] += rankk[a];
        king[a] = king[b];
    }
}

int main(void)
{
    lli n, e;
    cin >> n >> e;
    king.resize(n + 1);
    rankk.resize(n + 1);
    for (lli i = 0; i < e; i++)
    {
        struct edg t;
        cin >> t.src >> t.des >> t.wt;
        ed.push_back(t);
    }

    sort(ed.begin(), ed.end(), cmp);
    lli sum = 0;
    for (lli i = 0; i < n; i++)
    {
        rankk[i] = 1;
        king[i] = i;
    }
    // for(lli i=0;i<ed.size();i++){
    // 	cout<<ed[i].src<<" "<<ed[i].des<<" "<<ed[i].wt<<endl;
    // }
    for (lli i = 0; i < ed.size(); i++)
    {
        lli a = check(ed[i].src);
        lli b = check(ed[i].des);
        if (a != b)
        {
            merge(a, b);
            sum += ed[i].wt;
        }
    }

    cout << sum << endl;
    return 0;
}