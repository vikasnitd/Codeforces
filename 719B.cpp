#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll i,j,k,l,n,m;
    cin>>n;
    string s;
    cin>>s;
    k=0;
    l=0;
    ll r=0;
    ll b=0;
    for(i=0;i<n;i++)
    {
      if(i%2)
      {
        if(s[i]=='r')
        {
          k++;
          r++;
        }
      }
      else
      {
        if(s[i]=='b')
        {
          b++;
          k++;
        }
      }
    }
    if(r>b)
    {
      k=k-b;
    }
    else
    {
      k=k-r;
    }
    r=0;
    b=0;
    for(i=0;i<n;i++)
    {
      if(i%2)
      {
        if(s[i]=='b')
        {
          l++;
          b++;
        }
      }
      else
      {
        if(s[i]=='r')
        {
          l++;
          r++;
        }
      }
    }
    if(r>b)
    {
      l=l-b;
    }
    else
    {
      l=l-r;
    }
    cout<<min(l,k);
  return 0;
}
