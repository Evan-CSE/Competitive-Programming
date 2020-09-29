#include<bits/stdc++.h>
using namespace std;
double x,y,c;
double sqt(double w)
{
   // double a,b;
   double a = 1/sqrtl((x*x)-(w*w));
    double b = 1/sqrtl((y*y)-(w*w));
   double sq = a+b;
    return sq;
}

double Find(double l,double r)
{
    double mid,ans;
    while(r-l>0.0000001)
    {
        mid = l + (r-l)/2.0;
        if(sqt(mid)>(1/c))
        {
            //cout<<"ans "<<ans<<endl;
            r = mid;
        }
        else
            l = mid;
    }
    return mid;
}
int main()
{
    int test;
    scanf("%d",&test);
    for(int i=1;i<=test;i++)
    {

        scanf("%lf %lf %lf",&x,&y,&c);
        double mn,mx;
        mn = 0.0;
        mx = min(x,y);
        printf("Case %d: %lf\n",i,Find(mn,mx));
    }
    return 0;
}
