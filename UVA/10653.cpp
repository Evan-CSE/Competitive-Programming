
/**
        Bismilla- hir rahma-nir rahi-m
    @uthor Md Hasibur Rahman (Evan)
                JKKNIU
*/



/**
	Here we will have to check with how many minimum steps we can reach to our destination where we are allowed to move
	Up, Down , Left , Right. 
	So we need to find minimum shrtest path. If we observe carefully as BFS ensures us (may be not always) about shortest path so this
	algorithm can help us. So the question is how can we  apply bfs? Pretty simple. As like 1d array we'll run bfs
	on 2d array as we are moving on a 2d plane. We'll explore each neighbouring valid grids.Then put the level of new
	grid to level[parent] + 1 ... and thus after running whole bfs we can simply print our answer like
	 level[end] - level[start]...How can we guarantee that each time we'll get minimum steps required for a specific
	 grid? Simple.... Take pen and paper and observe that each time we are approaching with new grid with same 
	 quantity maintaining same level..... It ensures us that we are not missing minimum steps ..... 
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





int grid[5000][5000];
int R,C,t=0;
int dx[] = {-1,0,1,0},dy[] = {0,1,0,-1};
int level[5000][5000];





bool valid(int r, int c) //Checks valid move
{
	return (r<R && c<C && grid[r][c]!=1 && r>=0 && c>=0);
}









void bfs(int x, int y, int x2 , int y2) //Exploring all possible paths
{
	if(x==x2 && y==y2)
		return;
	queue<pair<int,int>>q;
	q.push({x,y});
	level[x][y] = 1;
	while(!q.empty()){
		int cr,cc;
		cr = q.front().first;
		cc = q.front().second;
		q.pop();
	for(int i=0;i<4;i++)
	{
		if(valid(cr+dx[i],cc+dy[i]) && level[cr+dx[i]][cc+dy[i]]==0)
			{
				level[cr+dx[i]][cc+dy[i]] = level[cr][cc] + 1;
				q.push({cr+dx[i],cc+dy[i]});
			}
	}

	}		
}




int main()
{
    int r,c;
    while(cin>>R>>C)
    {
    	if(R==C && R==0)
    		break;
    	for(int i=0;i<R;i++)
    		for(int j=0;j<C;j++)grid[i][j] = 0,level[i][j] = 0;
    	int bomb;
    	cin>>bomb;
    	while(bomb--)
    	{
    		int cur_bomb;
    		cin>>r>>cur_bomb;
    		while(cur_bomb--)
    		{
    			cin>>c;
    			grid[r][c] = 1;
    		}
    	}
    	int strtX,strtY,enX,enY;
    	cin>>strtX>>strtY>>enX>>enY;


    	//End of input sections! So much boring stuff!!!!
    	

    	bfs(strtX,strtY,enX,enY);
    	cout<< level[enX][enY]- level[strtX][strtY]<<endl;
    }
    return 0;
}
