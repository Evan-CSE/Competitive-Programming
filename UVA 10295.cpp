#include<bits/stdc++.h>
using namespace std;
#define     ll              long long
#define     MAX             100000
#define     FI              freopen("input.txt","r",stdin)
#define     FO              freopen("output.txt","w",stdout)
#define     fast            ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define     sc(a)           scanf("%d",&a)
#define     sc2(a,b)        scanf("%d %d",&a,&b)


int main()
{
    int no_of_words,text;
    cin>>no_of_words>>text;
    map<string,int>mp;
    for(int i=0; i<no_of_words; i++)
    {
        int n;
        string s;
        cin>>s>>n;
        mp[s]=n;
    }
    while(text--)
    {
        int salary = 0;
        string s;
        char ch;
        while(scanf("%c",&ch)==1)
        {
            if(ch=='.')
                break;
            if(!isalpha(ch))
            {
                if(s.size()!=0 && mp.find(s)!=mp.end())
                    salary+=mp[s];
                    s="";
                    continue;
            }
            else if(isalpha(ch))
                s+=ch;
        }
        cout<<salary<<"\n";
    }
    return 0;
}

