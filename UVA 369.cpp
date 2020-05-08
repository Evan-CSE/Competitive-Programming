#include<bits/stdc++.h>
using namespace std;
#define     ll              long long
#define     MAX             100000
#define     FI              freopen("input.txt","r",stdin)
#define     FO              freopen("output.txt","w",stdout)
#define     fast            ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define     sc(a)           scanf("%d",&a)
#define     sc2(a,b)        scanf("%d %d",&a,&b)
int arr[200][200];

int nCr(int n, int r)
{
    if(r==1)
        return n;
    if(n==r)
        return 1;
        if(arr[n][r])
            return arr[n][r];
    else
        return arr[n][r]=nCr(n-1,r-1) + nCr(n-1,r);
}


int main()
{
    int n,r;
    while(cin>>n>>r && n&&r)
    {
        printf("%d things taken %d at a time is %d exactly.\n",n,r,nCr(n,r));
    }
    return 0;
}

