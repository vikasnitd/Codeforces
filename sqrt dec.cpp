#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007;
ll blocknum[100011];
ll ans[1000];
ll chek=0;
ll a[100011];
ll getans(ll x,ll y)
{
    ll ans=0;
    ll temp=1;
    if(chek)
    {
        for(ll i=x;i<=y;i++)
        {
            if(a[i]==0)
            {
                x=i;
                chek=0;
                break;
            }
        }
    }
    for(ll i=x;i<=y;i++)
    {
        if(a[i]==1&&temp)
        {
            ans++;
            temp=0;
        }
        else if(a[i]==0)
            temp=1;
    }
    return ans;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,i,j,l,m,n,r,q,k,x;
    
        cin>>n>>q;
        ll c;
        // ll a[n+11];
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        ll blocksize=sqrt(n);
        j=1;
        for(i=1;i<=n;i++)
        {
            if(i%blocksize==0)
            {
                blocknum[i]=j;
                j++;
            }
            else
            {
                blocknum[i]=j;
            }
        }
        j=1;
        for(i=1;i<=n;i++)
        {
            // if(i)
            if(i%blocksize==0)
            {
                c=getans(j,i);
                j=i+1;
                if(a[i]==1)
                {
                    if((i+1)<=n)
                    {
                        if(a[i+1]==1)
                        {
                            chek=1;
                            ans[blocknum[i]]=c;
                            c=0;
                        }
                        else
                        {
                            chek=0;
                            ans[blocknum[i]]=c;
                            c=0;
                        }
                    }
                    else
                    {
                        ans[blocknum[i]]=c;
                            c=0;
                    }
                }
                else
                {
                    ans[blocknum[i]]=c;
                    c=0;
                }
            }
        }
        // for(i=1;i<=n;i++)
        // {
        //     cout<<ans[blocknum[i]]<<" ";
        // }
        if(n%blocksize)
        {
            j=((n/blocksize)*blocksize)+1;
            c=getans(j,n);
            ans[blocknum[j]]=c;
        }
        chek=0;
        while(q--)
        {
            cin>>l;
            if(l==1)
            {
                cin>>l;
                chek=0;
                a[l]=!a[l];
                i=blocknum[l];
                i=(i-1)*blocksize;
                i++;
                j=blocknum[l]*blocksize;
                if(l==1)
                {
                    ans[blocknum[l]]=getans(i,j);
                    if(a[l]==1)
                    {
                        if((l+1)<=n)
                        {
                            if(a[l+1]==1)
                            {
                                ans[blocknum[l+1]]--;
                            }
                        }
                    }
                    else
                    {
                        if((l+1)<=n)
                        {
                            if(a[l+1]==1)
                            {
                                ans[blocknum[l+1]]++;
                            }
                        }
                    }
                }
                else
                {
                    if(a[i-1]==1)
                    {
                        for(x=i;x<=j;x++)
                        {
                            if(a[x]==0)
                            {
                                i=x;
                                break;
                            }
                        }
                        if(i>j)
                        {
                            if(j==l)
                            {
                                if(blocknum[l]!=1)
                                    ans[blocknum[l]]=0;
                                else
                                    ans[blocknum[l]]=1;
                                if(a[l]==1)
                                {
                                    if((l+1)<=n)
                                    {
                                        if(a[l+1]==1)
                                        {
                                            ans[blocknum[l+1]]--;
                                        }
                                    }
                                }
                                else
                                {
                                    if((l+1)<=n)
                                    {
                                        if(a[l+1]==1)
                                        {
                                            ans[blocknum[l+1]]++;
                                        }
                                    }
                                }
                            }
                            else
                            {
                                if(blocknum[l]!=1)
                                    ans[blocknum[l]]=0;
                                else
                                    ans[blocknum[l]]=1;
                            }
                        }
                        else
                        {
                            ans[blocknum[l]]=getans(i,j);
                            if(j==l)
                            {
                                if(a[l]==1)
                                {
                                    if((l+1)<=n)
                                    {
                                        if(a[l+1]==1)
                                        {
                                            ans[blocknum[l+1]]--;
                                        }
                                    }
                                }
                                else
                                {
                                    if((l+1)<=n)
                                    {
                                        if(a[l+1]==1)
                                        {
                                            ans[blocknum[l+1]]++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        if(l==j)
                        {
                            ans[blocknum[l]]=getans(i,j);
                        if(a[l]==1)
                        {
                            if((l+1)<=n)
                            {
                                if(a[l+1]==1)
                                {
                                    ans[blocknum[l+1]]--;
                                }
                            }
                        }
                        else
                        {
                            if((l+1)<=n)
                            {
                                if(a[l+1]==1)
                                {
                                    ans[blocknum[l+1]]++;
                                }
                            }
                        }
                        }
                        else
                        {
                            ans[blocknum[l]]=getans(i,j);
                        }
                    }
                }
                // if(j==l)
                // {
                //     ans[blocknum[l]]=getans(i,j);
                //     if(a[l]==1)
                //     {
                //         if((l+1)<=n)
                //         {
                //             if(a[l+1]==1)
                //             {
                //                 ans[blocknum[l+1]]--;
                //             }
                //         }
                //     }
                //     else
                //     {
                //         if((l+1)<=n)
                //         {
                //             if(a[l+1]==1)
                //             {
                //                 ans[blocknum[l+1]]++;
                //             }
                //         }
                //     }
                // }
                // else
                // {
                //     ans[blocknum[l]]=getans(i,j);
                // }
            }
            else
            {
                cin>>l>>r;
                ll x=blocknum[l];
                ll y=blocknum[r];
                if((y-x)<=0)
                {
                    chek=0;
                    cout<<getans(l,r)<<"\n";
                }
                else
                {
                    ll ans1=0;
                    chek=0;
                    c=getans(l,blocknum[l]*blocksize);
                    ans1=c;
                    // cout<<c<<" ";
                    // cout<<blocknum[l]<<" ";
                    for(i=blocknum[l]+1;i<blocknum[r];i++)
                    {
                        // cout<<i<<" "<<ans[i]<<" ";
                        ans1=ans1+ans[i];
                    }
                    i=(blocknum[r]-1)*blocksize;
                    if(a[i]==1)
                    {
                        // cout<<"asdbj";
                        for(;i<=r;i++)
                        {
                            if(a[i]==0)
                            {
                                break;
                            }
                        }
                        // cout<<i<<" ";
                        if(i<=r)
                        {
                            ans1=ans1+getans(i,r);
                        }
                    }
                    else
                    {
                        // cout<<getans((blocknum[r]-1)*blocksize+1,r)<<" ";
                        ans1=ans1+getans((blocknum[r]-1)*blocksize+1,r);
                    }
                    cout<<ans1<<"\n";
                }
            }
        }
return 0;
}
