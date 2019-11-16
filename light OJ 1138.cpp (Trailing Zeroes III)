#include<iostream>
#include<cmath>
using namespace std;
int check(int x)
{
    int sum=0,p=5;
    while(x/p)
    {
        sum+=x/p;
        p*=5;

    }
    return sum;
}
int identify(int a)
{
    int ans=-1,low=0,high=a*5,mid;
    while(low<=high)
    {



        mid = low + (high-low)/2;
        if(check(mid)>a)
            high = mid-1;
        else if(check(mid)<a)
            low = mid+1;
            else
            {
                ans=mid;
                high = mid-1;
            }

    }
    return ans;
}
int main()
{
    int i,j,test,q;
    scanf("%d",&test);
    for(i=1;i<=test;i++)
    {


        scanf("%d",&q);
        if(identify(q)>0)
            printf("Case %d: %d\n",i,identify(q));
            else
                printf("Case %d: impossible\n",i);
    }
    return 0;
}
