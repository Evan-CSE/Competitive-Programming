#include<bits/stdc++.h>
using namespace std;
int container,sz,vessel[1000];
bool valid(int to_be_checked);
int Find(int low, int high) /**Here we'll find perfect container */
{
    int l=low,r=high,mid,ans;
    while(l<=r)
    {
        mid = l + (r-l)/2;
        if(valid(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    return ans;
}
bool valid(int to_be_checked) /**Here we'll check if we can take the assuming container or not */
{
    int i,contain=to_be_checked,tmp_contain=0,c=1;
    for(i=0;i<sz;i++)
    {
        tmp_contain+=vessel[i]; /**Temporary filling container */
        if(tmp_contain>contain)
        {
            c++;     /**if tmp_container exceed our capacity then another container will be needed. So here we're counting number container we need*/
            tmp_contain = vessel[i]; /**As we have selected new container so our counting begins from the last vessel milk which we couldn't pour in the previous one*/
        }
    }
    if(c>container) /**If our counted container exceeds maximum number of container told by user then it'll return false ie we can't use this container */
        return false;
    else
        return true;
}
int main()
{
    int i,j,test;
    scanf("%d",&test);
    for(i=1;i<=test;i++)
    {
        int mx=0,total=0;
        scanf("%d %d",&sz,&container);
        for(j=0;j<sz;j++)
        {
             scanf("%d",&vessel[j]);
             total+=vessel[j];
             mx = max(mx,vessel[j]);
        }

        printf("Case %d: %d\n",i,Find(mx,total));
    }
    return 0;
}
/**Evan*/
