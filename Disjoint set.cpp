#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define M (ll)(1e9+7)
ll n;
ll setsize[500011][2];

void intial()
{
     for(ll i=0;i<500011;i++)
    {
        setsize[i][0]=i;
        setsize[i][1]=1;
    }
}
ll root(ll x)
{
    while(setsize[x][0]!=x)
    {   
        setsize[x][0]=setsize[setsize[x][0]][0];

        x=setsize[x][0];
    }
    
    return x;
}
void makeset(ll l,ll r)
{
    l=root(l);
    r=root(r);
    if(l!=r)
      {
        if(setsize[l][1]<setsize[r][1])
        {
            setsize[l][0]=setsize[r][0];
            setsize[r][1]+=setsize[l][1];
        }
        else
        {
            setsize[r][0]=setsize[l][0];
            setsize[l][1]+=setsize[r][1];
        }
      }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
   ll t,i,j,p,q,k,l,r;
   cin>>n>>q;
   intial();
   while(q--)
   {
      cin>>l>>r;
      for(i=0;i<=(r-l+1)/2;i++)
      {
        if((l+i)==r||(r-i)==l)
          break;
        makeset(l+i,r-i);
        // cout<<(l+i)<<" "<<(r-i)<<"\n";
      }
   }
   // for(i=1;i<=n;i++)
   //  ll p=root(i);
   set<ll>st;
   for(i=1;i<=n;i++)
   {
      st.insert(setsize[i][0]);
   }
   cout<<st.size();
return 0;
}
