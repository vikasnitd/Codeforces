#include<bits/stdc++.h>
using namespace std;
#define ll long long int  
#define mod 1000000000
#define mkp make_pair
#define pb push_back

ll modexpo(ll x,ll y){if(y==0)return 1;if(y%2){ll viky=modexpo(x,y/2);
return (((x*viky)%mod)*viky)%mod;}else{ll viky=modexpo(x,y/2);return (viky*viky)%mod;
}}

vector<ll>segtree[1000011];
ll input[200011];
void seg_form(ll low,ll high,ll pos)
{
    if(low>high){
        return ;
    }
    if(low==high){
        segtree[pos].pb(input[low]);
        return ;
    }
    ll mid = (low+high)>>1;
    seg_form(low,mid,2*pos+1);
    seg_form(mid+1,high,2*pos+2);
    ll l = segtree[2*pos+1].size();
    ll r = segtree[2*pos+2].size();
    ll i=0,j=0;
    while(l&&r)
    {
        if(segtree[2*pos+1][i]>=segtree[2*pos+2][j]){
            segtree[pos].pb(segtree[2*pos+2][j]);
            j++;
            r--;
        }
        else{
            segtree[pos].pb(segtree[2*pos+1][i]);
            i++;
            l--;
        }
    }
    while(l){
        segtree[pos].pb(segtree[2*pos+1][i]);
        i++;
        l--;
    }
    while(r){
        segtree[pos].pb(segtree[2*pos+2][j]);
        j++;
        r--;
    }
}

ll getans(ll qlow, ll qhigh, ll low, ll high ,ll pos,ll value){
    if(low>high){
        return 0;
    }
    if(qhigh<low||qlow>high){
        return 0;
    }
    if(qlow<=low&&qhigh>=high){
        return segtree[pos].size() - (lower_bound(segtree[pos].begin(),segtree[pos].end(),value) - segtree[pos].begin());
    }
    ll mid = (low+high)>>1;
    return getans(qlow,qhigh,low,mid,2*pos+1,value) + getans(qlow,qhigh,mid+1,high,2*pos+2,value);
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,i,j,l,m,n,r,q,x,k;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>input[i];
    }
    seg_form(0,n-1,0);
    ll ans=0;
    for(i=0;i<n;i++){
        ans = ans + getans(i+1,input[i]-1,0,n-1,0,i+1);
    }
    cout<<ans;
return 0;
}
