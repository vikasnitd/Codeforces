#include<bits/stdc++.h>
using namespace std;
#define ll int
vector<ll>v[1000011];
ll intime[1000011],outtime[1000011];
ll up[1000011][25];
ll tim,depth;
ll dp[1000001];
void dfs( ll s,ll p)
{
	intime[s] = ++tim;
	dp[s] = dp[p] +1 ;
	up[s][0] = p;
	for(ll i=1;i<=depth;i++)
	{
		up[s][i] = up[up[s][i-1]][i-1];
	}
	for(ll i=0;i<v[s].size();i++)
	{
		if(v[s][i]!=p)
		{
			dfs(v[s][i],s);
		}
	}
	outtime[s] = ++tim;
}
bool check(ll a,ll b)
{
	return (intime[a]<=intime[b]&&outtime[a]>=outtime[b]);
}
ll lca(ll a,ll b)
{
	if(check(a,b))
		return a;
	if(check(b,a))
		return b;
	for(ll i=depth;i>=0;i--)
	{
		if(!check(up[a][i],b))
			a = up[a][i];
	}
	return up[a][0];
}

int main()
{
	#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  ll t,i,j,k,l,r,n,m,q,c,x,y;
  scanf("%d%d",&n,&k);
  for(i=1;i<n;i++)
  {
  	scanf("%d%d",&l,&r);
  	v[l].push_back(r);
  	v[r].push_back(l);
  }
  ll p=1;
  depth = 1;
  while(p<=n)
  {
  	p=p*2;
  	depth++;
  }
  dfs(n,0);
  
  return 0;
}
