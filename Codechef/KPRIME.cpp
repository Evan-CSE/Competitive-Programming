/**Bismilla- hir  rahma-nir rahi-m


@uthor   Md Hasibur Rahman (Evan)
                JKKNIU
*/


#include<bits/stdc++.h>


#define         MAX                 100010
#define         sc(a)               scanf("%d",&a)
#define         sc2(a,b)            scanf("%d %d",a&a,&b)
#define         PritCase(i,value)   printf("Case %d: %d\n",i,value)
#define         ll                  long long
#define			pb					push_back


using namespace std;



ll gcd(ll a, ll b)
{
    if(a<b)
        swap(a,b);
    if(a%b==0 || b==0)
        return b;
    else
        return gcd(b,a%b);
}



ll lcm(ll a, ll b)
{
    return (a*b)/gcd(a,b);
}



bool isPrime(ll value)
{
    if(value==2)
        return true;
    for(ll i=2;i*i<=value;i++)
        if(value%i==0)
            return false;
    return true;
}



bool isPowerof2(ll value)
{
    if(value==2 || value==1)
        return true;
    while(value)
    {
        value/=2;
    }
    if(value==1)
    return true;
    return false;
}


bool comp[MAX];
vector<ll>prime;
ll counter[MAX],KDiv[MAX][6];


void sieve()
{
	for(int i=2;i*i<MAX;i++)
		if(!comp[i])
			for(int j=i*i;j<MAX;j+=i)
				comp[j] = true;
				
	for(int i=2;i<MAX;i++)
		if(!comp[i])
			prime.pb(i);
	int l = prime.size();
	for(int i=0;i<l;i++)
	{
		for(int j = prime[i];j<MAX;j+=prime[i])
		{
			counter[j]++;
		}
	}
	
	/**Store number of k Primes for specific integer*/
	ll arr[7];
	memset(arr,0,sizeof arr);
	for(int i=2;i<MAX;i++)
	{
		//counter[i];
		arr[counter[i]]++;
		for(int j=1;j<6;j++)
			KDiv[i][j] = arr[j];
	}
	
}



int main()
{
    sieve();
    int t;
    cin>>t;
    while(t--)
    {
    	int a,b,k;
    	cin>>a>>b>>k;
    	int  ans = KDiv[b][k] - KDiv[a][k];
    	//cout<<KDiv[b]<<" "<<KDiv[a]<<".......\n";
    	if(counter[a]==k)
    	ans++;
    	cout<<ans<<endl;
	}
    return 0;
}
