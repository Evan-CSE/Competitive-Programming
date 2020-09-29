#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);;cin.tie(NULL);cout.tie(NULL);
using namespace std;
int a[30],cnt=0;
int main()
{
    fastio;
    set<char>s;
    char ch;
    cin>>ch;
    while(ch!='}')
    {
        cin>>ch;
        if(isalpha(ch))
        if(isupper(ch))
            a[ch-'A']++;
        else
            a[ch-'a']++;
    }
    for(int i=0;i<30;i++)
        if(a[i]>0)
        cnt++;
    cout<<cnt<<endl;
    return 0;
}
