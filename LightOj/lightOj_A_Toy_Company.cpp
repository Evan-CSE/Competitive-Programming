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



set<string>forbidden;
map<string,bool>visit;




int bfs(string &start , string &end)
{
	queue<pair<string,int>>q;
	q.push({start,0});
	while(!q.empty())
	{
		pair<string,int>u = q.front();
		q.pop();
		if(forbidden.find(u.first)!=forbidden.end() || visit[u.first])
			continue;
		visit[u.first] = true;
		for(int i=0;i<3;i++)
		{
			string tmp = u.first;
			tmp[i]++;
			if(tmp[i]>'z')
				tmp[i] = 'a';
			if(tmp==end && forbidden.find(tmp)==forbidden.end())
				return u.second+1;
			q.push({tmp,u.second+1});
			tmp = u.first;
			tmp[i]--;
			if(tmp[i]<'a')
				tmp[i] = 'z';
			if(tmp==end && forbidden.find(tmp)==forbidden.end())
				return u.second+1;
			q.push({tmp,u.second+1});
		}
	}
	return -1;
}




int main()
{
	int tst;
	cin>>tst;
	for(int t=1;t<=tst;t++)
	{
		forbidden.clear();
        visit.clear();
		string start,end;
		cin>>start>>end;
		int q;
		cin>>q;
		bool f = false;
		while(q--)
		{
			string s1,s2,s3;
			cin>>s1>>s2>>s3;
			int l1 = s1.size(),l2  = s2.size(), l3 = s3.size();
			
			for(int i=0;i<l1;i++) //Seperate forbideen strings
			{
				for(int j=0;j<l2;j++)
				{
					for(int k=0;k<l3;k++)
					{
						string tmp="";
						tmp+=s1[i];
						tmp+=s2[j];
						tmp+=s3[k];
						forbidden.insert(tmp);
						if(tmp==end)f = true;
					}
				}
			}
		}
		cout<<"Case "<<t<<": ";
		if(f)
		{
			cout<<"-1\n";
			continue;
		}
		if(start==end)
		{
			cout<<"0\n";
			continue;
		}
		else
		{
			cout<<bfs(start,end)<<endl;
		}
	}
    return 0;
}


