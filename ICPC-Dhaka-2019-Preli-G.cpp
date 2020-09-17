/**
        Bismilla- hir rahma-nir rahi-m
    @uthor Md Hasibur Rahman (Evan)
                JKKNIU
*/


#include<iostream>
#define         ll              long long
#define         FI              freopen("input.txt","r",stdin)
#define         FO              freopen("output.txt","w",stdout)
#define         PrintCase(i)    printf("Case %d: ",i)
#define         sc(a)           scanf("%d",&a)
#define         scl(a)          scanf("%lld",&a)
#define         rep(i,n)        for(int i=0;i<n;i++)
#define         pb              push_back
#define         MAX             1000000
#define         fast            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define         endl            "\n"


using namespace std;

bool isPrime(ll a)
{
    for(ll i=2;i*i<=a;i++)
        if(a%i==0)
            return false;
    return true;
}






bool isPowerOfTwo(ll a)
{
    if(a==1)
        return true;
    if(a&1)
        return false;
    while(a)
    {
        a/=2;
        if(a!=1 && a&1)
            return false;
        if(a==1)
            return true;
    }
    return true;
}




ll gcd(ll a, ll b)
{
    if(a<0 || b<0)
    {
        a = abs(a);
        b = abs(b);
    }
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



ll power(ll base, ll exponent)
{
    ll ans = 1;
    for(ll i=1;i<=exponent;i++)
        ans*=base;
    return ans;
}




bool isPowerOfX(ll x, ll value)
{
    if(value==1)
        return true;
    while(value)
    {
        value/=x;
        if(value%x && value!=1)
            return false;
    }
    return true;
}




ll sqrt(ll x)
{
	ll i = 1;
	while (i*i <= x)
		i++;

	return i - 1;
}


ll SUM[11111111];
 ll el[11111111];
 bool visit[11111111];


 void preCal()
 {
	 for(ll i=0;i<11111111;i++)
		el[i] = i;
	for(ll i=2;i<11111111;i++)
		{
			if(!visit[i])
			{
				for(ll j = i;j<11111111;j+=i)
				{
					visit[j] = true;
					el[j] = el[j]/i*(i-1);
				}
			}
		}
		for(int i=1;i<11111111;i++)
		{
			SUM[i]+=SUM[i-1] + el[i] - 1;
		}
}



 ll b_search(ll n, ll p)
 {
	 ll l = 1,r  = n,mid,ans = -1;
	 while(l<=r)
	 {
		 mid = l + ((r-l)/2);
		 if(SUM[n/mid] + (n/mid)>=p)
		 {
			 ans = mid;
			 l = mid+1;
		 }
		 else
			r = mid-1;
	 }
	 return ans;
}

int main()
{
	fast;
	preCal();
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
		ll n,p;
		cin>>n>>p;
		ll ans = b_search(n,p);
		cout<<"Case "<<i<<": "<<ans <<endl;
	}
    return 0;
}


