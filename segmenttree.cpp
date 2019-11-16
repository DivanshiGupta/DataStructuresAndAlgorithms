#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define rt return 0
#define endln "\n"
#define for1(i,a,b) for(long long int i=a;i<b;i++)
#define for2(i,a,b) for(long long int i=a;i>b;i--)
//  cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;
typedef long long int int1;
vector<int1>v;
int seg[400005];
int build(int pos,int low,int high)
{
	if(low>high)
	{
		return 0;
	}
	else if(low == high)
	{
		if(v[low]%2 == 0)
			seg[pos] = 1;
		else
			seg[pos]=0;
		return 0;
		
	}
	else
	{
		int mid = (low+high)/2;
		build(2*pos,low,mid);
		build(2*pos+1,mid+1,high);
		seg[pos] = (seg[2*pos] + seg[2*pos+1]) ;
		return 0;
	}
	return 0;
}

// }
int update(int pos , int low , int high,int x ,int y)
{
	// cout << pos << endl;
	if(low > x || high < x)
	{
		return 0;
	}
	else if( low == high)
	{
		if(y%2 == 0)
		{
			seg[pos]=1;
		}
		else
			seg[pos]=0;
	}
	else
	{
		int mid = (low+high)/2;
		if(mid >= x)
		{
			update(2*pos,low,mid,x,y);
			seg[pos] = seg[2*pos] + seg[2*pos+1];
		}
		else
		{
			update(2*pos+1,mid+1,high,x,y);
			seg[pos] = seg[2*pos] + seg[2*pos+1];

		}
	}
	return 0;
}
int query(int pos,int low,int high,int l,int h)
{
	// cout << pos << endl;

	if(l>high || h<low)
	{
		return 0;
	}
	else if(l <=low && h>=high)
	{
		return seg[pos];
	}
	else
	{
		int k=0,p=0;
		int mid =(low+high)/2;
		if( mid >=l)
		{
			k = query(2*pos,low,mid,l,h);
		}
		if(h>=mid+1 )
		{
			p = query(2*pos+1,mid+1,high,l,h);
		}
		// cout << k<<p<<endl;
		int a = (k+p);
		return a;
	}
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int1 x,y,n,k,m,a,b;
    scanf("%lld",&n);
    v.pb(0);
    for1(i,0,n)
    {
    	scanf("%lld",&k);
    	v.pb(k);
    }
    build(1,1,n);
    // cin >> m;
    scanf("%lld",&m);

    for1(i,0,m)
    {
    	// cin>>a>>x>>y;
    	scanf("%lld %lld %lld",&a,&x,&y);
    	if(a==0)
    	{
    		update(1,1,n,x,y);
    	}
    	else 
    	{
    		int1 p = query(1,1,n,x,y);
    		if(a==1)
    			printf("%lld\n",p);
    		else
    			printf("%lld\n",y-x+1-p);
    	}
    }
   
}

