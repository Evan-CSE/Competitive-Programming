#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);;cin.tie(NULL);cout.tie(NULL);
using namespace std;
long long a[6000001],test,number;
vector<int>v[600000];
void sieve() /**Generate all number's divisor's sum */
{
    for(int i=1;i<=600000;i++)
{
    for(int j=i;j<=600000;j+=i)
    {
        v[j].push_back(i);
        a[j]+=i;
    }
}

}
int main()
{
   fastio;
   sieve();
   cin>>test;
   while(test--)
   {
       cin>>number;
       cout<<a[number]-number<<endl; /**We'll have to find proper sum ; so, we subtract number from sum . Because our sieve contains all divisors of number */
   }
   return 0;
}
//Evan
