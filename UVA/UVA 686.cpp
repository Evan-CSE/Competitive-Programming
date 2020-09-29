#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);;cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define MAX 10000000
bool isComp[MAX];
int prime[MAX];
using namespace std;
void sieve()
{
    for(int i=2;i*i<=MAX;i++)
    {
        if(!isComp[i])
        {
            for(int j=i*i;j<=MAX;j+=i)
                isComp[j]=true;
        }
    }
    int index=0;
    for(auto i=2;i<=MAX;i++)
        if(!isComp[i])
        prime[index++]=i;
}
int main()
{
   fastio;
   sieve();
   ll a;
   while(cin>>a)
   {
       if(a==0)
        break;
       if(a==4)
        cout<<"1"<<endl;
       else
       {
           int cnt=0;
           for(int i=1;prime[i]<=a/2;i++)
           {
               if(!isComp[a-prime[i]])
                cnt++;
           }
           cout<<cnt<<endl;
       }
   }
   return 0;
}
