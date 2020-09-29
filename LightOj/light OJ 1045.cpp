#include<bits/stdc++.h>
using namespace std;
#define     ll              long long
#define     MAX             1000010
#define     FI              freopen("input.txt","r",stdin)
#define     FO              freopen("output.txt","w",stdout)
#define     fast            ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define     sc(a)           scanf("%d",&a)
#define     sc2(a,b)        scanf("%d %d",&a,&b)

double Log[MAX];


void digit_cnt()
{
    Log[0] = 0;
    for(int i=1;i<MAX;i++)
    {
        Log[i] = Log[i-1] + log(i);
    }

}


int main()
{
    digit_cnt();
    int test;
    scanf("%d",&test);
    for(int i=1;i<=test;i++)
    {
        ll n,base;
        scanf("%lld %lld",&n,&base);
        ll r = (Log[n]/log(base)) + 1;
        printf("Case %d: %lld\n",i,r);
    }
    return 0;
}
/**Md Hasibur Rahman (Evan) */
