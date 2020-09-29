#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);;cin.tie(NULL);cout.tie(NULL);
using namespace std;
long n,q,a[100000],range,r2;
int main()
{
   //fastio;
   int t;
   scanf("%d",&t);
   for(int i=1;i<=t;i++)
   {
       scanf("%ld%ld",&n,&q);
       for(long long j=0;j<n;j++)
        scanf("%ld",&a[j]);

        cout<<"Case "<<i<<":\n";
       while(q--)
       {
           scanf("%ld %ld",&range,&r2);

           cout<<upper_bound(a,a+n,r2)-lower_bound(a,a+n,range)<<"\n";
       }
       //memset(a,0,sizeof(a));
   }
   return 0;
}
