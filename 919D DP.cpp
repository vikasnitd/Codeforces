#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
vector<ll>v[500001],v2[500011];
ll ap[500011];
ll DP[500011][27];
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
    string s;
    cin>>s;
    for(i=0;i<m;i++)
    {
        cin>>l>>r;
        v[l].push_back(r);
        v2[r].push_back(l);
        ap[r]++;
    }
    queue<ll>q;
    for(i=1;i<=n;i++)
    {
        if(!v2[i].size())
        {
            DP[i][s[i-1]-'a']=1;
            q.push(i);
        }
    }
    ll cnt=0;
    while(!q.empty())
    {
        ll p=q.front();
        q.pop();
        cnt++;
        for(i=0;i<v[p].size();i++)
        {
            ll pp=v[p][i];
            for(j=0;j<26;j++)
            {
                if(j==(s[pp-1]-'a'))
                    DP[pp][j]=max(DP[pp][j],DP[p][j]+1);
                else
                    DP[pp][j]=max(DP[pp][j],DP[p][j]);
            }
            ap[pp]--;
            if(!ap[pp])
            {
                q.push(pp);
            }
        }
    }
    // cout<<cnt<<" ";
    if(cnt!=n)
    {
        cout<<"-1\n";
        return 0;
    }
    ll ans=-1;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<26;j++)
        {
            ans=max(ans,DP[i][j]);
        }
    }
    cout<<ans;
return 0;
}
