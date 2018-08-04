#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>v[1000011];
ll intime[1000011],outtime[1000011];
ll up[1000011][25];
ll tim,depth;
pair<ll,ll>pp[200011];
ll dist[1000001];
void dfs( ll s,ll p)
{
	intime[s] = ++tim;
	dist[s] = dist[p] + 1 ;
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
		// cout<<up[a][i]<<" ";
		if(!check(up[a][i],b)){
			// cout<<up[a][i]<<" ";
			a = up[a][i];
		}
	}
	return up[a][0];
}

int main()
{
	#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t,i,j,k,l,r,n,m,q,c,x,y;
  cin>>n>>k;
  
  for(i=0;i<(2*k);i++){
  	cin>>pp[i].second;
  }
  for(i=1;i<n;i++)
  {
  	cin>>l>>r;
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
  dfs(1,0);
  outtime[0] = ++tim;
  for(i=0;i<(2*k);i++){
  	pp[i].first = intime[pp[i].second];
  }
  sort(pp,pp+2*k);
  ll ans=0;
  for(i=0;i<k;i++){
  	ll a = pp[i].second;
  	ll b = pp[i+k].second;
  	ans = ans + dist[a] + dist[b] - 2*dist[lca(a,b)];
  }
  cout<<ans;
  // for(i=1;i<=n;i++){
  // 	cout<<dist[i]<<" ";
  // }
  
  return 0;
}
