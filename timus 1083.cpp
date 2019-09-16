/**Bismilla-hir rahma-nir rahi-m */
/**Evan_CSE */

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,r,ans,tmp,j=1;
    string s;
    cin>>n>>s;
    k=s.length();
    ans=n;
    r=n%k;
    tmp = n - (j*k);
    j++;
    if(r!=0)
    {
        while(tmp>=r)
        {
            ans = ans * tmp;
            tmp = n - (j*k);
            j++;
        }
    }
    else if(r==0 && tmp>0)
    {
        while(tmp>=k)
        {
            ans = ans *tmp;
            tmp = n - (j*k);
            j++;
        }
    }
        cout<<ans;
    return 0;
}
