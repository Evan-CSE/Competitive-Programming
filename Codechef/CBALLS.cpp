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




ll gcd(ll a, ll b)
{
    if(a<0 || b<0)
    {
        a = abs(a);
        b = abs(b);
    }
    if(a<b)
        swap(a,b);
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



int change(vector<int>v,int value)
{
    int l = v.size(),ans = 0;
    for(int i=0;i<l;i++)
    {
        ans+=(v[i]%value);
    }
    return ans;
}



int b_search(vector<int>v,int mx)
{
    int ans = INT_MAX,l = 2, r = mx;
    while(l<=r)
    {
        int mid = (l+r)>>1;
        int cng = change(v,mid);
        if(cng<ans)
        {
            ans = cng;
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
    int t;
    cin>>t;
    while(t--)
    {
        int n,mx = INT_MIN;
        cin>>n;
        vector<int>v;
        rep(i,n)
        {
            int x;
            cin>>x;
            v.pb(x);
            mx = max(mx,x);
        }
        bool srt = false;
        if(is_sorted(v.begin(),v.end()))
        {
            srt = true;
            int g = 0;
            for(int i=0;i<n;i++)
                g = gcd(g,v[i]);
            if(g>1)
            {
                cout<<"0\n";
                continue;
            }
        }
        int cnt = 0;
        if(!srt)
        {
            for(int i=0;i<n-1;i++)
            {
                if(v[i]>v[i+1])
                    v[i+1] = v[i],cnt+=abs(v[i]-v[i+1]);
                mx = max(mx,v[i]);
            }
            int g = 0;
            for(int i=0;i<n;i++)
                g = gcd(g,v[i]);
            if(g>1)
            {
                cout<<cnt<<"\n";
                continue;
            }
        }
        int ans = b_search(v,mx);
        cout<<cnt+ans<<endl;
    }
    return 0;
}
