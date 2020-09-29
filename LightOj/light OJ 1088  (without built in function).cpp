
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000
#define FI freopen("input.txt","r",stdin)
#define FO freopen("output.txt","w",stdout)
#define fast ios_base::sync_with_stdio(false);cin.tie();cout.tie();


int bnry_src_up(int sz, int bnd, int a[])
{
    int ans=-1;
    int l=0;
    int r=sz-1;
    if(bnd>a[sz-1])
        return ans;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(a[mid]>=bnd)
            {
                ans=mid;
                r=mid-1;
            }
        else
        {
            l=mid+1;
        }
    }
    return ans;
}



int bnry_src_dwn(int sz, int bnd, int a[])
{
    int l=0;
    int r=sz-1,ans=-1;
    if(bnd<a[0])
        return ans;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(a[mid]<=bnd)
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    return ans;
}

int main()
{
    int tst;
    scanf("%d",&tst);
    for(int i=1;i<=tst;i++)
    {
        int n,q;
        scanf("%d%d",&n,&q);
        int a[n];
        for(int j=0;j<n;j++)
            scanf("%d",&a[j]);
            sort(a,a+n);
            printf("Case %d:\n",i);
            for(int k=1;k<=q;k++)
            {
                int l,r;
                scanf("%d%d",&l,&r);
                int a1,a2;
                a1 = bnry_src_dwn(n,r,a);
                a2 = bnry_src_up(n,l,a);
                if(a1==-1 || a2==-1)
                    printf("0\n");
                else
                printf("%d\n",(a1-a2)+1);;
            }
    }
    return 0;
}


