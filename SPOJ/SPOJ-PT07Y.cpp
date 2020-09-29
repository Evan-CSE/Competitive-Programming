#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Max 30000
vector<ll>graph[Max];
bool visit[Max]={false};
ll c=0;
bool dfs(ll child, ll parent)
{
    visit[child]=true;
    c++;
    for(ll x:graph[child])
    {
        ll u=child;
        if(!visit[x])
            dfs(x,u);
        else if(visit[x]==true && x!=parent)
            return false;
    }
    return true;
}

int main()
{
    ll n,e;
   cin>>n>>e;
    for(ll i=0;i<e;i++)
    {
        ll x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    if(dfs(1,-1)==true && n==e+1 && c==n)
    puts("YES");
    else
        puts("NO");

    return 0;
}
//Evan
