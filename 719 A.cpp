#include<bits/stdc++.h>
using namespace std;
int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
int t,m,n,i,j,c=0,q=1,l,r,p=0,x=1;
scanf("%d",&n);
int a[n];
for(i=0;i<n;i++)
    scanf("%d",&a[i]);
if(n==1&&(a[0]==0))
{
  cout<<"UP";
  return 0;
}
else if(n==1&&a[0]==15)
{
  cout<<"DOWN";
  return 0;
}
else if(n==1)
{
  printf("-1");
  return 0;
}
else
{
  if((a[n-1]-a[n-2])>0&&(a[n-1]!=15))
    printf("UP");
  else if((a[n-1]-a[n-2])>0&&(a[n-1]==15))
    printf("DOWN");
  else if((a[n-1]-a[n-2])<0&&(a[n-1]!=0))
    printf("DOWN");
  else
    printf("UP");
}
return 0;
}
