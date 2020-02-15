#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000000
#define FI freopen("input.txt","r",stdin)
#define FO freopen("output.txt","w",stdout)
#define sc(a) scanf("%d",&a);
#define sc2(a,b) scanf("d",&a,&b);
#define fast ios_base::sync_with_stdio(false);cin.tie();cout.tie();

int up_bound(int l, int sz, int value, int a[])
{
    int r = sz-1;
    int ans=-1;
    while(l<=r)
    {
        int mid = (l+r)>>1;
        if(a[mid]<value)
        {
            ans = mid;
            l = mid+1;
        }
        else
        {
            r = mid-1;
        }
    }
    return ans;
}

int main()
{
    FI;
    int test;
    sc(test);
    for(int i=1; i<=test; i++)
    {
        int n;
        sc(n);
        int a[n];
        for(int j = 0; j<n; j++)
            sc(a[j]);
        sort(a,a+n);
        int ans = 0;
        for(int j = 0; j<n-2; j++)
        {
            for(int k = j+1; k<n; k++)
            {
                int sum = a[j]+a[k];
                int cnt = up_bound(k+1,n,sum,a)-k;
                if(cnt>0)
                {
                    cout<<"for   "<<a[j]<<"   "<<a[k]<<"   =  "<<cnt;
                    ans+=cnt;
                }
            }
        }
        printf("Case %d: %d\n",i,ans);
    }
    return 0;
}


