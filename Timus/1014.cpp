
/**
        Bismilla- hir rahma-nir rahi-m
    @uthor Md Hasibur Rahman (Evan)
                JKKNIU
*/


#include<iostream>
#include<vector>
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




void solve(int n)
{
    if(n==0)
    {
        cout<<"10\n";
        return;
    }
   if(n<=9)
    {
        cout<<n<<endl;
        return;
    }
    vector<int>v;
    for(int i=9;i>=2;i--)
    {
        while(n%i==0)
        {
            n/=i;
            v.pb(i);
        }
    }
    if(n==1)
    {
        for(int i=v.size()-1;i>=0;i--)
            cout<<v[i];
            cout<<endl;
            return;
    }
    else
    {
        cout<<"-1\n";
        return;
    }
}

int main()
{
    int n;
    cin>>n;
    solve(n);
    return 0;
}


