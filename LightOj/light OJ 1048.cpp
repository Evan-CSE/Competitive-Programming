#include<bits/stdc++.h>
using namespace std;
int a[11000],camp,night;


bool Valid(int mid)
{
    int tmp=0,cnt=0;
    for(int i=0;i<=camp;i++)
    {
        if(tmp+a[i]>mid)
        {
            tmp=a[i];
            cnt++;
        }
        else
            tmp+=a[i];
    }
    return cnt<(night+1);
}

int Find(int l,int r)
{
    int mid,ans;
    while(l<=r)
    {
        mid = l+ (r-l)/2;
        if(Valid(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    return ans;
}

int main()
{
    int test,ans;
    scanf("%d",&test);
    for(int i=1;i<=test;i++)
    {
        int tot=0,m=-1;
        scanf("%d%d",&camp,&night);
        for(int j=0;j<=camp;j++)
        {
            scanf("%d",&a[j]);
            tot+=a[j];
            m = max(m,a[j]);
        }
        ans = Find(m,tot);
        printf("Case %d: %d\n",i,ans);
        int tmp=0,cn=0;
        for(int j=0;j<=camp;j++)
        {
            if(tmp+a[j]>ans || camp-j+1<=night-cn)
            {
                printf("%d\n",tmp);
                tmp=a[j];
                cn++;
            }
            else
                tmp+=a[j];
        }
        printf("%d\n",tmp);
    }
    return 0;
}
