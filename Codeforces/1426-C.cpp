/**
        Bismilla- hir rahma-nir rahi-m
    @uthor Md Hasibur Rahman (Evan)
                JKKNIU
*/


#include<bits/stdc++.h>
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



void Swap(ll &a, ll &b)
{

    a^=b;
    b^=a;
    a^=b;
}



ll gcd(ll a, ll b)
{
    if(a<0 || b<0)
    {
        a = abs(a);
        b = abs(b);
    }
    if(a<b)
        Swap(a,b);
    if(b==0)
        return a;
    if(a%b==0)
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


ll level1,lv2;

void bfs(ll value,ll lv,ll strt )
{
    if(strt==value){
        level1 = min(lv,level1);
        return;
        }
    if(strt>value)
        return;
    else
        {
            bfs(value,lv+1,strt*2);
            bfs(value,lv+1,strt+1);
            return;
        }
}



void bfs2(ll value,ll lv,ll strt )
{
    if(strt==value){
        level1 = min(lv,level1);
        return;
        }
    if(strt>value)
        return;
    else
        {
            bfs(value,lv+1,strt+1);
            bfs(value,lv+1,strt*2);
            return;
        }
}



int main()
{
    //FI;
    //fast;
    int t;
    cin>>t;
    while(t--)
    {
       ll n;
       cin>>n;
       ll ans = 0,tmp=1,cnt = 1,l= 0 ;
       while(tmp<n)
       {
            if(l&1)
            {
                cnt++;
                tmp++;
            }
            else
                tmp+=cnt;
            ans++;
            l++;
            if(tmp>=n)
                break;
       }
       cout<<ans<<endl;
    }
    return 0;
}


