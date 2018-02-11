#include<bits/stdc++.h>
using namespace std;
#define ll long long int  
#define mod 1000000007
ll seg[600011];
ll input[100011];
ll lazy[600011];
ll n;
void segtree(ll low,ll high,ll pos)
{
    if(low>high)
        return ;
     if(low==high)
     {
        seg[pos]=input[low];
        return ;
     }
     ll mid=(low+high)/2;
     segtree(low,mid,2*pos+1);
     segtree(mid+1,high,2*pos+2);
     seg[pos]=(seg[2*pos+1]+seg[2*pos+2]);
}
void update(ll star,ll en,ll low,ll high,ll pos,ll val)
{
    if(low>high)
        return;
    if(lazy[pos]!=0)
    {
        seg[pos]+=lazy[pos];
        if(low!=high)
        {
            lazy[2*pos+1]+=lazy[pos];
            lazy[2*pos+2]+=lazy[pos];
        }
        lazy[pos]=0;
    }
    if(low>en||high<star)
        return ;
    if(low>=star&&high<=en)
    {
        seg[pos]+=val;
        if(low!=high)
        {
          lazy[2*pos+1]+=val;
          lazy[2*pos+2]+=val;
        }
        return ;
    }
    ll mid=(low+high)/2;
    update(star,en,low,mid,2*pos+1,val);
    update(star,en,mid+1,high,2*pos+2,val);
    seg[pos]=(seg[2*pos+1]+seg[2*pos+2]);
}
ll maxq(ll qlow,ll qhigh,ll low,ll high,ll pos)
{
    if(low>high)
            return 0;
    if(lazy[pos]!=0)
    {
        seg[pos]+=lazy[pos];
        if(low!=high)
        {
            lazy[2*pos+1]+=lazy[pos];
            lazy[2*pos+2]+=lazy[pos];
        }
        lazy[pos]=0;
    }
    if(qlow>high||qhigh<low)
        return 0;
    if(low>=qlow&&high<=qhigh)
        return seg[pos];
    ll mid=(low+high)/2;
    return (maxq(qlow,qhigh,low,mid,2*pos+1)+maxq(qlow,qhigh,mid+1,high,2*pos+2));
}
ll bin(ll s)
{
    ll low=0;
    ll high=n-1;
    while(low<=high)
    {
        ll mid=(low+high)/2;
        ll p=maxq(mid,mid,0,n-1,0);
        if(p==s)
        {
            return 1;
        }
        else if(p<s)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return 0;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,i,j,l,m;
    cin>>n;
    ll a[n+11];
    ll sum=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        input[i]=sum;
    }
    segtree(0,n-1,0);
    if(sum%2)
    {
        cout<<"NO\n";
        return 0;
    }
    else
    {
        sum=sum/2;
        if(bin(sum))
        {
            cout<<"YES\n";
            return 0;
        }
        else
        {
            for(i=0;i<n;i++)
            {
                update(i,n-1,0,n-1,0,-a[i]);
                if(bin(sum))
                {
                    cout<<"YES\n";
                    return 0;
                }
                update(i,n-1,0,n-1,0,a[i]);
            }
        }
        reverse(a,a+n);
        for(i=0;i<n;i++)
        {
            if(i>0)
            {
                input[i]=input[i-1]+a[i];
            }
            else
            {
                input[i]=a[i];
            }
        }
        for(i=0;i<=500000;i++)
        {
            seg[i]=lazy[i]=0;
        }
        segtree(0,n-1,0);
        if(bin(sum))
        {
            cout<<"YES\n";
            return 0;
        }
        else
        {
            for(i=0;i<n;i++)
            {
                update(i,n-1,0,n-1,0,-a[i]);
                if(bin(sum))
                {
                    cout<<"YES\n";
                    return 0;
                }
                update(i,n-1,0,n-1,0,a[i]);
            }
        }
        cout<<"NO\n";
    }
return 0;
}
