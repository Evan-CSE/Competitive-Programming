#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);;cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define MAX 20000000
bool isComp[MAX];
int prime[MAX];
int p2[MAX];
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
        index=0;
        for(ll i=0;i<=MAX;i++)
        {
            if(prime[i+1]-prime[i]==2)
            {
               p2[index++]=prime[i];
            }

        }

}
int main()
{
   fastio;
   sieve();
   ll a,in;
   while(cin>>in)
   {
       cout<<"("<<p2[in-1]<<", "<<p2[in-1]+2<<")"<<endl;
   }
   return 0;
}
