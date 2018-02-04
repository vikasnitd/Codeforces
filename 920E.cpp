#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
map<pair<ll,ll>,ll> mp;
deque<ll>dq;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,i,j,l,r,k,x,c,n,m;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>l>>r;
        mp[make_pair(l,r)]++;
        mp[make_pair(r,l)]++;
    }
    ll ans[n+1];
    k=0;
    for(i=1;i<=n;i++)
    {
        dq.push_front(i);
    }
    ll sz=0;
    while(!dq.empty())
    {
        sz++;
        ll p=dq.front();
        dq.pop_front();
        queue<ll>q;
        q.push(p);
        while(!q.empty())
        {
            ll x=dq.size();
            p=q.front();
            q.pop();
            
            while(x--)
            {
                ll xx=dq.front();
                dq.pop_front();
                if(mp[make_pair(p,xx)])
                {
                    dq.push_back(xx);
                }
                else
                {
                    // dq.push_back(xx);
                    q.push(xx);
                    sz++;
                }
            }
        }
        ans[k++]=sz;
        sz=0;
    }
    cout<<k<<"\n";
    sort(ans,ans+k);
    for(i=0;i<k;i++)
    {
        cout<<ans[i]<<" ";
    }
return 0;
}
