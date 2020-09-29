/**
        Bismilla- hir rahma-nir rahi-m
    @uthor Md Hasibur Rahman (Evan)
                JKKNIU
*/


/**Verdict AC */

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
#define         fast            ios_base::sync_with_stdio(false);cin.tie(NULL),cout.tie(NULL);



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



char isLand[100][100];
bool visit[100][100];
int cnt = 0;




void dfs(int r, int c,int mxR , int mxC)
{
    if(visit[r][c] || r<0 || r>mxR|| c<0 || c>mxC || isLand[r][c]=='#' || isLand[r][c]=='0')
        return;
    visit[r][c] = true;
    cnt++;
    dfs(r,c+1,mxR,mxC);
    dfs(r-1,c,mxR,mxC);
    dfs(r,c-1,mxR,mxC);
    dfs(r+1,c,mxR,mxC);

    return;
}


int main()
{
    fast;
    int test;
    cin>>test;
    for(int t=1;t<=test;t++)
    {
        int c,r;
        cin>>c>>r;
        memset(visit,false,sizeof visit);
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cin>>isLand[i][j];
            }
        }
        cnt = 0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(isLand[i][j]=='@')
                {
                    dfs(i,j,r-1,c-1);
                }
            }
        }
        cout<<"Case "<<t<<": ";
        cout<<cnt<<"\n";
    }
    return 0;
}


