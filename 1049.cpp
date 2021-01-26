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



bool isPrefectSquare(ll value)
{
    return (ll)sqrtl(value)*(ll)sqrtl(value)==value;
}



vector<int>graph[300];
bool Visit[300];
int cost[300][300];


void Reset()
{
	rep(i,300)
	{
		Visit[i]=false;
		graph[i].clear();
		rep(j,300)
			cost[i][j]=0;
	}
}



int bfs()
{
	//start wih left side
	int c1 = 0;
	queue<int>q;
	Visit[1] = true;
	q.push(graph[1][0]);
	c1+=cost[1][graph[1][0]]; 
    int lst;
	while(!q.empty())
	{
		int cur = q.front();
        lst = cur;
		q.pop();
		Visit[cur] = true;
		for(int i=0;i<graph[cur].size();i++)
		{
			int present = graph[cur][i];
			if(Visit[present])
				continue;
			q.push(present);
			c1+=cost[cur][present];
		}
	}
	return c1+cost[lst][1];
}



int main()
{
	int tst;
	cin>>tst;
	rep(t,tst)
	{
		Reset();
		int n,tot=0;
		cin>>n;
		rep(i,n)
		{
			int u,v,c;
			cin>>u>>v>>c;
			graph[u].pb(v);
			graph[v].pb(u);
			cost[v][u] = c;
			tot+=c;
		}
		int ans = bfs();
		cout<<"Case "<<t+1<<": "<<min(ans,tot-ans)<<endl;
	}
    return 0;
}

