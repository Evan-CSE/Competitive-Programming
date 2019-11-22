#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int main()
{
    fastio;
    string s;
    char ans[201];
    int i,j=0,flag=0;
    vector<char>v={'A','E','I','O','Y','U','a','e','i','o','u','y'};
    vector<char>::iterator it;
    cin>>s;
    for(i=0;i<s.length();i++)
    {
        it = find(v.begin(),v.end(),s[i]);
        if(it==v.end())
        flag=1;
        if(flag)
        {
            ans[j++]='.';
            if(s[i]>='A' && s[i]<='Z')
                ans[j++]=s[i]+32;
            else
            ans[j++]=s[i];
        }
        flag=0;
    }
    ans[j]='\0';
    cout<<ans;
    return 0;
}
