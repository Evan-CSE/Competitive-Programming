#include<iostream>
#include<cmath>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int main()
{
    //fastio;
    double ab,ac,bc,rat;
    int t;
    cin>>t;
    for(int i = 1; i<=t; i++)
    {
        scanf("%lf %lf %lf %lf",&ab,&ac,&bc,&rat);
        //cout<<"Case "<<i<<": "<< <<endl;
        rat = (1/sqrtl(1+1/rat))*ab;
        printf("Case %d: %lf\n",i,rat);

    }
    return 0;
}

